#pragma once
class Person {
private:
	int x = 100, y = 430;
	int dx = 0, dy = 0;
	int Psize = 80;
	int cnt = 5;
public:
	void draw();
	void OnAarrow();
	void OnWarrow();
	void OnDarrow();
};