#include <GL/freeglut.h>
#include <GL/glu.h>
#include "objects/cube.h"


float rotate_x=0;
float rotate_y=0;

void keyboardKeys(unsigned char key,int x,int y){
	switch(key){
		case 'w':
			rotate_x-=5;
			break;
		case 's':
			rotate_x+=5;
			break;
		case 'a':
			rotate_y+=5;
			break;
		case 'd':
			rotate_y-=5;
			break;
	}
	glutPostRedisplay();
}

void init(void)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 20.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.07 };
	GLfloat white_light[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat lmodel_ambient[] = { 1, 1, 1, 1.0 };
	glClearColor(0.4, 0.4, 0.7, 1.0);
	gluLookAt(0,0,5,0,0,0,0,1,0);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0005);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF,180);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float colors[]={0,0,255,0,0,255,0,0,255};
	glPushMatrix();
	glRotatef(rotate_x,1,0,0);
	glRotatef(rotate_y,0,1,0);

	glColor3f(0.2,0.8,0.2);
	cube();

	glPopMatrix();
	glFlush();
}


void reshape(int w, int h){
	glViewport(0,0,(GLsizei) w,(GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glFrustum(-1,1, -(GLfloat)h/(GLfloat)w,(GLfloat)h/(GLfloat)w,1.5,20);
	else
		glFrustum(-(GLfloat)w/(GLfloat)h,(GLfloat)w/(GLfloat)h,-1,1,1.5,20);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Game");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardKeys);
	glutMainLoop();
	return 0;
}

