#ifndef WORLD_H
#define WORLD_H

//#include <GL/glu.h>
//#include "world.cpp"
//#include "cube.h"


class world{
	//this is a temporary world 
	//Its just a rectangular slab on the xz plane
	
	float thickness;

	//half the lenght along x axis
	float xlength;
	//half the length along z axis
	float zlength;

	public:

	world();

	world(float thick,float xl, float zl);

	void draw();

};





#endif 
