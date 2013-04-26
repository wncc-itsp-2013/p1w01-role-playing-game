#ifndef WORLD_H
#define WORLD_H

#include <GL/glu.h>
#include <GL/freeglut.h>
//#include "world.cpp"
#include "cube.h"


class world{
	//this is a temporary world 
	//Its just a rectangular slab on the xz plane
	
	float thickness;

	//half the lenght along x axis
	float xlength;
	//half the length along z axis
	float zlength;

	public:

	world(){
		thickness=0.1;
		xlength=2;
		zlength=2;
	}

	world(float thick,float xl, float zl){
		thickness=thick;
		xlength=xl;
		zlength=zl;
	}

	void draw(){
		glPushMatrix();
		glTranslatef(0,-thickness/2,0);
		glScalef(2*xlength,thickness,2*zlength);
		cube();
		glPopMatrix();
	}

};





#endif 
