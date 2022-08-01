#include"SnakeActor.h"
#include"SnakeDrawer.h"
#include"Parameter.hpp"
#include<algorithm>

SnakeActor::SnakeActor(Game* game) :
	Actor(game), mDir(Direction::RIGHT), IsAlive(true)
{
	new SnakeDrawer(this, 300);
	mSnake.push_back(Vector2Int(1, 2));
	mSnake.push_back(Vector2Int(1, 3));
	mSnake.push_back(Vector2Int(1, 4));
}


bool SnakeActor::CanMove()
{
	Vector2Int nextPos = Next();
	if (std::min(nextPos.x, nextPos.y) >= 0 && nextPos.x < Parameter::StageWidth && nextPos.y < Parameter::StageHeight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SnakeActor::Move()
{
	if (CanMove()) {
		mSnake.pop_back();
		mSnake.push_front(Next());
	}
}

void SnakeActor::EatMove()
{
	if (CanMove()) {
		mSnake.push_front(Next());
	}
}

Vector2Int SnakeActor::Next()
{
	Vector2Int front = mSnake.front();
	switch (mDir)
	{
	case Direction::UP: {
		return Vector2Int(front.x, front.y - 1);
	}
	case Direction::DOWN: {
		return Vector2Int(front.x, front.y + 1);
	}
	case Direction::RIGHT: {
		return Vector2Int(front.x + 1, front.y);
	}
	case Direction::LEFT: {
		return Vector2Int(front.x - 1, front.y);
	}
	}
}
