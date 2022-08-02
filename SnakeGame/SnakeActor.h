#pragma once
#include"Actor.h"
#include<deque>
#include<random>

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
	void EatMove();

	const std::deque<Vector2Int>& GetSnakeDeque()const { return mSnake; }
	const Vector2Int GetSnakeFront()const { return mSnake.front(); }
	void SetDirection(Direction dir) { mDir = dir; }
	Vector2Int Next();

private:
	std::deque<Vector2Int> mSnake;
	Direction mDir;
	bool IsAlive;

protected:
	std::mt19937 mRnd;
};