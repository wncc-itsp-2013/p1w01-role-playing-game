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
	screen = SDL_SetVideoMode(640,480,8,SDL_SWSURFACE|SDL_ANYFORMAT);
	if(screen == NULL){
		printf("Error:2 Could set a 640x480x8 video mode: %s\n",SDL_GetError());
		return 1;
	}

	printf("Set 640x480 at %d bits-per-pixel mode\n",screen->format->BitsPerPixel);

	/* Code to set a yellow pixel at the center of the screen */
	int x, y;
	Uint32 yellow;
	/* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
	Note: If the display is palettized, you must set the palette first.
	*/
	yellow = SDL_MapRGB(screen->format, 0xff, 0xff, 0x00);
	x = screen->w / 2 +200;
	y = screen->h / 2;
	/* Lock the screen for direct access to the pixels */
	if ( SDL_MUSTLOCK(screen) ) {
		if ( SDL_LockSurface(screen) < 0 ) {
			fprintf(stderr, "Can’t lock screen: %s\n", SDL_GetError());
			return 1;
		}
	}
	putpixel(screen, x, y, yellow);
	if ( SDL_MUSTLOCK(screen) ) {
		SDL_UnlockSurface(screen);
	}
	/* Update just the part of the display that we’ve changed */
	SDL_UpdateRect(screen, x, y, 1, 1);
	display_bmp(screen,"calvin.bmp");
	sleep(2);

	cout<<"Quiting SDL"<<endl;

	SDL_Quit();
	cout<<"Quiting....."<<endl;
	return 0;
}

