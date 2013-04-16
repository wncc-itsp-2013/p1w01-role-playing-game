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

void head(){
	float height=0.6,fvlength=0.6,svlength=0.6;
	glPushMatrix();
	glTranslatef(0,height/2,0);
	glScalef(fvlength,height,svlength);
	cube();
	glPopMatrix();
}

void body(float b,float d,float a,float c){
	//upperpart
	glPushMatrix();
	glTranslatef(0,b/2,0);
	glScalef(2*d-0.3,b-0.1,0.5);
	cube();
	glPopMatrix();

	//lowerpart
	glPushMatrix();
	glTranslatef(0,-a/2,0);
	glScalef(2*c,a-0.1,0.4);
	cube();
	glPopMatrix();
}

void hand(float h){
	glPushMatrix();
	glTranslatef(0,-h/2,0);
	glScalef(0.2,h,0.3);
	cube();
	glPopMatrix();
}

void palm(){
	float h=0.2,f=0.3,s=0.3;
	glPushMatrix();
	glTranslatef(0,-h/2-0.01,0);
	glScalef(f,h,s);
	cube();
	glPopMatrix();
}


void leg(float l){
	glPushMatrix();
	glTranslatef(0,-l/2,0);
	glScalef(0.2,l,0.3);
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
		l=0.8;
		c=0.4;
		a=0.5;
		b=0.5;
		h=0.8;
		d=0.7;
		A=0;
		B1=45;
		B2=0;
		D1=0;
		D2=0;
		E1=-15;
		E2=15;
		G1=0;
		G2=0;
		T=0;
	}

	void draw(){
		glPushMatrix();
		float temp=(a+(l/2)+(c*(mytan(T))));
		glTranslatef( temp*(mysin (T)),temp*(mycos (T)),0);
		glRotatef(T,0,0,1);

		//body with diaphram as center
		body(b,d,a,c);
			//right hand
			glPushMatrix();
			//translate so that hands joint to body becomes origin
			glTranslatef(d,b,0);
			glRotatef(G1,-1,0,0);
			glRotatef(B1,0,0,1);
			//draw hand here starting from origin towards -ve y axis
			hand(h);

				glPushMatrix();
				glTranslatef(0,-h,0);
				glRotatef(D1,0,0,-1);
				//draw palm here from origin towards -ve y axis
				palm();
				glPopMatrix();
			glPopMatrix();

			//left hand
			glPushMatrix();
			//translate so that hands joint to body becomes origin
			glTranslatef(-d,b,0);
			glRotatef(G2,-1,0,0);
			glRotatef(B2,0,0,-1);
			//draw hand here starting from origin towards -ve y axis
			hand(h);

				glPushMatrix();
				glTranslatef(0,-h,0);
				glRotatef(D2,0,0,1);
				//draw palm here from origin towards -ve y axis
				palm();
				glPopMatrix();
			glPopMatrix();

			//right leg
			glPushMatrix();
			glTranslatef(c,-a,0);
			glRotatef(E1,-1,0,0);
			//draw leg starting from origin towards -ve y axis
			leg(l);

			glPopMatrix();

			//left leg
			glPushMatrix();
			glTranslatef(-c,-a,0);
			glRotatef(E2,-1,0,0);
			//draw leg starting from origin towards -ve y axis
			leg(l);

			glPopMatrix();

			//head
			glPushMatrix();
			glTranslatef(0,b,0);
			glRotatef(A,1,0,0);
			//draw head here starting from origin towards +ve y axis
			head();

			glPopMatrix();

		glPopMatrix();
	}

};




#endif
