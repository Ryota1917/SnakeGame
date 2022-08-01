#pragma once
#include"Actor.h"
#include<random>

class FruitActor : public Actor {
public:
	FruitActor(Game* game);
	FruitActor(Game* game,int _x,int _y);



	int GetX()const { return mPoint.x; }
	int GetY()const { return mPoint.y; }
	const Vector2Int GetPoint()const {return mPoint; }
	void SetPosition(const int x, const int y) { mPoint.x = x; mPoint.y = y; }
	void ChangePosRandom();

private:
	Vector2Int mPoint;
	std::mt19937 mRnd;
};