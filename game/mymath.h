#ifndef MYMATH_H
#define MYMATH_H

#include "mymath.cpp"

float mysin(int T);

float mycos(int T);

float mytan(int T);


double spike(double value){
    return spike(value,4.0,1.0);
}

double spike(double value,double period,double max);

#endif 
