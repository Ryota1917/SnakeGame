#include"FruitActor.h"
#include"FruitDrawer.h"
#include"Parameter.hpp"


FruitActor::FruitActor(Game* game):
	Actor(game),mRnd(Parameter::FruitSeed)
{
	auto drawer = new FruitDrawer(this, 200);
	mPoint.x = mRnd() % Parameter::StageWidth;
	mPoint.y = mRnd() % Parameter::StageHeight;
}

FruitActor::FruitActor(Game* game, int _x, int _y):
	Actor(game), mPoint(_x,_y),mRnd(Parameter::FruitSeed)
{
	auto drawer = new FruitDrawer(this, 200);
}

void FruitActor::ChangePosRandom()
{
	mPoint.x = mRnd() % Parameter::StageWidth;
	mPoint.y = mRnd() % Parameter::StageHeight;
}

 