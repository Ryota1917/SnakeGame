#pragma once
#include"SDL.h"

class Drawer {
public:
	Drawer(class Actor* owner, int order = 100);
	virtual ~Drawer();

	virtual void Draw(SDL_Renderer* renderer);

	const int GetOrder()const{ return mOrder; }
	int SetOrder(int order) { mOrder = order; }

	Actor* GetActor() { return mOwner; }

protected:
	class Actor* mOwner;
	int mOrder;
};