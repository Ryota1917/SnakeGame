#include"Game.h"
#include"Actor.h"
#include"StageActor.h"
#include"FruitActor.h"
#include"KeyControllSnakeActor.h"
#include"RandomSnake.h"
#include"SimpleAISnake.h"

void Game::LoadData() {
	auto stage = new StageActor(this);
	auto fruit = new FruitActor(this);
	//auto snake = new KeyControllSnakeActor(this);
	auto snake2 = new SimpleAISnake(this,fruit);
	//stage->AddSnake(snake);
	stage->SetFruitActor(fruit);
	stage->AddSnake(snake2);
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