#pragma once
#include"Actor.h"
#include<vector>

class StageActor :public Actor {
public:
	StageActor(Game* game);

	void UpdateActor(float deltaTime)override;

	std::vector<class SnakeActor*> GetSnakes()const { return mSnakes; }
	void AddSnake(SnakeActor* snake);
	void RemoveSnake(SnakeActor* snake);

	class FruitActor* GetFruit()const { return mFruit; }
	void SetFruitActor(FruitActor* fruit) { mFruit = fruit; }


private:
	bool IsSnakeEat(SnakeActor* snake, FruitActor* fruit);
	void SnakeEat(SnakeActor* snake, FruitActor* fruit);

	std::vector<class SnakeActor*>mSnakes;
	class FruitActor* mFruit;
	int mTotalTurn;
	int mTurnSpace;
};