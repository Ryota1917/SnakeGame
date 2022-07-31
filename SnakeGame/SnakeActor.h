#pragma once
#include"Actor.h"
#include<deque>

class SnakeActor :public Actor {
public:
	SnakeActor(Game* game);

	const std::deque<Vector2Int>& GetSnakeDeque()const { return mSnake; }

private:
	std::deque<Vector2Int> mSnake;
};