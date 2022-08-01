#pragma once
#include"SnakeActor.h"

class KeyControllSnakeActor :public SnakeActor {
public:
	KeyControllSnakeActor(Game* game);

	void ProcessKeybord(const Uint8* keyState)override;
};