/* Athabasca University

   Comp390 - Introduction to Computer Graphics
   Producing the output showing the diffrence between object with antialising and without
  Assignment 1
  Program 1


   @author: chukwufumnanya obi

   @date: June 5 2022


   */


#include "gl/glut.h"



// initialize

void initialize() {

	// set background color

	glClearColor(1.0, 1.0, 1.0, 0.0);

}



// render

void render() {

	// points color

	glColor3f(0.0, 0.0, 0.0);
	// set mode to draw polygons without fill

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


   //Draw the top object without antialising 
	glDisable(GL_LINE_SMOOTH);

	glDisable(GL_BLEND);

	
	//Draw the triangle for the top of the house
	glBegin(GL_TRIANGLES);

	glVertex2f(-2.75, 3.25);

	glVertex2f(-4.25, 1.75);

	glVertex2f(-4.0, 3.0);

	glEnd();


	//Draw the square for the bottom of the house
	glBegin(GL_QUADS);
	glVertex2f(-3.0, 1.0);
	glVertex2f(-2.0, 2.0);
	glVertex2f(-3.0, 3.0);
	glVertex2f(-4.0, 2.0);

	glEnd();
	glEnable(GL_LINE_SMOOTH);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	//Draw the house below with antialising 
	//Draw the triangle for the top of the house

	glBegin(GL_TRIANGLES);

	glVertex2f(0.25, 0.25);

	glVertex2f(-1.25, -1.25);

	glVertex2f(-1.0, 0.0);

	glEnd();

//Draw the square for the bottom of the house

	glBegin(GL_QUADS);
	glVertex2f(0.0, -2.0);
	glVertex2f(1.0, -1.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(-1.0, -1.0);

	glEnd();


}



// display registry

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();



	// viewing

	gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


	//display the render 
	render();



	glutSwapBuffers();

}



// reshape registry

void reshape(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);

	glMatrixMode(GL_MODELVIEW);

}



/ main program

void main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(100, 100);



	int windowHandle = glutCreateWindow("Athabasca University -TME1 -Program 1");

	glutSetWindow(windowHandle);



	glutDisplayFunc(display);

	glutReshapeFunc(reshape);



	initialize();



	glutMainLoop();

}