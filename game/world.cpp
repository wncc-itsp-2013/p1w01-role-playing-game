#include <GL/glu.h>
#include "cube.h"

#include "world.h"

world::world(){
    thickness=0.1;
    xlength=3000;
    zlength=2000;
}

world::world(float thick,float xl, float zl){
    thickness=thick;
    xlength=xl;
    zlength=zl;
}

void world::draw(){
    glPushMatrix();
    glTranslatef(0,-thickness/2,0);

    glPushMatrix();
    glScalef(2*xlength,thickness,2*zlength);
    cube();
    glPopMatrix();

    //cube();
    glPopMatrix();
}

