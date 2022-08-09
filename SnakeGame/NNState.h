#pragma once
#include<vector>

class NNState {
public:
	NNState(int _id, int _layer);

	int GetScore()const { return score; }
	void SetScore(int s) { score = s; }
	int GetID()const { return mStateID; }
	int GetLayer()const { return layer; }

	void UpdateScore();
	void AddEdge(const std::pair<NNState*, int> e) { edges.push_back(e); }

private:
	int mStateID;
	int score;
	int layer;
	std::vector<std::pair<NNState*, int>> edges;
};