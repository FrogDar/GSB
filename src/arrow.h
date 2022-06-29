#pragma once
#include<iostream>
#include<cstring>
#include<deque>
#include"Control.h"
extern Control* now;
using std::cout;
using std::cin;
using std::endl;
using std::deque;
class arrow {
public:
	int x, y = 600, code;
	int dy = 4;
	bool flag = 0;
	//x横坐标 code传箭头类型
	//左0右1上3
	arrow() = default;
	arrow(int x, int code);//
	arrow(int x, int y, int code);
	void drawArrow();
};
class ArrowLine {
private:
	int level = 0;
	int count = 0;
	int staY = 50;//静址箭头Y
	int staCode;//箭头代号
	deque<arrow*> darrow;//使用队列
	int arrowY = 0;//箭头起始y
	int lineX = 40;//箭头列x
public:
	ArrowLine(int x, int staCode_);
	//返回  1 miss 2 good 3 great
	int getInput(int code);//用户输入的y   //code 左0右1上2 用户输入什么对应箭头
	void drawStaticArrow();//画静止箭头
	void lineClear();//清空列
	void add();//左0右1上3
	int drawLine();//画箭头列
};