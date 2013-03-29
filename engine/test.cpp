#include "initialize.cpp"
#include "windows.cpp"
#include <iostream>

using namespace std;

int main(){
	sdlInit('a');

	window screen1(600,400);
	screen1.draw("image.bmp",20,10,0,0);
	screen1.reload();
	sleep(2);
	cout<<"Closing the window"<<endl;
	screen1.close();
	cout<<"window closed"<<endl;
	sleep(2);
	cout<<"waited for 2 sec"<<endl;
	


	SDL_Quit();
	return 0;
}
