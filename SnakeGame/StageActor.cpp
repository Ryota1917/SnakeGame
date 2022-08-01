#include"StageActor.h"
#include"StageDrawer.h"
#include"SnakeActor.h"
#include"FruitActor.h"
#include"Parameter.hpp"

StageActor::StageActor(Game* game):
	Actor(game),mTurnSpace(Parameter::TurnSpace),mTotalTurn(0)
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
				if (IsSnakeEat(snake, mFruit)) {
					SnakeEat(snake, mFruit);
					snake->EatMove();
				}
				else {
					snake->Move();
				}
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

bool StageActor::IsSnakeEat(SnakeActor* snake, FruitActor* fruit)
{
	return snake->GetSnakeFront() == fruit->GetPoint();
}

void StageActor::SnakeEat(SnakeActor* snake, FruitActor* fruit)
{
	fruit->ChangePosRandom();
}
