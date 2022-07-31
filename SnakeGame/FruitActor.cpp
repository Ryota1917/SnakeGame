#include"FruitActor.h"
#include"FruitDrawer.h"

FruitActor::FruitActor(Game* game, int _x, int _y):
	Actor(game),mx(_x),my(_y)
{
	auto drawer = new FruitDrawer(this, 200);
}

 