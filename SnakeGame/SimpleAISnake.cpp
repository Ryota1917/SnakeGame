#include "SimpleAISnake.h"
#include"FruitActor.h"
#include<cmath>

SimpleAISnake::SimpleAISnake(Game* game, FruitActor* fruit):
	SnakeActor(game),mFruit(fruit)
{
}

void SimpleAISnake::UpdateActor(float deltaTime)
{
	auto frontPos = GetSnakeFront();
	auto fruitPos = mFruit->GetPoint();
	int dx = frontPos.x - fruitPos.x;
	int dy = frontPos.y - fruitPos.y;
	if (abs(dx) > abs(dy)) {
		SetDirection(dx > 0 ? Direction::LEFT : Direction::RIGHT);
	}
	else {
		SetDirection(dy > 0 ? Direction::UP : Direction::DOWN);
	}
}
