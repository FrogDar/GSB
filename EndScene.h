#pragma once

#include"Scene.h"

#include<SDL2/SDL_keycode.h>

class EndScene :public Scene {
private:
	int Score;
public:
	using Scene::Scene;
	EndScene(int score_);
	~EndScene() = default;
	void update()override;
	void onKey(SDL_Keycode key)override;
	void onMouse(Sint32 x, Sint32 y) override;
};
