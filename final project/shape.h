#ifndef _OBJECTS_H_

#define _OBJECTS_H_



#include "gl/glut.h"
class shape {
private:

	GLuint sphere, cylinder, arm;

	float radius, stepRad, stepDeg;

	float uCircle[22][3];

	float uCylinder[42][3];

	void drawCircle();

	void drawSquare();

	void drawCube();
	void frontlighht();
	void backlight();
	void drawCylinder();

	void drawLimb(int base, int extend, int appendage);

	void drawBody(int bottom, int belt, int torso, int head);


public:

	shape();

	void drawfarmer();

	void drawCar();

	void drawanimal();

	void drawhouse();
	void drawBarn();

};
#endif  // _OBJECTS_H_

