#ifndef INITIALIZE_CPP
#define INITIALIZE_CPP

#include <iostream>
#include <stdio.h>
#include "SDL/SDL.h"

void sdlInit(char c){
	switch(c){
		case 'a':
			if(SDL_Init(SDL_INIT_EVERYTHING)==-1){
				printf("Could not initialize all: %s.\n", SDL_GetError());
				return;
			}
			break;
		case 't':
			if(SDL_Init(SDL_INIT_TIMER)==-1){
				printf("Could not initialize timer: %s.\n", SDL_GetError());
				return;
			}
			break;
		case 'v':
			if(SDL_Init(SDL_INIT_VIDEO)==-1){
				printf("Could not initialize video: %s.\n", SDL_GetError());
				return;
			}
			break;
		case 'c':
			if(SDL_Init(SDL_INIT_CDROM)==-1){
				printf("Could not initialize cdrom: %s.\n", SDL_GetError());
				return;
			}
			break;
		case 'j':
			if(SDL_Init(SDL_INIT_JOYSTICK)==-1){
				printf("Could not initialize joystick: %s.\n", SDL_GetError());
				return;
			}
			break;
	}
}

#endif
