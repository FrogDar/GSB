#include "EndScene.h"
#include "Control.h"
extern Control* now;
EndScene::EndScene(int score_) :Score{ score_ }
{
}

void EndScene::update()
{
	now->putImage("./Pic/Last.png", 0, 0, 960, 640);
	char* t = new char[300];
	sprintf(t, "%5d", Score);
	now->xyprintf(70, 80, "Score:", 64);
	now->xyprintf(100, 150, t, 64);
	delete[] t;
}

void EndScene::onKey(SDL_Keycode key)
{
}

void EndScene::onMouse(Sint32 x, Sint32 y)
{
}