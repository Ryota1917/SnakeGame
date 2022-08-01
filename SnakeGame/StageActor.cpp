#include"StageActor.h"
#include"StageDrawer.h"
#include"SnakeActor.h"
#include"FruitActor.h"
#include"Parameter.hpp"

StageActor::StageActor(Game* game):
	Actor(game),mTurnSpace(30),mTotalTurn(0)
{
	new StageDrawer(this, 100);

}

void StageActor::UpdateActor(float deltaTime)
{
	mTotalTurn++;
	if (mTotalTurn % mTurnSpace == 0) {
		// snake‚ð“®‚©‚·
		for (auto snake : mSnakes) {
			if (snake->CanMove()) {
				snake->Move();
			}
			else {

			}
		}


	}
}

void StageActor::AddSnake(SnakeActor* snake)
{
	mSnakes.emplace_back(snake);
}

void StageActor::RemoveSnake(SnakeActor* snake)
{
	auto iter = std::find(mSnakes.begin(), mSnakes.end(), snake);
	if (iter != mSnakes.end()) {
		std::iter_swap(iter, mSnakes.end() - 1);
		mSnakes.pop_back();
	}
}
