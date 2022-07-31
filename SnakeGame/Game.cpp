#include"SDL_image.h"
#include"Game.h"
#include"Actor.h"
#include"Drawer.h"
#include<vector>
#include <SDL_image.h>

Game::Game()
	:mWindow(nullptr)
	, mRenderer(nullptr)
	, mIsRunning(true)
	, mTickCount(0)
	, mDrawers([](const Drawer* l, const Drawer* r) {return l->GetOrder() < r->GetOrder(); })
{

}

bool Game::Initialize() {
	// SDL������
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// SDL Window�쐬
	mWindow = SDL_CreateWindow(
		"SnakeGame!", // Window title
		128,	// Top left x-coordinate of window
		128,	// Top left y-coordinate of window
		1024,	// Width of window
		768,	// Height of window
		0		// Flags (0 for no flags set)
	);

	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	// SDL renderer�쐬
	mRenderer = SDL_CreateRenderer(
		mWindow, // Window to create renderer for
		-1,		 // Usually -1
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	//SDL_IMG ������
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
		return false;
	}

	LoadData();

	mTickCount = SDL_GetTicks();
	return true;
}

void Game::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::Shutdown()
{
	UnloadData();
	IMG_Quit();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			// If we get an SDL_QUIT event, end loop
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}

	// Get state of keyboard
	const Uint8* state = SDL_GetKeyboardState(NULL);
	// If escape is pressed, also end loop
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}
	if (state[SDL_SCANCODE_SPACE]) {
		for (auto actor : mActors) {
			actor->SetState(Actor::State::EPaused);
		}
	}
	if (state[SDL_SCANCODE_S]) {
		for (auto actor : mActors) {
			actor->SetState(Actor::State::EActive);
		}
	}

	for (auto actor : mActors) {
		actor->ProcessKeybord(state);
	}
}

void Game::UpdateGame() {
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTickCount + 16))
		;

	// Delta time is the difference in ticks from last frame
	// (converted to seconds)
	float deltaTime = (SDL_GetTicks() - mTickCount) / 1000.0f;

	// Clamp maximum delta time value
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}
	mTickCount = SDL_GetTicks();


	//Update Actors
	mIsUpdatingActors = true;
	for (auto actor : mActors) {
		actor->Update(deltaTime);
	}

	for (auto actor : mActors) {
		actor->LastUpdate(deltaTime);
	}
	mIsUpdatingActors = false;

	//�ǉ��҂��ɂ��Ă���Actor��ǉ�
	for (auto actor : mPendingActors) {
		mActors.emplace_back(actor);
	}
	mPendingActors.clear();

	//Dead��Ԃ�Actor���폜
	std::vector<Actor*> deadActors;
	for (auto actor : mActors) {
		if (actor->GetState() == Actor::EDead) {
			deadActors.emplace_back(actor);
		}
	}
	for (auto dead : deadActors) {
		delete dead;
	}
}

void Game::GenerateOutput() {
	// Set draw color
	SDL_SetRenderDrawColor(
		mRenderer,
		255,	// R
		255,	// G 
		255,	// B
		255		// A
	);

	// Clear back buffer
	SDL_RenderClear(mRenderer);

	// Actor�`��
	for (auto drawer : mDrawers) {
		if(drawer->GetActor()->GetState() == Actor::EActive)
			drawer->Draw(mRenderer);
	}

	// Swap front buffer and back buffer
	SDL_RenderPresent(mRenderer);
}

void Game::AddActor(Actor* actor)
{
	if (mIsUpdatingActors)
	{
		mPendingActors.emplace_back(actor);
	}
	else
	{
		mActors.emplace_back(actor);
	}
}

void Game::RemoveActor(Actor* actor) {
	// pending�̕��ɓ����Ă�����
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end()) {
		std::iter_swap(iter, mPendingActors.end() - 1);
		mPendingActors.pop_back();
	}

	//mActors�̕��ɓ����Ă�����
	iter = std::find(mActors.begin(), mActors.end(), actor);
	if (iter != mActors.end())
	{
		std::iter_swap(iter, mActors.end() - 1);
		mActors.pop_back();
	}
}

void Game::AddDrawer(Drawer* drawer) {
	mDrawers.insert(drawer);
}

void Game::RemoveDrawer(Drawer* drawer) {
	mDrawers.erase(drawer);
}

SDL_Texture* Game::GetTexture(const std::string& fileName) {
	SDL_Texture* tex = nullptr;
	auto iter = mTextures.find(fileName);
	if (iter != mTextures.end()) {
		tex = iter->second;
	}
	else {
		SDL_Surface* surf = IMG_Load(fileName.c_str());
		if (!surf) {
			SDL_Log("Failed to load texture file : %s", fileName.c_str());
			return nullptr;
		}

		tex = SDL_CreateTextureFromSurface(mRenderer, surf);
		SDL_FreeSurface(surf);
		if (!tex)
		{
			SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
			return nullptr;
		}

		mTextures.emplace(fileName.c_str(), tex);
	}
	return tex;
}