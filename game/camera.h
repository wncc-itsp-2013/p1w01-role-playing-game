#ifndef ROTATESCREEN_H
#define ROTATESCREEN_H

#include "timer.h"

float rotate_x=0;
float rotate_y=0;

//0 for none
//1 for up
//2 for right
//3 for down
//4 for left
int turnDirection=0;

bool turning=false;

void rotate(){
	static contimer rotator;
    if(turnDirection != 0)


    rotator.getDelta();



}

#endif
