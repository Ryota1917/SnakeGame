#include"StageDrawer.h"
#include"Parameter.hpp"

StageDrawer::StageDrawer(Actor* owner, int order):
	Drawer(owner,order)
{}

void StageDrawer::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	for (int h = 0; h < Parameter::StageHeight; h++) {
		for (int w = 0; w < Parameter::StageWidth; w++) {
			SDL_Rect r{
				(Parameter::GridSize + Parameter::GridSpace) * h,
				(Parameter::GridSize + Parameter::GridSpace) * w,
				Parameter::GridSize,
				Parameter::GridSize
			};
			SDL_RenderFillRect(renderer, &r);
		}
	}
}

