#include "SDL/SDL.h"
#include "putget.cpp"
#include "windows.hpp"


window::window(int w, int h){
	screen = SDL_SetVideoMode(w,h,8,SDL_SWSURFACE|SDL_ANYFORMAT);
	if(screen == NULL){
		printf("Error:2 Could set a 640x480x8 video mode: %s\n",SDL_GetError());
		return;
	}
	bgcolor=SDL_MapRGB(screen->format,255,255,255);
	refresh();
}

void window::refresh(){
	int i,j;
	if(SDL_MUSTLOCK(screen)){
		if(SDL_LockSurface(screen)<0){
			fprintf(stderr, "Can't lock screen: %s\n",SDL_GetError());
			return;
		}
	}
	for(i=0;i<screen->w;i++){
		for(j=0;j<screen->h;j++){
			putpixel(screen,i,j,bgcolor);
		}
	}
	if(SDL_MUSTLOCK(screen)){
		SDL_UnlockSurface(screen);
	}
}

void window::setbgcolor(int x,int y, int z){
	bgcolor=SDL_MapRGB(screen->format,x,y,z);
}

//Draw image to screen at respective coordinates
void window::draw(char *filename, int x, int y){

	SDL_Surface *image;
	/* Load the BMP file into a surface */
	image = SDL_LoadBMP(filename);
	if (image == NULL) {
		fprintf(stderr, "Couldn’t load %s: %s\n", filename, SDL_GetError());
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
void window::draw(char *filename, int x, int y, int ix, int iy){
	SDL_Surface *image;
	/* Load the BMP file into a surface */
	image = SDL_LoadBMP(filename);
	if (image == NULL) {
		fprintf(stderr, "Couldn’t load %s: %s\n", filename, SDL_GetError());
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
void window::reload(){
	SDL_UpdateRect(screen,0,0,0,0);
}

//close the window
void window::close(){
	SDL_FreeSurface(screen);
}


