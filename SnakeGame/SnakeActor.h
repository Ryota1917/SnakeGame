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
	const Vector2Int GetSnakeBack()const { return mSnake.back(); }
	void SetDirection(Direction dir) { mDir = dir; }
	bool GetIsAlive()const { return mIsAlive; }
	void SetIsAlive(const bool alive) { mIsAlive = alive; }

	Vector2Int Next();

private:
	std::deque<Vector2Int> mSnake;
	Direction mDir;
	bool mIsAlive;

protected:
	std::mt19937 mRnd;
};