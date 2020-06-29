#pragma once

#include "Scene.h"
#include "Person.h"
#include <SDL2/SDL_keycode.h>
#include "arrow.h"
#include "SandDobstacle.h"
#include "Star.h"

class MainScene :public Scene {
private:
	Person* person;
	int BGx1 = 0, BGx2 = 960;
	ArrowLine* arrowLine[3];
	Star* star = nullptr;
	SandDobstacle* obstacleLine = nullptr;
	int Score = 0;
	int daojishi = 3 * 60 * 59;
public:
	using Scene::Scene;
	MainScene();
	~MainScene();
	void update()override;
	void onKey(SDL_Keycode key)override;
	void onMouse(Sint32 x, Sint32 y) override;
};
