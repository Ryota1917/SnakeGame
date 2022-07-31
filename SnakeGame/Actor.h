#pragma once
#include<vector>
#include"Math.h"
#include"Game.h"

class Actor {
public:
	enum State {
		EActive,
		EPaused,
		EDead,
	};

	Actor(class Game* game);
	virtual ~Actor();

	// Update Actor
	void Update(float deltaTime);
	// Update all Components
	void UpdateComponents(float deltaTime);
	// Actor ���L�̍X�V
	virtual void UpdateActor(float deltaTime);
	// Update->LastUpdate�̏��ԂŌĂяo�����
	void LastUpdate(float deltaTime);
	virtual void LastUpdateActor(float deltaTime);

	virtual void ProcessKeybord(const Uint8* keyState);
	
	//�`��p�̏������Ăяo��
	void Draw(SDL_Renderer* renderer);

	//Component�Ɋւ��鏈��
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	//Drawer�Ɋւ��鏈��
	void AddDrawer(class Drawer* drawer);
	void RemoveDrawer(class Drawer* drawer);

	Game* GetGame() { return mGame; }
	State GetState() { return mState; }
	void SetState(State state) { mState = state; }

	const Vector2& GetPosition()const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	const Vector2& GetScale()const { return mScale; }
	void SetScale(const Vector2& scale) { mScale = scale; }
	float GetRotate()const { return mRotate; }
	void SetRotate(float rot) { mRotate = rot; }

	Vector2 GetForward() { return Vector2(Math::Cos(mRotate), -Math::Sin(mRotate)); }

private:
	State mState;

	//Transform ���
	Vector2 mPosition;
	Vector2 mScale;
	float mRotate;

	std::vector<class Component*> mComponents;
	std::vector<class Drawer*> mDrawers;
	Game* mGame;
};