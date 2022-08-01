#include "KeyControllSnakeActor.h"

KeyControllSnakeActor::KeyControllSnakeActor(Game* game):
	SnakeActor(game)
{
}

void KeyControllSnakeActor::ProcessKeybord(const Uint8* keyState)
{
	if (keyState[SDL_SCANCODE_UP]) {
		SetDirection(Direction::UP);
	}
	else if (keyState[SDL_SCANCODE_DOWN]) {
		SetDirection(Direction::DOWN);
	}
	else if (keyState[SDL_SCANCODE_LEFT]) {
		SetDirection(Direction::LEFT);
	}
	else if (keyState[SDL_SCANCODE_RIGHT]) {
		SetDirection(Direction::RIGHT);
	}
}
