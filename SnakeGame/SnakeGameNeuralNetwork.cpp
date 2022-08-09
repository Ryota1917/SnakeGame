#include "SnakeGameNeuralNetwork.h"
#include"NNState.h"
#include"StageActor.h"

SnakeGameNeuralNetwork::SnakeGameNeuralNetwork(class StageActor* stage):
	mNNStatesLayerOrder([](const NNState* l, const NNState* r) {return l->GetLayer() < r->GetLayer(); }),
	mStage(stage)
{}

SnakeGameNeuralNetwork::~SnakeGameNeuralNetwork()
{
	for (auto iter = mNNState.begin(); iter != mNNState.end();) {
		delete (*iter).second;
		iter = mNNState.erase(iter);
	}
}

void SnakeGameNeuralNetwork::StateUpdate()
{
	for (auto state : mNNStatesLayerOrder) {
		// input layer
		if (state->GetLayer() == 0) {
			state->SetScore(mInputLayerUpdate[state->GetID()]());
		}

		// another layer
		else {
			state->UpdateScore();
		}
	}
}

void SnakeGameNeuralNetwork::AddState(NNState* state, std::function<int()> inputFunction = nullptr)
{
	if (state->GetID() == 0 && inputFunction == nullptr) {
		SDL_Log("error: NNStateが正しく初期化できません．\ninput layerのinput functionが正しく注入されているか確認してください．");
	}
	mNNStatesLayerOrder.insert(state);
	mNNState[state->GetID()] = state;
	mInputLayerUpdate[state->GetID()] = inputFunction;
}
