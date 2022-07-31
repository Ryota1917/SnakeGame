#pragma once
#include"Actor.h"

class FruitActor : public Actor {
public:
	FruitActor(Game* game,int _x,int _y);
	int GetX()const { return mx; }
	int GetY()const { return my; }
	void SetPosition(const int x, const int y) { mx = x; my = y; }

private:
	int mx;
	int my;
};