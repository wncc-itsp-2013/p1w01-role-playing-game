#ifndef CHARACTER_H
#define CHARACTER_H

#include <GL/glu.h>
#include <GL/freeglut.h>
#include "mymath.h"
#include "cube.h"

//pi/180
#define pi180 0.017453293

void pole(float l){
	glPushMatrix();
	glTranslatef(0,l/2,0);
	glScalef(0.1,l,0.1);
	cube();
	glPopMatrix();
}


class character{
	//l length of leg
	//a length from diaphram to pelvis
	//b length from neck till diaphram
	//c half the distance between legs
	//h length of hand
	//d half of the horizontal chest length
	private:
		float l,a,b,c,d,h;

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
	
	int A,B1,B2,D1,D2,E1,E2,G1,G2,T;

	public:

	character(){
		l=1;
		c=0.5;
		a=1;
		b=1;
		h=1.5;
		d=0.7;
		A=0;
		B1=0;
		B2=0;
		D1=0;
		D2=0;
		E1=0;
		E2=0;
		G1=0;
		G2=0;
		T=0;
	}

	void draw(){
		glPushMatrix();
		float temp=(a+(l/2)+(c*(mytan(T))));
		glTranslatef( temp*(mysin (T)),temp*(mycos (T)),0);
		glRotatef(T,0,0,1);
			//right hand
			glPushMatrix();
			//translate so that hands joint to body becomes origin
			glTranslatef(d,b,0);
			glRotatef(G1,-1,0,0);
			glRotatef(B1,0,0,1);
			//draw hand here starting from origin towards -ve y axis
			pole(-h);

				glPushMatrix();
				glTranslatef(0,-h,0);
				glRotatef(D1,0,0,-1);
				//draw palm here from origin towards -ve y axis
				
				glPopMatrix();
			glPopMatrix();

			//left hand
			glPushMatrix();
			//translate so that hands joint to body becomes origin
			glTranslatef(-d,b,0);
			glRotatef(G2,-1,0,0);
			glRotatef(B2,0,0,-1);
			//draw hand here starting from origin towards -ve y axis
			pole(-h);

				glPushMatrix();
				glTranslatef(0,-h,0);
				glRotatef(D2,0,0,1);
				//draw palm here from origin towards -ve y axis

				glPopMatrix();
			glPopMatrix();

			//right leg
			glPushMatrix();
			glTranslatef(c,-a,0);
			glRotatef(E1,-1,0,0);
			//draw leg starting from origin towards -ve y axis
			pole(-l);

			glPopMatrix();

			//left leg
			glPushMatrix();
			glTranslatef(-c,-a,0);
			glRotatef(E2,-1,0,0);
			//draw leg starting from origin towards -ve y axis
			pole(-l);

			glPopMatrix();

			//head
			glPushMatrix();
			glTranslatef(0,b,0);
			glRotatef(A,1,0,0);
			//draw head here starting from origin towards +ve y axis
			pole(0.3);

			glPopMatrix();

		glPopMatrix();
	}

};




#endif
