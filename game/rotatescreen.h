#ifndef ROTATESCREEN_H
#define ROTATESCREEN_H

float rotate_x=0;
float rotate_y=0;

bool turnright = false;
bool turnleft =false;


void rotateright(){
	static timer hunmilli(100);
	if(!turnright){
		hunmilli.reset();
		return;
	}
	hunmilli.update();
	if(hunmilli.check()){
		rotate_y-=1;
	}
	rotateright();
}


#endif
