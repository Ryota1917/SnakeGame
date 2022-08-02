#pragma once
#include"SnakeActor.h"

class SimpleAISnake :public SnakeActor {
public:
	SimpleAISnake(Game* game, class FruitActor* fruit);

	void UpdateActor(float deltaTime)override;

private:
	FruitActor* mFruit;
};