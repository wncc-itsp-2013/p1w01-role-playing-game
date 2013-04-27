#ifndef MAIN_CPP
#define MAIN_CPP 
#include "SDL/SDL.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "cube.h"
#include "character.cpp"
#include "world.h"
#include <iostream>

float rotate_x=0;
float rotate_y=0;
bool running;
static GLboolean should_rotate = GL_TRUE;
static int quitSDL(int code);

void keyboardKeys(unsigned char key,int x,int y){
	switch(key){
		case 'w':
			rotate_x-=5;
			break;
		case 's':
			rotate_x+=5;
			break;
		case 'a':
			rotate_y+=5;
			break;
		case 'd':
			rotate_y-=5;
			break;
	}
	//glutPostRedisplay();
}

static void handle_key_down(SDL_keysym* keysym){
	switch(keysym->sym){
		case SDLK_ESCAPE:
			quitSDL(0);
			break;
		case SDLK_SPACE:
			should_rotate = !should_rotate;
			break;
		case SDLK_UP:
			rotate_x-=5;
			break;
		case SDLK_DOWN:
			rotate_x+=5;
			break;
		case SDLK_LEFT:
			rotate_y+=5;
			break;
		case SDLK_RIGHT:
			rotate_y-=5;
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

void initializeGL1(int width, int height){

float ratio = (float) width / (float) height;
/* Our shading model--Gouraud (smooth). */
glShadeModel( GL_SMOOTH );
/* Culling. */
glCullFace( GL_BACK );
glFrontFace( GL_CCW );
glEnable( GL_CULL_FACE );
/* Set the clear color. */
glClearColor( 1, 0, 0, 0 );
/* Setup our viewport. */
glViewport( 0, 0, width, height );
/*
 * * Change to the projection matrix and set
 * * our viewing volume.
 * */
glMatrixMode( GL_PROJECTION );
glLoadIdentity( );
/*
 * * EXERCISE:
 * * Replace this with a call to glFrustum.
 * */
gluPerspective( 60.0, ratio, 1.0, 1024.0 );

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
	character neo;
	neo.draw();
	/***************DRAWING ENDS**************/

	glPopMatrix();
	glFlush();

	SDL_GL_SwapBuffers();
}

void draw_screen1(void)
{
/* Our angle of rotation. */
static float angle = 0.0f;
/*
* EXERCISE:
* Replace this awful mess with vertex
* arrays and a call to glDrawElements.
*
* EXERCISE:
* After completing the above, change
* it to use compiled vertex arrays.
*
* EXERCISE:
* Verify my windings are correct here ;).
*/
static GLfloat v0[] = { -1.0f, -1.0f, 1.0f };
static GLfloat v1[] = { 1.0f, -1.0f, 1.0f };
static GLfloat v2[] = { 1.0f, 1.0f, 1.0f };
static GLfloat v3[] = { -1.0f, 1.0f, 1.0f };
static GLfloat v4[] = { -1.0f, -1.0f, -1.0f };
static GLfloat v5[] = { 1.0f, -1.0f, -1.0f };
static GLfloat v6[] = { 1.0f, 1.0f, -1.0f };
static GLfloat v7[] = { -1.0f, 1.0f, -1.0f };
static GLubyte red[] = { 255, 0, 0, 255 };
static GLubyte green[] = { 0, 255, 0, 255 };
static GLubyte blue[] = { 0, 0, 255, 255 };
static GLubyte white[] = { 255, 255, 255, 255 };
static GLubyte yellow[] = { 0, 255, 255, 255 };
static GLubyte black[] = { 0, 0, 0, 255 };
static GLubyte orange[] = { 255, 255, 0, 255 };
static GLubyte purple[] = { 255, 0, 255, 0 };
/* Clear the color and depth buffers. */
glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
/* We don’t want to modify the projection matrix. */
glMatrixMode( GL_MODELVIEW );
glLoadIdentity( );
/* Move down the z-axis. */
glTranslatef( 0.0, 0.0, -5.0 );
/* Rotate. */
glRotatef( angle, 0.0, 1.0, 0.0 );
if( should_rotate ) {
if( ++angle > 360.0f ) {
angle = 0.0f;
}
}
/* Send our triangle data to the pipeline. */
glBegin( GL_TRIANGLES );
glColor4ubv( red );
glVertex3fv( v0 );
glColor4ubv( green );
glVertex3fv( v1 );
glColor4ubv( blue );
glVertex3fv( v2 );
glColor4ubv( red );
glVertex3fv( v0 );
glColor4ubv( blue );
glVertex3fv( v2 );
glColor4ubv( white );
glVertex3fv( v3 );
glColor4ubv( green );
glVertex3fv( v1 );
glColor4ubv( black );
glVertex3fv( v5 );
glColor4ubv( orange );
glVertex3fv( v6 );
glColor4ubv( green );
glVertex3fv( v1 );
glColor4ubv( orange );
glVertex3fv( v6 );
glColor4ubv( blue );
glVertex3fv( v2 );
glColor4ubv( black );
glVertex3fv( v5 );
glColor4ubv( yellow );
glVertex3fv( v4 );
glColor4ubv( purple );
glVertex3fv( v7 );
glColor4ubv( black );
glVertex3fv( v5 );
glColor4ubv( purple );
glVertex3fv( v7 );
glColor4ubv( orange );
glVertex3fv( v6 );
glColor4ubv( yellow );
glVertex3fv( v4 );
glColor4ubv( red );
glVertex3fv( v0 );
glColor4ubv( white );
glVertex3fv( v3 );
glColor4ubv( yellow );
glVertex3fv( v4 );
glColor4ubv( white );
glVertex3fv( v3 );
glColor4ubv( purple );
glVertex3fv( v7 );
glColor4ubv( white );
glVertex3fv( v3 );
glColor4ubv( blue );
glVertex3fv( v2 );
glColor4ubv( orange );
glVertex3fv( v6 );
glColor4ubv( white );
glVertex3fv( v3 );
glColor4ubv( orange );
glVertex3fv( v6 );
glColor4ubv( purple );
glVertex3fv( v7 );
glColor4ubv( green );
glVertex3fv( v1 );
glColor4ubv( red );
glVertex3fv( v0 );
glColor4ubv( yellow );
glVertex3fv( v4 );
glColor4ubv( green );
glVertex3fv( v1 );
glColor4ubv( yellow );
glVertex3fv( v4 );
glColor4ubv( black );
glVertex3fv( v5 );
glEnd( );
/*
* EXERCISE:
* Draw text telling the user that ’Spc’
* pauses the rotation and ’Esc’ quits.
* Do it using vetors and textured quads.
*/
/*
* Swap the buffers. This this tells the driver to
* render the next frame from the contents of the
* back-buffer, and to set all rendering operations
* to occur on what was the front-buffer.
*
* Double buffering prevents nasty visual tearing
* from the application drawing on areas of the
* screen that are being updated at the same time.
*/
SDL_GL_SwapBuffers( );
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

	flags = SDL_OPENGL | SDL_FULLSCREEN;
	//flags = SDL_SWSURFACE | SDL_ANYFORMAT;

	if(SDL_SetVideoMode(width, height,bpp, flags)==0){
		std::cout<<"Video mode set failed"<<std::endl;
		quitSDL(1);
	}

	initializeGL(width,height);
}


int main(int argc, char** argv)
{
	initializeSDL();
	while(1){
		process_events();
		draw_screen();

	}
	//glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(1000, 700);
	//glutInitWindowPosition(100, 100);
	//glutCreateWindow("Game");
	//glutDisplayFunc(display);
	//glutReshapeFunc(reshape);
	//glutKeyboardFunc(keyboardKeys);
	//glutMainLoop();
	return 0;
}

#endif
