#include "Person.h"
#include "Control.h"
static int state = 0;
static int state1 = 0;
static int state2 = 0;
static int state3 = 0;
extern Control* now;
void Person::draw()
{
	if (state < 60)
	{
		char* s = new char[500];
		sprintf(s, "./Pic/Move/%d.png", state / cnt + 1);
		now->putImage(s, x, y, Psize, Psize);
		state++;
		if (state == cnt * 6)state = 0;
		delete[] s;
	}
	if (state == 60)
	{
		char* s = new char[500];
		sprintf(s, "./Pic/Left/%d.png", state1 / cnt + 1);
		now->putImage(s, x, y, Psize, Psize);
		state1++;
		if (state1 == cnt * 6)state = 0, state1 = 0, now->is_NoAarrow = true;
		delete[] s;
	}
	if (state == 120)
	{
		char* s = new char[500];
		sprintf(s, "./Pic/Down/%d.png", state2 / cnt + 1);
		now->putImage(s, x, y, Psize, Psize);
		state2++;
		if (state2 == cnt * 6)state = 0, state2 = 0, now->is_NoWarrow = true;
		delete[] s;
	}
	if (state == 180)
	{
		char* s = new char[500];
		sprintf(s, "./Pic/Right/%d.png", state3 / cnt + 1);
		now->putImage(s, x, y, Psize, Psize);
		state3++;
		if (state3 == cnt * 6)state = 0, state3 = 0, now->is_NoDarrow = true;
		delete[] s;
	}
}
void Person::OnAarrow()
{
	state = 60;
	now->is_NoAarrow = false;
}
void Person::OnWarrow()
{
	state = 120;
	now->is_NoWarrow = false;
}
void Person::OnDarrow()
{
	state = 180;
	now->is_NoDarrow = false;
}