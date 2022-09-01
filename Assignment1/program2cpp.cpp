/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4


   3D transformation matrix


   TMe2 program2
   @author: chukwufumnanya obi

   @date: june 12 2022


*/


 

#include <iostream>

#include "gl/glut.h"



using namespace std;



// vertex array

typedef GLint vertex3[3];
typedef GLfloat vertex4[4];



vertex3 pt[8] = { { 1.0, 1.0, 1.0 }, { 1.0, 0.0, 1.0 }, { 0.0, 0.0, 1.0 }, { 0.0, 1.0, 1.0} ,{ -0.0, 0.0, 0.0 },{ -0.0, 1.0, 0.0 },{1.0,1.0,0.0},{1.0,0.0,0.0} }; //coordinate for the cube

vertex3 st[4] = { {8.0,-0.1,8.0},{8.0,-0.1,-8.0},{-8.0,-0.1,8.0},{-8.0,-0.1,-8.0} }; //coordinate for the GREY RECTANGLE
vertex3 btt[4] = { {2.0,0.0,2.0},{-1.0,0.0,2.0},{-1.0,0.0,-1.0},{2,0.0,-1.0} };//coordinate for the green rec
vertex4 tr[5] = { {0.5, 1.5, 0.5}, {1.2, 1.0, 1.2}, {-0.2, 1.0, 1.2},{-0.5, 1.0, -0.2},{0.5, 1.0, -0.5} }; //coordinate for the TRANGLE


// initialize

void initialize() {

	// set background color

	glClearColor(1.0, 1.0, 1.0, 0.0);
	
}







// adapt from Hearn & Baker, ed. 4, p. 77
//draw the red cube

void quad(GLint n1, GLint n2, GLint n3, GLint n4) {

	glBegin(GL_QUADS);

	glVertex3iv(pt[n1]);

	glVertex3iv(pt[n2]);

	glVertex3iv(pt[n3]);

	glVertex3iv(pt[n4]);

	glEnd();

}
// draw the grey rectangle 
void ruad(GLint n1, GLint n2, GLint n3, GLint n4) {
	glBegin(GL_QUADS);

	glVertex3iv(st[n1]);

	glVertex3iv(st[n2]);

	glVertex3iv(st[n3]);

	glVertex3iv(st[n4]);

	glEnd();
}
// draw the green rectangle 

void smallruad(GLint n1, GLint n2, GLint n3, GLint n4) {
	glBegin(GL_QUADS);

	glVertex3iv(btt[n1]);

	glVertex3iv(btt[n2]);

	glVertex3iv(btt[n3]);

	glVertex3iv(btt[n4]);

	glEnd();
}
// draw the triangle  rectangle 

void tuad(GLint n1, GLint n2, GLint n3) {

	glBegin(GL_TRIANGLES);

	glVertex3fv(tr[n1]);

	glVertex3fv(tr[n2]);

	glVertex3fv(tr[n3]);


	glEnd();
}
//draw the red cube
void cube() {
	glColor3f(1.0, 0.0, 0.0); //set the red colour

	quad(0, 1, 2, 3); // right
	quad(2, 4, 5, 3);//front
	quad(4,7, 6, 5);//left
	quad(6, 7, 1, 0);
	

}

void rec() {
	glColor3f(0.7, 0.7, 0.7); //set the grey colour

	ruad(0, 2, 3, 1);
}
void srec() {
	glColor3f(0.0, 1.0, 0.0); //set the green  colour

	smallruad(0, 1, 2, 3);
}
void Tri() {
	glColor3f(0.0, 0.0, 1.0); //set the bule colour
	tuad(0, 1, 2);
	tuad(3, 0, 2);
	tuad(3, 4, 0);
	tuad(1, 4, 0);
	
}
//draws the complete house 
void createhouse() {
	srec();
	cube();

	Tri();
}
// render

void render() {
	/*The render method draws the orignal how and shows the tansalation of the house of the grey plane */
	

	// original


	rec();
	createhouse();

	//top left
	glPushMatrix();
	glTranslatef(-5.0, 0.0, -5.0);

	//glRotatef(45.0, 0.0, 1.0, 0.0);

	glScalef(1.0, 1.5, 2.5);

	createhouse();

	glPopMatrix();

	//behind right
	glPushMatrix();
	glTranslatef(6.0, 0.0, 5.0);

	glRotatef(-45.0, 0.0, 1.0, 0.0);

	glScalef(1.0, 1.5, 1.0);

	createhouse();

	glPopMatrix();

	//behind
	glPushMatrix();
	glTranslatef(6.0, 0.0, 1.0);
	
	
	createhouse();

	glPopMatrix();
	//behind left
	glPushMatrix();
	glTranslatef(5.0, 0.0, -5.0);



	createhouse();

	glPopMatrix();
	
	//left
	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.0);



	createhouse();
	
	glPopMatrix();
	//right
	glPushMatrix();
	glTranslatef(-0.0, 0.0, 5.0);

	

	createhouse();

	glPopMatrix();
	//draw top right 
	glPushMatrix();
	glTranslatef(-5.0, 0.0, 5.0);

	glScalef(1.0, 1.0, -1.5);

	createhouse();

	glPopMatrix();
}



// display registry

void display(void) {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();



	// viewing

	gluLookAt(-12.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

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