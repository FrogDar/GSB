#include "MainScene.h"
#include "Control.h"
#include <iostream>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "EndScene.h"

extern Control* now;

MainScene::MainScene() {
	char* t = new char[300];
	sprintf(t, "./Music/%d.wav", now->rand() % 1 + 1);
	now->playSound(t);
	delete[] t;

	person = new Person();

	arrowLine[0] = new ArrowLine(200, 0);
	arrowLine[1] = new ArrowLine(620, 1);
	arrowLine[2] = new ArrowLine(410, 2);

	star = new Star();
	obstacleLine = new SandDobstacle();
}

MainScene::~MainScene() {
	delete person;
	for (int i = 0; i < 3; i++)
		delete arrowLine[i];
	delete star;
	delete obstacleLine;
}
void MainScene::update() {
	static int time = 1;

	now->putImage("./Pic/Background_1.png", BGx1, 0, 960, 640);
	now->putImage("./Pic/Background_2.png", BGx2, 0, 960, 640);
	BGx1 -= 3; BGx2 -= 3;
	if (BGx1 == -960)BGx1 = 960;
	if (BGx2 == -960)BGx2 = 960;
	if (daojishi > 60 * 10) {
		time++;
		if (time == 50) {
			int t = now->rand() % 3;
			arrowLine[t]->add();
			obstacleLine->add(t);
			time = now->rand() % 30 - now->rand() % 30;
		}
	}
	for (int i = 0; i < 3; i++)
		Score += arrowLine[i]->drawLine();
	obstacleLine->drawLine();
	if (star != nullptr && star->drawStar()) {
		Score += star->getScore();
		delete star;
		star = nullptr;
		if (daojishi > 60 * 10) {
			star = new Star();
		}
	}
	person->draw();

	char* s = new char[500];
	sprintf(s, "Score:%5d", this->Score);
	now->xyprintf(20, 580, s, 40);
	delete[] s;

	daojishi--;
	if (daojishi == 0) {
		now->scene = new EndScene(Score);
		delete this;
	}
}

void MainScene::onKey(SDL_Keycode key) {
	switch (key)
	{
	case SDLK_a:

		Score += arrowLine[0]->getInput(0);
		if (obstacleLine->onKey(0) > 0) {
			person->OnAarrow();
			now->playSound("./Sound/Move.wav");
		}
		break;
	case SDLK_w:

		Score += arrowLine[2]->getInput(2);
		if (obstacleLine->onKey(2) > 0) {
			person->OnWarrow();
			now->playSound("./Sound/Move.wav");
		}
		break;
	case SDLK_d:

		Score += arrowLine[1]->getInput(1);
		if (obstacleLine->onKey(1) > 0) {
			person->OnDarrow();
			now->playSound("./Sound/Move.wav");
		}
		break;
	default:
		break;
	}
}

void MainScene::onMouse(Sint32 x, Sint32 y) {
	if (star->levelJudge(x, y) > 0)
		now->playSound("./Sound/Key.wav");
}