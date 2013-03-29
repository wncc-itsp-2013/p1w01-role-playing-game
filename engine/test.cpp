#include "initialize.cpp"
#include "windows.cpp"

int main(){
	sdlInit('a');

	window screen1(600,400);
	screen1.draw("image.bmp",20,10);
sleep(2);


	SDL_Quit();
	return 0;
}
