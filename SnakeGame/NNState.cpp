#include "NNState.h"

NNState::NNState(int _id, int _layer):
	mStateID(_id),layer(_layer),score(0)
{
}

void NNState::UpdateScore()
{
	score = 0;
	for (auto state : edges) {
		score += state.first->GetScore() * state.second;
	}
}
