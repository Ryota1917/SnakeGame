#include"SnakeDrawer.h"
#include"SnakeActor.h"
#include"Parameter.hpp"

SnakeDrawer::SnakeDrawer(SnakeActor* owner, int order) :
	Drawer(owner, order),mSnakeActor(owner)
{}

void SnakeDrawer::Draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	for (auto pos : mSnakeActor->GetSnakeDeque()) {
		SDL_Rect r{
			(Parameter::GridSize + Parameter::GridSpace) * pos.x,
			(Parameter::GridSize + Parameter::GridSpace) * pos.y,
			Parameter::GridSize,
			Parameter::GridSize
		};
		SDL_RenderFillRect(renderer, &r);
	}
}
