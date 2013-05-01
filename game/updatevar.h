#ifndef UPDATEVAR_H
#define UPDATEVAR_H
#include "timer.h"
#include <iostream>

void updateall(){
	static timer hund(1000);
	hund.update();
	if(hund.check()){
		std::cout<<"Hello"<<std::endl;
	}
}


#endif
