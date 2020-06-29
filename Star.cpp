#include "Star.h"
#include "Control.h"
#include <cmath>
#include <cstdio>
extern Control* now;

Star::Star() {
	randStar();
}
void Star::randStar() {//随机生成星星坐标
	this->x = ((now->rand()) % (960 - starP - 50)) + 25;
	this->y = ((now->rand()) % (640 - starP - 50)) + 25;
	this->time = ((now->rand()) % 170) + 30;//随机time数值，在30~200之间
}

int Star::levelJudge(int a, int b) {//判断点击等级
	if (judge) {
		int distance = (int)sqrt((a - (this->x + starP / 2)) * (a - (this->x + starP / 2)) + (b - (this->y + starP / 2)) * (b - (this->y + starP / 2)));
		//	printf("p:%d %d star:%d %d d:%d\n",a,b,this->x + starP / 2,this->y + starP / 2,distance);
		if (distance <= (int)(starP / 3)) {
			level = 1;//perfect等级
			count = 0;//重置计数
			judge = false;//关闭等级判断
			return 100;
		}
		else if (distance > (int)(starP / 3) && distance < starP / 2) {
			level = 2;//great等级
			count = 0;
			judge = false;
			return 50;
		}
		else {
			level = 3;//miss等级
			count = 0;
			judge = false;
			return -20;
		}
	}
	return 0;
}

int Star::drawStar() {//绘制星星
	if (count < time) {//计数后显示星星
		count++;
	}
	if (count >= time && count < time + 150) {//计数到100，显示星星
		now->putImage("./Pic/Star.png", this->x, this->y, starP, starP);
		count++;
		judge = true;
	}
	if (count == time + 150) {//一直没点击，计数到1000后直接miss
		now->putImage("./Pic/miss.png", this->x, this->y, starP, starP);
		count = 0;
		judge = false;
		level = 3;
	}
	if (level != 0)countLevel++;
	if (1 == level) {//perfect
		now->putImage("./Pic/perfect.png", this->x, this->y, starP, starP);
	}
	else if (2 == level) {//great
		now->putImage("./Pic/great.png", this->x, this->y, starP, starP);
	}
	else if (3 == level) {//miss
		now->putImage("./Pic/miss.png", this->x, this->y, starP, starP);
	}
	if (countLevel == 60) {//重置等级显示计数
		return 1;
	}
	return 0;
}

int Star::getScore()
{
	switch (level) {
	case 1:return 123;
	case 2:return 66;
	case 3:return -99;
	default:return 0;
	}
}