#ifndef DISPLAY_CPP
#define DISPLAY_CPP


#include "SDL/SDL.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "cube.h"
#include "character.cpp"
#include "world.h"
#include "timer.h"
#include "timeupdater.h"
#include "camera.h"
#include "updatevar.h"
#include "initialisations.cpp"
#include <iostream>
#include <cmath>

#include "characterskin.h"

void draw_screen(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float colors[]={0,0,255,0,0,255,0,0,255};
	glPushMatrix();
	glRotatef(rotate_x,1,0,0);
	glRotatef(rotate_y,0,1,0);

	/****************DRAWING STARTS************/
	glColor3f(0.2,0.8,0.2);
	world newworld;
	newworld.draw();

	glColor3f(0.2,0.2,0.8);
	neo.draw();


    //chead();
	/***************DRAWING ENDS**************/

	glPopMatrix();
	glFlush();

	SDL_GL_SwapBuffers();
}


#endif
