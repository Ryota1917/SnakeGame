#include"Drawer.h"
#include"Actor.h"

Drawer::Drawer(Actor* owner,int order):
	mOwner(owner),mOrder(order)
{
	owner->AddDrawer(this);
	owner->GetGame()->AddDrawer(this);
}

Drawer::~Drawer() {
	mOwner->RemoveDrawer(this);
	mOwner->GetGame()->RemoveDrawer(this);
}

void Drawer::Draw(SDL_Renderer* renderer) {

}