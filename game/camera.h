#ifndef ROTATESCREEN_H
#define ROTATESCREEN_H

#include "timer.h"
#include <cmath>

float rotate_x=20;
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

//maximum vertical angle it can go
//float cameraVerticalThreshould=30;
float cameraUpThreshould=-10;
float cameraDownThreshould=30;


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
                if(rotate_x > -cameraUpThreshould){
                    rotate_x-=camXSpeed*delta;
                }
                break;
            case 2:
                rotate_y-=camYSpeed*delta;
                rotate_y=fmod(rotate_y,360);
                break;
            case 3:
                if(rotate_x < cameraDownThreshould){
                    rotate_x+=camXSpeed*delta;
                }
                break;
            case 4:
                rotate_y+=camXSpeed*delta;
                rotate_y=fmod(rotate_y,360);
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
