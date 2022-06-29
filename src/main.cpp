#include"Control.h"
#include<SDL2/SDL.h>
Control* now = nullptr;
int main(int argc, char* argv[]) {
	now = new Control(960, 640);
	now->mainLoop();
	delete now;
	return 0;
}