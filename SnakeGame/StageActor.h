#pragma once
#include"Actor.h"
#include<vector>
#include"Parameter.hpp"


class StageActor :public Actor {
public:
	enum MapType {
		NONE,
		SNAKE,
		FRUIT
	};

	StageActor(Game* game);

	void UpdateActor(float deltaTime)override;

	std::vector<class SnakeActor*> GetSnakes()const { return mSnakes; }
	void AddSnake(SnakeActor* snake);
	void RemoveSnake(SnakeActor* snake);

	class FruitActor* GetFruit()const { return mFruit; }
	void SetFruitActor(FruitActor* fruit) { mFruit = fruit; }

	const MapType GetMapType(const int h, const int w) const { return mMap[h][w]; }

	bool OutOfStage(const Vector2Int& point)const { return OutOfStage(point.x, point.y); }
	bool OutOfStage(const int x, const int y)const { return x < 0 || y < 0 || x >= Parameter::StageWidth || y >= Parameter::StageHeight; }


private:
	bool IsSnakeEat(SnakeActor* snake, FruitActor* fruit);
	void SnakeEat(SnakeActor* snake, FruitActor* fruit);
	void UpdateMapType();
	bool CanMoveSnake(SnakeActor* snake);

	MapType mMap[Parameter::StageHeight][Parameter::StageWidth];

	std::vector<class SnakeActor*>mSnakes;
	class FruitActor* mFruit;
	int mTotalTurn;
	int mTurnSpace;
};