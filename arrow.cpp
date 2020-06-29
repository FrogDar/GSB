#include"arrow.h"
extern Control* now;
arrow::arrow(int x, int code) {
	this->x = x;
	this->code = code;
}
arrow::arrow(int x, int y, int code) {
	this->x = x;
	this->y = y;
	this->code = code;
}
int ArrowLine::getInput(int code) {
	if (0 == darrow.size()) {
		return -10;//没开始
	}
	//队列从上到下-> 队尾->队头
	//auto itr = darrow.rbegin(); itr != darrow.rend()标准倒序遍历
	for (auto itr = darrow.rbegin(); itr != darrow.rend() && false == ((*itr)->flag); itr++) {
		//循环直到找到没有判断(false == ((*itr)->flag))的箭头
		int distance = abs((*itr)->y - staY);//
		if (distance <= 25 && false == (*itr)->flag) {//距离0到25为perfect
			(*itr)->flag = true;//
			delete* itr;
			//删除迭指向的指针
			darrow.pop_back();
			//后删除尾元素(空)
			//内存意识,向蛙哥学习
			level = 1;
			count++;
			//count代表启动显示模块
			return 100;//循环一次,找到了就返回退出
		}
		else if (distance > 25 && distance < 50 && (false == (*itr)->flag)) {//距离25到50是great
			(*itr)->flag = true;
			delete* itr;
			darrow.pop_back();
			level = 2;
			count++;
			return 60;//循环一次,找到了就返回退出
		}
		else if ((false == (*itr)->flag)) {//距离40以上为miss
			(*itr)->flag = true;
			delete* itr;
			darrow.pop_back();
			level = 3;
			count++;
			return -60;//循环一次,找到了就返回退出
		}
		return 0;
	}
	return 0;//没开始不循环
}

ArrowLine::ArrowLine(int x, int staCode_) :lineX{ x }, staCode{ staCode_ }{
	//优雅的写法记住
};
void ArrowLine::drawStaticArrow() {
	int y = this->staY;
	int code = this->staCode;
	char* fileName = new char[50];
	if (0 == code) {
		sprintf(fileName, "./Pic/AQuiver.png");//左
		now->putImage(fileName, lineX, y, 100, 100);
	}
	else if (1 == code) {
		sprintf(fileName, "./Pic/DQuiver.png");//右
		now->putImage(fileName, lineX, y, 100, 100);
	}
	else if (2 == code) {
		sprintf(fileName, "./Pic/SQuiver.png");//上
		now->putImage(fileName, lineX, y, 100, 100);
	}
	else {
		// tishi
	}
	delete[] fileName;
}
void arrow::drawArrow() {//左0右1
	if (0 == code) {
		char* fileName = new char[50];
		y = y - dy;
		sprintf(fileName, "./Pic/AKey.png");//左
		now->putImage(fileName, x, y, 100, 100);
		delete[] fileName;
	}
	else if (1 == code) {
		char* fileName = new char[50];
		y = y - dy;
		sprintf(fileName, "./Pic/DKey.png");//右
		now->putImage(fileName, x, y, 100, 100);
		delete[] fileName;
	}
	else if (2 == code) {
		char* fileName = new char[50];
		y = y - dy;
		sprintf(fileName, "./Pic/SKey.png");//上
		now->putImage(fileName, x, y, 100, 100);
		delete[] fileName;
	}
}
void ArrowLine::lineClear() {//清洗函数
	darrow.clear();
}
//左0右1上2
void ArrowLine::add() {
	//左0右1上2
	darrow.push_front(new arrow(lineX, staCode));
	//?
}
int ArrowLine::drawLine() {
	drawStaticArrow();
	for (auto every : darrow) {
		every->drawArrow();
	}
	if (1 == level) {//perfect
		now->putImage("./Pic/perfect.png", lineX, 120, 100, 100);
		count++;
	}
	//显示三个帧率//妙
	else if (2 == level) {//great
		now->putImage("./Pic/great.png", lineX, 120, 100, 100);
		count++;
	}
	else if (3 == level) {//miss
		now->putImage("./Pic/miss.png", lineX, 120, 100, 100);
		count++;
	}
	if (50 == count) {
		count = 0;
		level = 0;
	}
	int sum = 0;
	while (darrow.size() && (darrow.back()->y) < -20) {
		level = 3;
		delete darrow.back();
		darrow.pop_back();
		sum -= 60;
		//总分
	}
	return sum;
}