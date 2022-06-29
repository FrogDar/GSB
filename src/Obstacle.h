#pragma once
class Obstacle
{
private:
	int dx = 4;
	int shape = 0;
	int level = 0;
public:
	int x = 1280, y = 430;
	void draw();/*更新并绘制障碍*/
	Obstacle(const int shape);//传一个整数参数，1代表障碍DownObstacle.png，2代表障碍LeftObstacle.png，3代表RightObstaclepng
	int onKey(int key);
	bool getJudged();
};