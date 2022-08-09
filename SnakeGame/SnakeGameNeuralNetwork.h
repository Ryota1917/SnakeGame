#pragma once
#include<unordered_map>
#include<set>
#include <functional>

class SnakeGameNeuralNetwork {
public:
	SnakeGameNeuralNetwork(class StageActor* stage);
	~SnakeGameNeuralNetwork();

	void StateUpdate();
	void AddState(class NNState* state, std::function<int()> inputFunction = nullptr);

private:

	std::multiset<class NNState*, std::function<bool(const NNState*, const NNState*)>> mNNStatesLayerOrder;
	std::unordered_map<int, NNState*> mNNState;
	std::unordered_map<int, std::function<int()>> mInputLayerUpdate;
	class StageActor* mStage;
	int mLayerNum;
};