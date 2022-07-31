#include"Component.h"
#include"Actor.h"

Component::Component(Actor* owner) :mOwner(owner) {
	mOwner->AddComponent(this);
}

Component::~Component()
{
	mOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime)
{
}
