#pragma once
#include"Drawer.h"

class StageDrawer :public Drawer {
public:
	StageDrawer(Actor* owner, int order);
	void Draw(SDL_Renderer* renderer)override;

private:


};