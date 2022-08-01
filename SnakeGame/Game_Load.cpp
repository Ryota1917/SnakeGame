#include"Game.h"
#include"Actor.h"
#include"StageActor.h"
#include"FruitActor.h"
#include"KeyControllSnakeActor.h"

void Game::LoadData() {
	auto stage = new StageActor(this);
	auto fruit = new FruitActor(this, 10, 10);
	auto snake = new KeyControllSnakeActor(this);
	stage->AddSnake(snake);
	stage->SetFruitActor(fruit);
}

void Game::UnloadData() {
	while (!mActors.empty()) {
		delete mActors.back();
	}

	for (auto t : mTextures) {
		SDL_DestroyTexture(t.second);
	}
	mTextures.clear();
}