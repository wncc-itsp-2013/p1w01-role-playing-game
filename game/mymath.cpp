
#ifndef MYMATH_CPP
#define MYMATH_CPP

#include <cmath>
#define mypi 3.14159

float mysin(int T){
	return sin(((float)mypi)*((float)T)/((float)180));
}

float mycos(int T){
	return cos(((float)mypi)*((float)T)/((float)180));
}

float mytan(int T){
	return tan(((float)mypi)*((float)T)/((float)180));
}

double spike(double value,double period,double max){
    return ((abs(4*max*(fmod(value+(period/4),period)-(period/2))/period))-max);
}

#endif
