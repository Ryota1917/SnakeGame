#pragma once
#include"SnakeActor.h"

class NNSnake :public SnakeActor {
public:
	NNSnake(Game* game,class StageActor* stage);
	void UpdateActor(float deltaTime)override;
private:
	class StageActor* mStage;

	struct NNState {

	};
};