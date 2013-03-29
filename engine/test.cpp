#include "initialize.cpp"
#include "windows.cpp"
#include <iostream>

using namespace std;

int main(){
	sdlInit('a');

	window screen1(600,400);
	screen1.draw("image.bmp",20,10,0,0);
	screen1.reload();
	sleep(5);
	SDL_Quit();
	return 0;
}
