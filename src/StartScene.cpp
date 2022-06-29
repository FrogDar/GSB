#include "StartScene.h"
#include "Control.h"
#include "MainScene.h"
extern Control *now;
void StartScene::update()
{
	now->putImage("./Pic/Start.png", 0, 0, 960, 640);
}

void StartScene::onKey(SDL_Keycode key)
{
	now->scene = new MainScene();
	delete this;
}

void StartScene::onMouse(Sint32 x, Sint32 y)
{
	if (90 <= x && x <= 270 && 370 <= y && y <= 470)
	{
		now->scene = new MainScene();
		delete this;
	}
}