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

float camXSpeed=30;
float camYSpeed=30;

void rotate(){
	static contimer rotator;
    if(turnDirection != 0){
        if(!turning){
            rotator.reset();
            turning=true;
        }
        double delta=rotator.getDelta();
        switch (turnDirection) {
            case 1:
                rotate_x-=camXSpeed*delta;
                break;
            case 2:
                rotate_y-=camYSpeed*delta;
                break;
            case 3:
                rotate_x+=camXSpeed*delta;
                break;
            case 4:
                rotate_y+=camXSpeed*delta;
                break;
            default:
                break;
        }
    }
    else if(turning){
        turning = false;
    }
}

#endif
