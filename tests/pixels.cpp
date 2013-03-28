#include "SDL/SDL.h"
#include <stdio.h>
#include <iostream>
#include <ctime>

#include "display_bmp.cpp"
#include "putget.cpp"
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
	screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE|SDL_ANYFORMAT);
	if(screen == NULL){
		printf("Error:2 Could set a 640x480x8 video mode: %s\n",SDL_GetError());
		return 1;
	}

	printf("Set 640x480 at %d bits-per-pixel mode\n",screen->format->BitsPerPixel);

	/* Code to set a yellow pixel at the center of the screen */
	int x, y;
	Uint64 yellow;
	/* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
	Note: If the display is palettized, you must set the palette first.
	*/

	for(int i=255;i<256;i+=1){
		for(int j=255;j<256;j+=1){
			for(int k=255;k<256;k+=1){
				for(int l=0;l<256;l++){
					yellow = SDL_MapRGBA(screen->format, i, j, k,l);
					cout<<i<<"----"<<j<<"-----"<<k<<"----"<<yellow<<endl;
				}
			}
		}
	}
	
	cout<<"Quiting SDL"<<endl;

	SDL_Quit();
	cout<<"Quiting....."<<endl;
	return 0;
}

