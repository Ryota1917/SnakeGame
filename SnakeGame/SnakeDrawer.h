#pragma once
#include"Drawer.h"

class SnakeDrawer :public Drawer {
public:
	SnakeDrawer(class SnakeActor* owner, int order);
	void Draw(SDL_Renderer* renderer)override;
private:
	class SnakeActor* mSnakeActor;
};