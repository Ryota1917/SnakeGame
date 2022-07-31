#pragma once
#include"SDL.h"
#include<vector>
#include<unordered_map>
#include<string>
#include<set>
#include <functional>

class Game {
public:
	Game();
	// Game logic
	bool Initialize();
	void RunLoop();
	void Shutdown();

	// Actor Controll
	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	// Drawer Conrtoll
	void AddDrawer(class Drawer* drawer);
	void RemoveDrawer(class Drawer* drawer);


	SDL_Texture* GetTexture(const std::string& fileName);

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	//�f�[�^���[�h
	void LoadData();
	void UnloadData();

	//�e�N�X�`��
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	// all Actors
	std::vector<class Actor*> mActors;
	// all pending Actors
	std::vector<class Actor*> mPendingActors;
	bool mIsUpdatingActors;

	// all Drawers
	std::set<class Drawer*, std::function<bool(const Drawer*, const Drawer*)>> mDrawers;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	unsigned mTickCount;
	bool mIsRunning;
};
