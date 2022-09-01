/* Athabasca University

   Comp390 - Introduction to Computer Graphics
   Final Project Option 1
   @author: chukwufumnanya obi
   @date: july 30, 2022
   Program: The purpose of this program to combine 2d shapes with 3d shapes into composite object 
   */
#include "shape.h"

#include "gl/glut.h"

#include "feature.h"

#include <math.h>



#define PI 3.14159265

#define PIECES 20

shape::shape() {
	// set initial circle values

	radius = 1.0;

	stepRad = (2 * PI) / PIECES;

	stepDeg = 360.0 / PIECES;


	// unit circle initial points

	uCircle[0][0] = 0.0;

	uCircle[0][1] = 0.0;

	uCircle[0][2] = 0.0;


	// set points for circles and cylinders

	for (int i = 0; i <= PIECES; ++i) {

		uCircle[i + 1][0] = radius * cosf(stepRad * i);

		uCircle[i + 1][1] = 0.0;

		uCircle[i + 1][2] = radius * sinf(stepRad * i);


		uCylinder[2 * i][0] = uCircle[i + 1][0];

		uCylinder[2 * i][1] = uCircle[i + 1][1];

		uCylinder[2 * i][2] = uCircle[i + 1][2];


		uCylinder[2 * i + 1][0] = uCircle[i + 1][0];

		uCylinder[2 * i + 1][1] = uCircle[i + 1][1] + radius;

		uCylinder[2 * i + 1][2] = uCircle[i + 1][2];

	}
}
// draw a circle

void shape::drawCircle() {

	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < PIECES + 2; i++) {

		glVertex3fv(uCircle[i]);

	}

	glEnd();
}



// draw a unit square

void shape::drawSquare() {

	glBegin(GL_QUADS);

	glVertex3f(-0.5, 0.0, 0.5);

	glVertex3f(0.5, 0.0, 0.5);

	glVertex3f(0.5, 0.0, -0.5);

	glVertex3f(-0.5, 0.0, -0.5);

	glEnd();

}



// draw a unit cube

void shape::drawCube() {

	glMatrixMode(GL_MODELVIEW);

	drawSquare();


	glPushMatrix();

	glTranslatef(0.0, 1.0, 0.0);

	drawSquare();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0.5, 0.5, 0.0);

	glRotatef(90.0, 0.0, 0.0, 1.0);

	drawSquare();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-0.5, 0.5, 0.0);

	glRotatef(90.0, 0.0, 0.0, 1.0);

	drawSquare();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0.0, 0.5, 0.5);

	glRotatef(90.0, 1.0, 0.0, 0.0);

	drawSquare();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0.0, 0.5, -0.5);

	glRotatef(90.0, 1.0, 0.0, 0.0);

	drawSquare();

	glPopMatrix();

}

// draw a unit cylinder

void shape::drawCylinder() {

	glMatrixMode(GL_MODELVIEW);

	drawCircle();

	glPushMatrix();

	glTranslatef(0.0, radius, 0.0);

	drawCircle();

	glPopMatrix();

	glBegin(GL_QUADS);

	for (int i = 0; i < PIECES; ++i) {

		glVertex3fv(uCylinder[2 * i + 2]);

		glVertex3fv(uCylinder[2 * i + 3]);

		glVertex3fv(uCylinder[2 * i + 1]);

		glVertex3fv(uCylinder[2 * i]);

	}

	glEnd();

}

// draw a limb of 2 cylinders for the arm/leg, a sphere for the hand/foot

void shape::drawLimb(int base, int forelimb, int appendage) {

	glMatrixMode(GL_MODELVIEW);


	setMaterial(base);

	glPushMatrix();

	glScalef(0.5, 0.5, 0.5);

	drawCylinder();

	glPopMatrix();


	setMaterial(forelimb);

	glPushMatrix();

	glTranslatef(0.0, 0.5, 0.0);

	glScalef(0.5, 1.5, 0.5);

	drawCylinder();

	glPopMatrix();


	setMaterial(appendage);

	glPushMatrix();

	glTranslatef(0.0, 2.5, 0.0);

	glutSolidSphere(0.5, 20, 20);

	glPopMatrix();

}



