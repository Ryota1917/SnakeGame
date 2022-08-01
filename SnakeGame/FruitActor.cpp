#include"FruitActor.h"
#include"FruitDrawer.h"
#include"Parameter.hpp"


FruitActor::FruitActor(Game* game):
	Actor(game),mRnd(Parameter::FruitSeed)
{
	auto drawer = new FruitDrawer(this, 200);
	mx = mRnd() % Parameter::StageWidth;
	my = mRnd() % Parameter::StageHeight;
}

FruitActor::FruitActor(Game* game, int _x, int _y):
	Actor(game),mx(_x),my(_y),mRnd(Parameter::FruitSeed)
{
	auto drawer = new FruitDrawer(this, 200);
}

void FruitActor::ChangePosRandom()
{
	mx = mRnd() % Parameter::StageWidth;
	my = mRnd() % Parameter::StageHeight;
}

 