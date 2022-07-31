#include"SnakeActor.h"
#include"SnakeDrawer.h"

SnakeActor::SnakeActor(Game* game):
	Actor(game)
{
	new SnakeDrawer(this, 300);
	mSnake.push_back(Vector2Int(1, 2));
	mSnake.push_back(Vector2Int(1, 3));
	mSnake.push_back(Vector2Int(1, 4));
}