// draw a body consisting of 3 cylinders for the trunk, and a sphere for the head

void shape::drawBody(int bottom, int belt, int torso, int head) {

	glMatrixMode(GL_MODELVIEW);

	setMaterial(bottom);

	glPushMatrix();

	glScalef(1.0, 0.4, 1.0);

	drawCylinder();

	glPopMatrix();


	setMaterial(belt);

	glPushMatrix();

	glTranslatef(0.0, 0.4, 0.0);

	glScalef(1.0, 0.1, 1.0);

	drawCylinder();

	glPopMatrix();


	setMaterial(torso);

	glPushMatrix();

	glTranslatef(0.0, 0.5, .0);

	glScalef(1.0, 1.5, 1.0);

	drawCylinder();

	glPopMatrix();


	setMaterial(head);

	glPushMatrix();

	glTranslatef(0.0, 3.0, 0.0);

	glutSolidSphere(1.0, 20, 20);

	glPopMatrix();

}

// creating farmer using the limbs and body methods
void shape::drawfarmer() {
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

	glTranslatef(0.0, 3.0, 0.0);

	drawBody(8, 12, 7, 4);


	// arms

	glPushMatrix();

	glTranslatef(1.0, 1.5, 0.0);

	glRotatef(-90.0, 0.0, 1.0, 0.0);

	glRotatef(-90.0, 0.0, 0.0, 1.0);

	drawLimb(7, 4, 4);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-1.0, 1.9, 0.0);

	glRotatef(-150.0, 1.0, 0.0, 0.0); //chg x --> z

	drawLimb(7, 4, 4);

	glPopMatrix();


	// legs

	glPushMatrix();

	glTranslatef(-0.5, 0.0, 0.0);

	glRotatef(160.0, 1.0, 0.0, 0.0);

	drawLimb(8, 8, 1);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0.5, 0.0, 0.0);

	glRotatef(-160.0, 1.0, 0.0, 0.0);

	drawLimb(8, 8, 1);

	glPopMatrix();




	glPopMatrix();

}

// method to create the front light using rectangle

