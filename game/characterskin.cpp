#include "SDL/SDL.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "cube.h"

void chead(){
    glPushMatrix();
    glColor3f(1,220/255.0,128/255.0);
    glScalef(8,3,7);
    mini();
    glPopMatrix();
}
