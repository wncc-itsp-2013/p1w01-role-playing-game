#include "SDL/SDL.h"
#include <iostream>
#include "putget.cpp"
using namespace std;

int main(){
	SDL_Surface *image,*screen;

	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(640,480,8,SDL_SWSURFACE|SDL_ANYFORMAT);


	/* Load the BMP file into a surface */
	image = SDL_LoadBMP("white.bmp");
	if (image == NULL) {
		fprintf(stderr, "Couldnt load: %s\n",  SDL_GetError());
		return 1;
	}
	/*
	* Palettized screen modes will have a default palette (a standard
	* 8*8*4 colour cube), but if the image is palettized as well we can
	* use that palette for a nicer colour matching
	*/
	if (image->format->palette && screen->format->palette) {
		SDL_SetColors(screen, image->format->palette->colors, 0,
		image->format->palette->ncolors);
	}
	/* Blit onto the screen surface */
	if(SDL_BlitSurface(image, NULL, screen, NULL) < 0)
		fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());

	int i,j;
	std::cout<<image->w<<std::endl;
	std::cout<<image->h<<std::endl;
	for(i=image->w;i==image->w;i++){
		for(j=image->h;j==image->h;j++){
			cout<<getpixel(image,i,j)<<"   ";
		}
		cout<<endl;
	}
	SDL_Quit();
	return 0;
}



	

