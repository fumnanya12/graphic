/* Athabasca University

   Comp390 - Introduction to Computer Graphics

  Assignment 1
  Program 2
Rotating and translating the house object 

   @author: chukwufumnanya obi

   @date: June 5 2022





#include "gl/glut.h"


*/
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


	

	//Draw the triangle 
	glBegin(GL_TRIANGLES);

	glVertex2f(1.0, 1.0);

	glVertex2f(-1.0, 1.0);

	glVertex2f(0.0, 1.5);

	glEnd();

	// creating the square 
	glBegin(GL_QUADS);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, 1.0);
	glVertex2f(-0.5, 1.0);

	glEnd();


}



// display registry

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();



	// viewing

	gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


	//original object 
	render();
	//translate and rotate on the left 
	glPushMatrix();
	glTranslatef(-1.5, -0.5, 0.0);   

	glRotatef(40.0, 0.0, 0.0, 1.0);

	render();
	glTranslatef(-1.5, -0.5, 0.0);

	glRotatef(40.0, 0.0, 0.0, 1.0);
	render();
	glPopMatrix();

	///translate and rotate on the right
	glPushMatrix();
	glTranslatef(1.5, -0.5, 0.0);

	glRotatef(-40.0, 0.0, 0.0, 1.0);  //rotate 40 degrees 

	render();
	glTranslatef(1.5, -0.5, 0.0);

	glRotatef(-40.0, 0.0, 0.0, 1.0); //rotate another  40 degrees which is 80
	render();
	glPopMatrix();


		


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



// main program

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

} */