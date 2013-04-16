#ifndef CUBE_H
#define CUBE_H

#include <GL/glu.h>
#include <GL/freeglut.h>

void cube(){
	//FRONT
	glBegin(GL_POLYGON);
	glNormal3f(0,0,1);
	glVertex3f(-0.5,-0.5,0.5);
	glVertex3f(0.5,-0.5,0.5);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(-0.5,0.5,0.5);
	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glNormal3f(0,0,-1);
	glVertex3f(-0.5,-0.5,-0.5);
	glVertex3f(0.5,-0.5,-0.5);
	glVertex3f(0.5,0.5,-0.5);
	glVertex3f(-0.5,0.5,-0.5);
	glEnd();

	//RIGHT
	glBegin(GL_POLYGON);
	glNormal3f(1,0,0);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(0.5,-0.5,0.5);
	glVertex3f(0.5,-0.5,-0.5);
	glVertex3f(0.5,0.5,-0.5);
	glEnd();

	//LEFT
	glBegin(GL_POLYGON);
	glNormal3f(-1,0,0);
	glVertex3f(-0.5,-0.5,-0.5);
	glVertex3f(-0.5,-0.5,0.5);
	glVertex3f(-0.5,0.5,0.5);
	glVertex3f(-0.5,0.5,-0.5);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glNormal3f(0,1,0);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(-0.5,0.5,0.5);
	glVertex3f(-0.5,0.5,-0.5);
	glVertex3f(0.5,0.5,-0.5);
	glEnd();

	//BOTTOM
	glBegin(GL_POLYGON);
	glNormal3f(0,-1,0);
	glVertex3f(-0.5,-0.5,-0.5);
	glVertex3f(-0.5,-0.5,0.5);
	glVertex3f(0.5,-0.5,0.5);
	glVertex3f(0.5,-0.5,-0.5);
	glEnd();

}

#endif
