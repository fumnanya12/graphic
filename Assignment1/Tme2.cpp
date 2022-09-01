/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4


   3D transformation matrix


   TMe2 program1
   @author: chukwufumnanya obi

   @date: june 12 2022
  
  */




#include <iostream>

#include "gl/glut.h"



using namespace std;



// vertex array

typedef GLint vertex3[3];  //arry type
typedef GLfloat vertex4[3];




vertex3 pt[8] = { {-0.5,-1,0}, {0,1.5,0}, {-2,-1,0}, {-2,1.5,0}, {0,0,-2.5}, {0,2,-2}, {-2,0,-2}, {-2,2,-2} }; //coordinate for the green rectangle

vertex3 st[4] = { {4,-1,3},{4,1,-4},{-4,-1,4},{-4,1,-4} }; //coordinate for the red  cube
vertex4 tr[5] = { {-2.5,0.8,0.0}, {0.5,0.9,0.5},{-1.0,3.0,0},{0.0,2.1,-3.0},{-3.0,2.1,-4.0} }; //coordinate for the blue triangle



// initialize

void initialize() {

	// set background color

	glClearColor(1.0, 1.0, 1.0, 0.0);

}






// Draw the rectangle for the lower part of the house

void quad(GLint n1, GLint n2, GLint n3, GLint n4) {

	glBegin(GL_LINE_LOOP);

	glVertex3iv(pt[n1]);

	glVertex3iv(pt[n2]);

	glVertex3iv(pt[n3]);

	glVertex3iv(pt[n4]);

	glEnd();

}
//draw the cube
void ruad(GLint n1, GLint n2, GLint n3, GLint n4) {

	glBegin(GL_LINE_LOOP);

	glVertex3iv(st[n1]);

	glVertex3iv(st[n2]);

	glVertex3iv(st[n3]);

	glVertex3iv(st[n4]);

	glEnd();
}

// draw the pyramid’s 
void tuad(GLint n1, GLint n2, GLint n3) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLES);

	glVertex3fv(tr[n1]);

	glVertex3fv(tr[n2]);

	glVertex3fv(tr[n3]);


	glEnd();
}

void cube() {
	
	glColor3f(1.0, 0.0, 0.0);
	quad(0, 2, 3, 1); // front 

	quad(0, 4, 5, 1); //right

	quad(2, 6, 7, 3); ///left

	quad(1, 3, 7, 5); //top

	quad(4, 6, 7, 5); //back

	quad(0, 2, 6, 4);

}

void rec() {
	glColor3f(0.0, 1.0, 0.0);
	ruad(0, 2, 3, 1);
}

void tri() {
	glColor3f(0.0, 0.0, 1.0);
	tuad(0, 1, 2);
	tuad(1, 3, 2);
	tuad(0, 4, 2);
	tuad(4, 3, 2);
}
// render

void render() {
	// points color

	glColor3f(0.0, 0.0, 0.0);



	

	// original

	glColor3f(0.0, 0.0, 0.0);
	rec();
	cube();
	tri();





}



// display registry

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();



	// viewing

	gluLookAt(1.9, 1.9, 9.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

		//gluLookAt(0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



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



// main program

void main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(100, 100);



	int windowHandle = glutCreateWindow("Athabasca University - Comp390 U6 S2 O3");

	glutSetWindow(windowHandle);



	glutDisplayFunc(display);

	glutReshapeFunc(reshape);



	initialize();



	glutMainLoop();

}