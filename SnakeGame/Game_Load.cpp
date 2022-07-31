#include"Game.h"
#include"Actor.h"
#include"StageActor.h"
#include"FruitActor.h"

void Game::LoadData() {
	new StageActor(this);
	new FruitActor(this, 10, 10);
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