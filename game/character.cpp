#ifndef CHARACTER_H
#define CHARACTER_H

#include <GL/glu.h>
#include "SDL/SDL.h"
#include "mymath.h"
#include "cube.h"
#include <iostream>
#include <cmath>
#include "timer.h"
#include <iostream>
#include "characterskin.h"

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
	float height=0.5,fvlength=0.5,svlength=0.5;
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
	//B1 angle between vertical and hand along the line joining lungs 
	//B2
	//D1
	//D2
	//E1 angle between rightleg from vertical
	//E2
	//G1
	//G2
	//T
	

	public:


	double A,B1,B2,D1,D2,E1,E2,G1,G2,T;

    bool walking;//true only when the player is walking

    //number of seconds taken for one complete oscillation of leg
    float legSpeed;

    float xCor,yCor;

	character(){
		l=0.4;
		c=0.3;
		a=0.3;
		b=0.3;
		h=0.4;
		d=0.5;
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

        xCor=0;
        yCor=0;

        walking=false;
        legSpeed=0.5;
	}

	void draw(){

		glPushMatrix();
		glRotatef(T,0,0,1);
		glTranslatef(0,a+l,0);

		//body with diaphram as center
		body(b,d,a,c);
			/********TEST**********/
			//the small dot at the center of the diaphram
			//cuboid(0.05,0.05,0.05);
			/**********TEST*******/

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

		/*******TEST***********/
		//the thin vertical line running from top till 
		//bottom and the blue bottom plate
		//cuboid(1,0.1,1);
		//glColor3f(0.1,0.8,0.1);
		//cuboid(0.01,5,0.01);
		/*******TEST******/
	}

    //walking
    void walk(){
        static contimer walker;
        double delta=walker.getDelta();
        static double totalTime=0;
        totalTime+=delta;
        totalTime=fmod(totalTime,legSpeed);
        E1=spike(totalTime,legSpeed,15);
        E2=-spike(totalTime,legSpeed,15);
        G2=spike(totalTime,legSpeed,15);
        G1=-spike(totalTime,legSpeed,15);
    }

	void action(){
        if(walking){
            walk();
        }
	}
};




#endif
