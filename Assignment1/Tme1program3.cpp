/* Athabasca University

   Comp390 - Introduction to Computer Graphics

  Assignment 1 program 3


  showing the display of colour
   @author: Steve Leung

   @date: May 4, 2011

*/



#include "gl/glut.h"



// initialize

void initialize() {

	// set background color

	glClearColor(1.0, 1.0, 1.0, 0.0);

}



// render

void render() {

	// color


	glBegin(GL_QUADS);

	glColor3f(1.0, 0.0, 0.0);	//  color of the top left  side vertices green
	glVertex2f(-2.0, -2.0);
	glColor3f(0.0, 1.0, 0.0); //  color of the bottom left  side vertices red
	glVertex2f(-2.0, 2.0);

	glColor3f(0.0, 0.0, 1.0); //  color of the top right  side vertices blue

	glVertex2f(2.0, 2.0);
	glColor3f(1.0, 1.0, 0.0);//  color of the top right  side vertices yellow
	glVertex2f(2.0, -2.0);

	glEnd();

}



// display registry

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();



	// viewing

	gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



	render();



	glutSwapBuffers();

}



// reshape registry

void reshape(int w, int h) {

	glViewport(0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);

	glMatrixMode(GL_MODELVIEW);

}



// main program

void main(int argc, char **argv)

{

	glutInit( &argc, argv );

	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;

	glutInitWindowSize(500, 500);

  	glutInitWindowPosition(100, 100);



	int windowHandle = glutCreateWindow("Athabasca University - TME program 3");

	glutSetWindow(windowHandle);



	glutDisplayFunc( display );

	glutReshapeFunc( reshape );



	initialize();



    glutMainLoop();

}