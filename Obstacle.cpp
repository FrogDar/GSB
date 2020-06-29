#include "Obstacle.h"
#include "Control.h"
#include <cstdio>
extern Control* now;
void Obstacle::draw()
{
	char* t = new char[500];
	switch (this->shape)
	{
	case 0:
		sprintf(t, "./Pic/LeftObstacle.png");
		break;
	case 1:
		sprintf(t, "./Pic/RightObstacle.png");
		break;
	case 2:
		sprintf(t, "./Pic/DownObstacle.png");
		break;
	case 5:
		sprintf(t, "./Pic/miss.png");
		break;
	}
	now->putImage(t, x, y, 100, 100);

	if (level) {
		switch (this->level)
		{
		case 3:
			sprintf(t, "./Pic/perfect.png");
			break;
		case 4:
			sprintf(t, "./Pic/great.png");
			break;
		case 5:
			sprintf(t, "./Pic/miss.png");
			break;
		}
		now->putImage(t, 100, 500, 100, 100);
	}
	delete[] t;

	x -= dx;
}
Obstacle::Obstacle(int shape)
{
	this->shape = shape;
}
int Obstacle::onKey(int key)
{
	if (key == shape)
	{
		if (x <= 300 && x >= 130)
		{
			level = 3;
			return 99;
		}
		else if (x > 300 && x <= 400)
		{
			level = 4;
			return 57;
		}
		else
		{
			level = 5;
			shape = 5;
			return -60;
		}
	}
	else
	{
		level = 5;
		shape = 5;
		return -60;
	}
	return 0;
}
bool Obstacle::getJudged() {
	return level;
}