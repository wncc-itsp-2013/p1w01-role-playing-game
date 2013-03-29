#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "SDL/SDL.h"
#include "putget.cpp"

window::window(int w, int h){
	screen = SDL_SetVideoMode(w,h,8,SDL_SWSURFACE|SDL_ANYFORMAT);
	if(screen == NULL){
		printf("Error:2 Could set a 640x480x8 video mode: %s\n",SDL_GetError());
		return 1;
	}
}

//Draw image to screen at respective coordinates
void draw(char *filename, int x, int y){

	SDL_Surface *image;
	/* Load the BMP file into a surface */
	image = SDL_LoadBMP(file_name);
	if (image == NULL) {
		fprintf(stderr, "Couldn’t load %s: %s\n", file_name, SDL_GetError());
		return;
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

	int xp,yp,xe,ye;
	Uint32 color;
	for(xp=0;xp<image->w;xp++){
		xe=x+xp;
		for(yp=0;yp < image->h;yp++){
			ye=y+yp;
			if(ye == screen->h){
				break;
			}
			else{
				color=getpixel(image,xp,yp);
				putpixel(screen,xe,ye,color);
			}
		}
	}		

	//deleting image
	SDL_FreeSurface(image);

}



//Draw image to respective coordinates ignoring specific colors
void draw(char *filename, int x, int y, int ix, int iy){
	SDL_Surface *image;
	/* Load the BMP file into a surface */
	image = SDL_LoadBMP(file_name);
	if (image == NULL) {
		fprintf(stderr, "Couldn’t load %s: %s\n", file_name, SDL_GetError());
		return;
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

	int xp,yp,xe,ye;
	Uint32 color,ignore;
	ignore=getpixel(image,ix,iy);
	if(SDL_MUSTLOCK(screen)){
		if(SDL_LockSurface(screen)<0){
			fprintf(stderr,"Can't lock screen: %s\n",SDL_GetError());
		}
	}
	for(xp=0;xp<image->w;xp++){
		xe=x+xp;
		for(yp=0;yp < image->h;yp++){
			ye=y+yp;
			if(ye == screen->h){
				break;
			}
			else{
				color=getpixel(image,xp,yp);
				if(color == ignore){
					continue;
				}
				else{
					putpixel(screen,xe,ye,color);
				}
			}
		}
	}	
	if(SDL_MUSTLOCK(screen)){
		SDL_UnlockSurface(screen);
	}

	//deleting image
	SDL_FreeSurface(image);
}



//reload the window
void reload(){
	SDL_UpdateRect(screen,0,0,0,0);
}

//close the window
void close(){
	SDL_FreeSurface(screen);
}


#endif
