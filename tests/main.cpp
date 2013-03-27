#include "SDL/SDL.h"
#include <stdio.h>
#include <iostream>
#include "display_bmp.cpp"
#include <ctime>
using namespace std;


int main(){
	cout<<"Initializing SDL"<<endl;

	//Initializing SDL
	if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == -1)){
		printf("Error:1 Could not initialize SDL: %s.\n",SDL_GetError());
		return 1;
	}

	cout<<"SDL initialized"<<endl;

	//Setting up a screen
	SDL_Surface *screen;
	screen = SDL_SetVideoMode(640,480,8,SDL_SWSURFACE|SDL_ANYFORMAT);
	if(screen == NULL){
		printf("Error:2 Could set a 640x480x8 video mode: %s\n",SDL_GetError());
		return 1;
	}

	printf("Set 640x480 at %d bits-per-pixel mode\n",screen->format->BitsPerPixel);

	display_bmp(screen,"calvin.bmp");
	sleep(2);

	cout<<"Quiting SDL"<<endl;

	SDL_Quit();
	cout<<"Quiting....."<<endl;
	return 0;
}

