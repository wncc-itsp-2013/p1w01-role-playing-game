#ifndef UPDATEVAR_H
#define UPDATEVAR_H
#include "timer.h"
#include <iostream>

void updateall(){

	//Managing the frame rate
	int rate=1;
	static timer hund((1000/rate));
	hund.update();
	if(hund.check()){
		std::cout<<"hello\n";
	}
}


#endif