void shape::frontlighht() {
	glBegin(GL_QUADS);

	glVertex3f(2.5, 1.0, -4.05);
	glVertex3f(1.5, 1.0, -4.05);
	glVertex3f(1.5, 2.0, -4.05);
	glVertex3f(2.5, 2.0, -4.05);

	glVertex3f(-2.5, 1.0, -4.05);
	glVertex3f(-1.5, 1.0, -4.05);
	glVertex3f(-1.5, 2.0, -4.05);
	glVertex3f(-2.5, 2.0, -4.05);
	glEnd();

}
// method to create the back light using rectangle
void shape::backlight() {
	glBegin(GL_QUADS);

	glVertex3f(2.5, 1.0, 4.05);
	glVertex3f(1.5, 1.0, 4.05);
	glVertex3f(1.5, 2.0, 4.05);
	glVertex3f(2.5, 2.0, 4.05);



	glVertex3f(-2.5, 1.0, 4.05);
	glVertex3f(-1.5, 1.0, 4.05);
	glVertex3f(-1.5, 2.0, 4.05);
	glVertex3f(-2.5, 2.0, 4.05);
	glEnd();
}
// the use of cubes and triangle to create the body of the car adding a window and using the cylinder for the tires
void shape::drawCar() {
	glMatrixMode(GL_MODELVIEW);


	glPushMatrix();

	glTranslatef(0.0, 1.0, 0.0);


	// draw lower body

	setMaterial(12);

	glPushMatrix();

	glScalef(5.0, 2.0, 8.0);

	drawCube();

	glPopMatrix();


	//front light 
	setMaterial(10);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	frontlighht();
	glPopMatrix();


	//back light
	setMaterial(9); //change front light
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	backlight();
	glPopMatrix();
	
	// draw upper body

	setMaterial(13);

	glPushMatrix();

	glTranslatef(0.0, 2.0, 0.0);

	glScalef(5.0, 2.0, 3.0);

	drawCube();

	glPopMatrix();

	// draw windshields

	setMaterial(6);

	glBegin(GL_QUADS);

	glVertex3f(-2.5, 2.0, 3.0);

	glVertex3f(2.5, 2.0, 3.0);

	glVertex3f(2.5, 4.0, 1.5);

	glVertex3f(-2.5, 4.0, 1.5);


	glVertex3f(-2.5, 2.0, -1.55);

	glVertex3f(2.5, 2.0, -1.55);

	glVertex3f(2.5, 4.0, -1.55);

	glVertex3f(-2.5, 4.0, -1.55);

	glEnd();
	



	glBegin(GL_TRIANGLES);

	glVertex3f(-2.5, 2.0, 3.0);

	glVertex3f(-2.5, 4.0, 1.5);

	glVertex3f(-2.5, 2.0, 1.5);


	glVertex3f(2.5, 2.0, 3.0);

	glVertex3f(2.5, 4.0, 1.5);

	glVertex3f(2.5, 2.0, 1.5);


	

	glEnd();
	glBegin(GL_QUADS);


	glVertex3f(2.53, 4.0, 1.3);

	glVertex3f(2.53, 2.0, 1.3);
	glVertex3f(2.53, 2.0, 0.5);

	glVertex3f(2.53, 4.0, 0.5);

	
	glVertex3f(2.53, 4.0, -1.3);

	glVertex3f(2.53, 2.0, -1.3);
	glVertex3f(2.53, 2.0, -0.5);

	glVertex3f(2.53, 4.0, -0.5);



	glVertex3f(-2.53, 4.0, 1.3);

	glVertex3f(-2.53, 2.0, 1.3);
	glVertex3f(-2.53, 2.0, 0.5);

	glVertex3f(-2.53, 4.0, 0.5);


	glVertex3f(-2.53, 4.0, -1.3);

	glVertex3f(-2.53, 2.0, -1.3);
	glVertex3f(-2.53, 2.0, -0.5);

	glVertex3f(-2.53, 4.0, -0.5);

	glEnd();

	// draw wheels

	setMaterial(0);

	glPushMatrix();

	glTranslatef(-2.5, 0.0, 4.0);

	glRotatef(90.0, 0.0, 0.0, 1.0);

	glScalef(1.0, 0.5, 1.0);

	drawCylinder();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(2.5, 0.0, 4.0);

	glRotatef(-90.0, 0.0, 0.0, 1.0);

	glScalef(1.0, 0.5, 1.0);

	drawCylinder();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-2.5, 0.0, -2.5);

	glRotatef(90.0, 0.0, 0.0, 1.0);

	glScalef(1.0, 0.5, 1.0);

	drawCylinder();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(2.5, 0.0, -2.5);

	glRotatef(-90.0, 0.0, 0.0, 1.0);

	glScalef(1.0, 0.5, 1.0);

	drawCylinder();

	glPopMatrix();

	glPopMatrix();
}
// create a house using cubes and triangles to create the body and roof of the house and rectangle for the windows and doors using cylinder to creat poles

