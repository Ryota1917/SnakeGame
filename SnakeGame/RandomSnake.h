#pragma once
#include"SnakeActor.h"
#include<random>

class RandomSnake : public SnakeActor {
public:
	RandomSnake(Game* game);

	void UpdateActor(float deltaTime)override;

private:
	std::mt19937 mRnd;
};