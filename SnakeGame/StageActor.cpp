#include"StageActor.h"
#include"StageDrawer.h"

StageActor::StageActor(Game* game):
	Actor(game)
{
	new StageDrawer(this, 100);
}
