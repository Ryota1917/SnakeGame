#pragma once
#include"SnakeActor.h"

class NNSnake :public SnakeActor {
public:
	NNSnake(Game* game);
	void UpdateActor(float deltaTime)override;
private:
	class StageActor* mStage;
};