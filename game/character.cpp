#ifndef CHARACTER_H
#define CHARACTER_H

#include <GL/glu.h>
#include <GL/freeglut.h>
#include "mymath.h"

//pi/180
#define pi180 0.017453293

class character(){
	//l length of leg
	//a length from diaphram to pelvis
	//b length from neck till diaphram
	//c half the distance between legs
	//h length of hand
	//d half of the horizontal chest length
	private float l,a,b,c,d,h;

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
		float temp=(a+(l/2)+(c*(mytan T)));
		glTranslate3f( temp*(mysin T),temp*(mycos T),0);
		glRotate3f(T,0,0,1);
			//right hand
			glPushMatrix();
			//translate so that hands joint to body becomes origin
			glTranslate3f(d,b,0);
			glRotate(G1,-1,0,0);
			glRotate(B1,0,0,1);
			//draw hand here starting from origin towards -ve y axis

				glPushMatrix();
				glTranslate3f(0,-h,0);
				glRotate3f(D1,0,0,-1);
				//draw palm here from origin towards -ve y axis

				glPopMatrix();
			glPopMatrix();

			//left hand
			glPushMatrix();
			//translate so that hands joint to body becomes origin
			glTranslate3f(-d,b,0);
			glRotate(G2,-1,0,0);
			glRotate(B2,0,0,-1);
			//draw hand here starting from origin towards -ve y axis

				glPushMatrix();
				glTranslate3f(0,-h,0);
				glRotate3f(D2,0,0,1);
				//draw palm here from origin towards -ve y axis

				glPopMatrix();
			glPopMatrix();

			//right leg
			glPushMatrix();
			glTranslate3f(c,-a,0);
			glRotate3f(E1,-1,0,0);
			//draw leg starting from origin towards -ve y axis

			glPopmatrix();

			//left leg
			glPushMatrix();
			glTranslate3f(-c,-a,0);
			glRotate3f(E2,-1,0,0);
			//draw leg starting from origin towards -ve y axis

			glPopmatrix();

			//head
			glPushMatrix();
			glTranslate3f(0,b,0);
			glRotate3f(A,1,0,0);
			//draw head here starting from origin towards +ve y axis


			glPopMatrix();

		glPopMatrix();
	}

}




#endif
