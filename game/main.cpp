#ifndef MAIN_CPP
#define MAIN_CPP 
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
#include <iostream>
#include <cmath>

//float rotate_x=0;
//float rotate_y=0;
static int quitSDL(int code);

character neo;

static void handle_key_down(SDL_keysym* keysym){
	switch(keysym->sym){
		case SDLK_ESCAPE:
			quitSDL(0);
			break;
		case SDLK_w:
            turnDirection=1;
			//rotate_x-=5;
			break;
		case SDLK_s:
            turnDirection=3;
			//rotate_x+=5;
			break;
		case SDLK_a:
            turnDirection=4;
			//rotate_y+=5;
			break;
		case SDLK_d:
            turnDirection=2;
			//rotate_y-=5;
			//turnright=true;
			//rotateright();
			break;
		default:
			break;
	}
	//glutPostRedisplay();
}

static void handle_key_up(SDL_keysym* keysym){
	switch(keysym->sym){
		case SDLK_w:
			turnDirection=0;
			break;
		case SDLK_s:
			turnDirection=0;
			break;
		case SDLK_a:
			turnDirection=0;
			break;
		case SDLK_d:
			turnDirection=0;
			break;
		default:
			break;
	}
	//glutPostRedisplay();
}

static void process_events(void){
	SDL_Event event;

	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_KEYDOWN:
				handle_key_down(&event.key.keysym);
				break;
			/**case SDL_KEYUP:
				handle_key_up(&event.key.keysym);
				break;**/
			case SDL_QUIT:
				quitSDL(0);
				break;
		}
	}


}

void initializeGL(int w, int h)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 20.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.07 };
	GLfloat white_light[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat lmodel_ambient[] = { 1, 1, 1, 1.0 };
	glClearColor(0.4, 0.4, 0.7, 1.0);
	gluLookAt(0,0,5,0,0,0,0,1,0);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0005);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF,180);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glViewport(0,0,(GLsizei) w,(GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glFrustum(-1,1, -(GLfloat)h/(GLfloat)w,(GLfloat)h/(GLfloat)w,1.5,20);
	else
		glFrustum(-(GLfloat)w/(GLfloat)h,(GLfloat)w/(GLfloat)h,-1,1,1.5,20);
	glMatrixMode(GL_MODELVIEW);
}

void draw_screen(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float colors[]={0,0,255,0,0,255,0,0,255};
	glPushMatrix();
	glRotatef(rotate_x,1,0,0);
	glRotatef(rotate_y,0,1,0);

	/****************DRAWING STARTS************/
	glColor3f(0.2,0.8,0.2);
	//cube();
	//world newworld(0.2,2,2);
	world newworld;
	newworld.draw();

	glColor3f(0.2,0.2,0.8);
	//character neo;
	neo.draw();
	/***************DRAWING ENDS**************/

	glPopMatrix();
	glFlush();

	SDL_GL_SwapBuffers();
}

void reshape(int w, int h){
	glViewport(0,0,(GLsizei) w,(GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glFrustum(-1,1, -(GLfloat)h/(GLfloat)w,(GLfloat)h/(GLfloat)w,1.5,20);
	else
		glFrustum(-(GLfloat)w/(GLfloat)h,(GLfloat)w/(GLfloat)h,-1,1,1.5,20);
	glMatrixMode(GL_MODELVIEW);
}

static int quitSDL(int code){
	SDL_Quit();
	return code;
}

void initializeSDL(){
	const SDL_VideoInfo* info = NULL;
	//height and width of window
	int height=700;
	int width=1000;
	//color depth in bits
	int bpp=0;
	int flags=0;

	if(SDL_Init(SDL_INIT_VIDEO)<0){
		std::cout<<"Video Initialisation Failed"<<std::endl;
		quitSDL(1);
	}

	info = SDL_GetVideoInfo();

	if(!info){
		std::cout<<"Video query failed"<<std::endl;
		quitSDL(1);
	}

	bpp=info->vfmt->BitsPerPixel;
	
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	//flags = SDL_OPENGL | SDL_FULLSCREEN;
	flags = SDL_OPENGL | SDL_ANYFORMAT;

	if(SDL_SetVideoMode(width, height,bpp, flags)==0){
		std::cout<<"Video mode set failed"<<std::endl;
		quitSDL(1);
	}

	initializeGL(width,height);
}

void manageframe(){

    //updateall();
    
	//Managing the frame rate
	int rate=60;
	static timer framestimer((1000/rate));
	framestimer.update();
	if(framestimer.check()){
		draw_screen();
	}
    
    //static contimer walktimer;
    //neo.E1=fmod(neo.E1+15+(15*walktimer.getDelta()),30)-15;
    

    //static parametricSine walktimer;
}

int main(int argc, char** argv)
{
	initializeSDL();
	while(1){
		//updateall();
		process_events();

		manageframe();
	}
	return 0;
}

#endif
