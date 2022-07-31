#pragma once
#include"Drawer.h"
#include"FruitActor.h"

class FruitDrawer : public Drawer {
public:
	FruitDrawer(FruitActor* owner, int order); 
	void Draw(SDL_Renderer* renderer)override;

private:
	FruitActor* mFruit;
};