/* Athabasca University

   Comp390 - Introduction to Computer Graphics

  

   The purpose of this program is to add a specular contribution to a lighting model that already
			includes both ambient and diffuse values. 




   @author: chukwufumnanya obi 

   @date: June 15, 2011


   */


#include <iostream>

#include <math.h>

#include "gl/glut.h"



#include "vector3.h"



using namespace std;



// viewer

vector3 viewer(0.0, 0.0, 80.0);



// square

vector3 wallNormal(0.0, 0.0, 1.0);



// colors

vector3 grey(0.75, 0.75, 0.75);

vector3 lightRed(0.75, 0.1, 0.1);



// lighting position

vector3 lightPosition(10, 10, 10);



// lighting elements

float ambient_coef = 0.3;

float diffuse_coef = 0.7;

float specular_coef = 0.8;



// initialize Sets the background colour of the display window.

void initialize() {

	// set background color

	glClearColor(0.5, 0.7, 0.5, 0.0);

}



// calculate local color  The colour is a sum of the ambient, diffuse, and specular contributing values.

// local color is intensity * base color

vector3 localColor(vector3 intersect, vector3 baseColor, vector3 normal) {

	// calculate unit vector

	vector3 origin = lightPosition.subtract(intersect);

	vector3 unitVec = origin.normalize();



	// calculate dot product

	float dotProd = unitVec.dot(normal);
	float specular_expo = 10.0;    // specular exponent

	/*
	calculate the specular conribute to add to the ambient and diffuse contri bution to get total illumiation or total colour  
	first we will need to calculate the refelction vector and find the dot product of the viewier vector
	With the result raise to the power of a specular exponet  then multipy it by the specular coefficient 
	*/
	vector3 reflection = normal.scalar((normal.scalar(2)).dot(unitVec)).subtract(unitVec);
	vector3 viewervector = viewer.normalize();
	float specularcontr = specular_coef * pow(reflection.dot(viewervector), specular_expo);
	// calculate intensity
	
	float ambientContr = ambient_coef;

	float diffuseContr = diffuse_coef * dotProd;

	float intensity = ambientContr + diffuseContr + specularcontr;



	if (intensity > 1.0) intensity = 1.0;



	float r = intensity * baseColor.x;

	float g = intensity * baseColor.y;

	float b = intensity * baseColor.z;



	return vector3(r, g, b);

}



// render  Creates the buch of squares that make up the one  square.


void render() {

	// render the square

	for (int m = -25; m < 25; m++) {

		for (int n = -25; n < 25; n++) {

			vector3 color = localColor(vector3(m, n, 0), lightRed, wallNormal);

			glColor3f(color.x, color.y, color.z);

			glRecti(m, n, m + 1, n + 1);

		}

	}

}



// display registry

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();



	//	gluLookAt(0.0, 40.0, 150.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	gluLookAt(viewer.x, viewer.y, viewer.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



	render();



	glutSwapBuffers();

}



// reshape registry Sets the viewing projection properties of the scene.


void reshape(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 250.0);

	glMatrixMode(GL_MODELVIEW);

}



// main program

void main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(100, 100);



	int windowHandle = glutCreateWindow("Athabasca University -TME3 program2 ");

	glutSetWindow(windowHandle);



	glutDisplayFunc(display);

	glutReshapeFunc(reshape);



	initialize();



	glutMainLoop();

}