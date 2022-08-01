#pragma once
#include"Actor.h"
#include<deque>

class SnakeActor :public Actor {
public:
	enum Direction {
		UP,
		DOWN,
		RIGHT,
		LEFT
	};

	SnakeActor(Game* game);

	bool CanMove();
	void Move();

	const std::deque<Vector2Int>& GetSnakeDeque()const { return mSnake; }

private:
	Vector2Int Next();

	std::deque<Vector2Int> mSnake;
	Direction mDir;
	bool IsAlive;
};