void shape::drawhouse() {
	glMatrixMode(GL_MODELVIEW);

	//draw the main bulding
	setMaterial(13); //change to brown
	glPushMatrix();

	glScalef(20.0, 10.0, 20.0);

	drawCube();

	glPopMatrix();

	//drawroof
	setMaterial(12);

	glBegin(GL_QUAD_STRIP);

	glVertex3f(-12.0, 10.0, -13.0);

	glVertex3f(-12.0, 10.0, 13.0);

	glVertex3f(12.0, 10.0, -13.0);

	glVertex3f(12.0, 10.0, 13.0);

	glVertex3f(0.0, 15.0, -10.0);

	glVertex3f(0.0, 15.0, 13.0);

	glVertex3f(-10.0, 10.0, -10.0);

	glVertex3f(-10.0, 10.0, 13.0);

	glEnd();
	glBegin(GL_TRIANGLES);

	glVertex3f(-12.0, 10.0, 13.0);

	glVertex3f(12.0, 10.0, 13.0);

	glVertex3f(0.0, 15.0, 13.0);

	glVertex3f(-10.0, 10.0, -10.0);

	glVertex3f(12.0, 10.0, -13.0);

	glVertex3f(0.0, 15.0, -10.0);

	glEnd();
	// standing poles 
	setMaterial(12);
	glPushMatrix();

	glTranslatef(-9.0, 3.0, 12.0);

	glScalef(0.1, 7.0, 0.1);

	drawCylinder();
	
	glPopMatrix();
	glPushMatrix();

	glTranslatef(9.0, 3.0, 12.0);
	glScalef(0.1, 7.0, 0.1);

	drawCylinder();

	glPopMatrix();

	// draw doors

	setMaterial(12);

	glBegin(GL_QUADS);

	glVertex3f(-3.0, 0.0, 10.01);

	glVertex3f(0.0, 0.0, 10.01);

	glVertex3f(0.0, 5.0, 10.01);

	glVertex3f(-3.0, 5.0, 10.01);


	glVertex3f(0.0, 0.0, 10.01);

	glVertex3f(3.0, 0.0, 10.01);

	glVertex3f(3.0, 5.0, 10.01);

	glVertex3f(0.0, 5.0, 10.01);

	//windows
	setMaterial(6);

	glBegin(GL_QUADS);

	glVertex3f(-9.0, 5.0, 10.01);

	glVertex3f(-5.0, 5.0, 10.01);

	glVertex3f(-5.0, 7.0, 10.01);

	glVertex3f(-9.0, 7.0, 10.01);




	glVertex3f(9.0, 5.0, 10.01);

	glVertex3f(5.0, 5.0, 10.01);
	glVertex3f(5.0, 7.0, 10.01);

	glVertex3f(9.0, 7.0, 10.01);

	glEnd();
}
// create a barn using cubes and triangles to create the body and roof of the barn and rectangle for the windows and doors
void shape::drawBarn() {
	glMatrixMode(GL_MODELVIEW);

	//draw the main bulding
	setMaterial(3); //change to red
	glPushMatrix();

	glScalef(20.0, 10.0, 20.0);

	drawCube();

	glPopMatrix();

	//drawroof
	setMaterial(4);

	glBegin(GL_QUAD_STRIP);

	glVertex3f(-12.0, 10.0, -13.0);

	glVertex3f(-12.0, 10.0, 13.0);

	glVertex3f(12.0, 10.0, -13.0);

	glVertex3f(12.0, 10.0, 13.0);

	glVertex3f(0.0, 15.0, -10.0);

	glVertex3f(0.0, 15.0, 13.0);

	glVertex3f(-10.0, 10.0, -10.0);

	glVertex3f(-10.0, 10.0, 13.0);

	glEnd();
	glBegin(GL_TRIANGLES);

	glVertex3f(-12.0, 10.0, 13.0);

	glVertex3f(12.0, 10.0, 13.0);

	glVertex3f(0.0, 15.0, 13.0);

	glVertex3f(-10.0, 10.0, -10.0);

	glVertex3f(12.0, 10.0, -13.0);

	glVertex3f(0.0, 15.0, -10.0);

	glEnd();


	// draw doors

	setMaterial(12);

	glBegin(GL_QUADS);

	glVertex3f(-3.0, 0.0, 10.01);

	glVertex3f(0.0, 0.0, 10.01);

	glVertex3f(0.0, 5.0, 10.01);

	glVertex3f(-3.0, 5.0, 10.01);


	glVertex3f(0.0, 0.0, 10.01);

	glVertex3f(3.0, 0.0, 10.01);

	glVertex3f(3.0, 5.0, 10.01);

	glVertex3f(0.0, 5.0, 10.01);

	//windows
	setMaterial(6);

	glBegin(GL_QUADS);

	glVertex3f(-9.0, 5.0, 10.01);

	glVertex3f(-5.0, 5.0, 10.01);

	glVertex3f(-5.0, 7.0, 10.01);

	glVertex3f(-9.0, 7.0, 10.01);


	

	glVertex3f(9.0, 5.0, 10.01);

	glVertex3f(5.0, 5.0, 10.01);
	glVertex3f(5.0, 7.0, 10.01);

	glVertex3f(9.0, 7.0, 10.01);

	glEnd();
}