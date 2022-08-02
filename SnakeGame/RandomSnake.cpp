#include "RandomSnake.h"

RandomSnake::RandomSnake(Game* game):
	SnakeActor(game),mRnd(12345679)
{
}

void RandomSnake::UpdateActor(float deltaTime)
{
	SetDirection(static_cast<SnakeActor::Direction>(mRnd()%4));
}
