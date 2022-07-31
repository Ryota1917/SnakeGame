#include"FruitDrawer.h"
#include"Parameter.hpp"

FruitDrawer::FruitDrawer(FruitActor* owner, int order):
	Drawer(owner,order),mFruit(owner)
{}

void FruitDrawer::Draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect r{
		(Parameter::GridSize + Parameter::GridSpace) * mFruit->GetX(),
		(Parameter::GridSize + Parameter::GridSpace) * mFruit->GetY(),
		Parameter::GridSize,
		Parameter::GridSize
	};
	SDL_RenderFillRect(renderer, &r);
}
