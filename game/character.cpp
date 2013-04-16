#ifndef CHARACTER_H
#define CHARACTER_H

#include <GL/glu.h>
#include <GL/freeglut.h>

//pi/180
#define pi180 0.017453293

class character(){
	//l length of leg
	//a length from diaphram to pelvis
	//b length from neck till diaphram
	//c distance between legs
	//h length of hand
	private float l,a,b,c,h;

	//all angles are capital letters
	//A angle between head and the body
	//B1  
	//B2
	//D1
	//D2
	//E1
	//E2
	//G1
	//G2
	//T
	private int A,B1,B2,D1,D2,E1,E2,G1,G2,T;

	character(){

	}

	draw(){
		glPushMatrix();
		glTranslate3f();
		glPopMatrix();
	}













}


#endif
