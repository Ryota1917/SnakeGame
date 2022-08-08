#include"StageActor.h"
#include"StageDrawer.h"
#include"SnakeActor.h"
#include"FruitActor.h"

StageActor::StageActor(Game* game):
	Actor(game),mTurnSpace(Parameter::TurnSpace),mTotalTurn(0),mFruit(nullptr)
{
	new StageDrawer(this, 100);
	UpdateMapType();
}

void StageActor::UpdateActor(float deltaTime)
{
	mTotalTurn++;

	if (mTotalTurn % mTurnSpace == 0) {
		// snake‚ð“®‚©‚·
		for (auto snake : mSnakes) {
			// ‚à‚¤Ž€‚ñ‚Å‚¢‚½‚ç‰½‚à‚µ‚È‚¢
			if (!snake->GetIsAlive()) {
				continue;
			}

			// “®‚¯‚é‚©‚Ç‚¤‚©
			if (CanMoveSnake(snake)) {
				if (IsSnakeEat(snake, mFruit)) {
					snake->EatMove();
					SnakeEat(snake, mFruit);
				}
				else {
					snake->Move();
				}
			}
			else {
				snake->SetIsAlive(false);
				SDL_Log("Game over..");
			}
		}

		UpdateMapType();
	}
}

void StageActor::AddSnake(SnakeActor* snake)
{
	mSnakes.emplace_back(snake);
	for (auto s : snake->GetSnakeDeque()) {
		mMap[s.y][s.x] = MapType::SNAKE;
	}
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
	return snake->Next() == fruit->GetPoint();
}

void StageActor::SnakeEat(SnakeActor* snake, FruitActor* fruit)
{
	fruit->ChangePosRandom();
}

void StageActor::UpdateMapType()
{
	// Initialize
	for (int h = 0; h < Parameter::StageHeight; h++) {
		for (int w = 0; w < Parameter::StageWidth; w++) {
			mMap[h][w] = MapType::NONE;
		}
	}

	// Update
	if(mFruit)
		mMap[mFruit->GetPoint().y][mFruit->GetPoint().x] = MapType::FRUIT;
	for (auto snake : mSnakes) {
		for (auto sp : snake->GetSnakeDeque()) {
			mMap[sp.y][sp.x] = MapType::SNAKE;
		}
	}

}

bool StageActor::CanMoveSnake(SnakeActor* snake)
{
	Vector2Int nextPos = snake->Next();
	if (OutOfStage(nextPos)) {
		return false;
	}
	if (mMap[nextPos.y][nextPos.x] == MapType::SNAKE) {
		return false;
	}

	return true;
}
