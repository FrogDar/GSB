#pragma once
#include "Obstacle.h"
#include<deque>
class SandDobstacle {
private:
	int index = 0;
	int temp = 0;
public:
	std::deque<Obstacle*>obstacle;
	SandDobstacle() = default;
	void add(int i);// 传一个整数参数，1代表障碍DownObstacle.png，2代表障碍LeftObstacle.png，3代表RightObstaclepng
	void drawLine();
	int onKey(int key);
};