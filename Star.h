#pragma once

class Star {
private:
	int x{ 0 }, y{ 0 };//代表星星中心的坐标
	int starP{ 100 };//星星图片的边长
	int count{ 0 };//星星显示计数
	int level{ 0 };//等级分别
	int countLevel{ 0 };//判断等级显示计数
	int time{ 0 };//星星生成时间间隔
public:
	void randStar();//随机生成星星（坐标、生成时间间隔
	int levelJudge(int a, int b);//判断点击等级,返回分数
	int drawStar();//绘制星星
	int getScore();
	bool judge = false;
	Star();
};