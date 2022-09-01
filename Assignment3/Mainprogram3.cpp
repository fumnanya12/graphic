/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   Version 4


   The purpose of this program is to use the texturingroutine to display a background on the 3d houses done in TME 2 program 2


   TMe3 program3
   @author: chukwufumnanya obi

   @date: june 12 2022

  */



#include "windows.h"

#include "gl/glut.h"

#include "math.h"

#include <iostream>
#include <fstream>

#include <string>



using namespace std;
// image

GLubyte* image;

//unsigned char * l_texture;

GLubyte* l_texture;

BITMAPFILEHEADER fileheader;

BITMAPINFOHEADER infoheader;

RGBTRIPLE rgb;



GLuint texName;
/*
The function loads the image and stores the values used in texturing  


*/
void makeImage(void) {

	int i, j = 0;

	FILE* l_file;



	string fn = "side.bmp";

	const char* filename = fn.c_str();



	// open image file, return if error

	fopen_s(&l_file, filename, "rb");

	if (l_file == NULL) return;



	// read file header and header info

	fread(&fileheader, sizeof(fileheader), 1, l_file);

	fseek(l_file, sizeof(fileheader), SEEK_SET);

	fread(&infoheader, sizeof(infoheader), 1, l_file);



	// allocate space for the image file

	l_texture = (GLubyte*)malloc(infoheader.biWidth * infoheader.biHeight * 4);

	memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);



	// read da data

	j = 0;

	for (i = 0; i < infoheader.biWidth * infoheader.biHeight; i++)

	{

		fread(&rgb, sizeof(rgb), 1, l_file);



		l_texture[j + 0] = (GLubyte)rgb.rgbtRed; // Red component

		l_texture[j + 1] = (GLubyte)rgb.rgbtGreen; // Green component

		l_texture[j + 2] = (GLubyte)rgb.rgbtBlue; // Blue component

		l_texture[j + 3] = (GLubyte)255; // Alpha value

		j += 4; // Go to the next position

	}



	fclose(l_file); // Closes the file stream

}

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

	makeImage();

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);



	glGenTextures(1, &texName);

	glBindTexture(GL_TEXTURE_2D, texName);



	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);



	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,

		infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,

		l_texture);

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
	quad(4, 7, 6, 5);//left
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
	
	


	// enable texture

	glEnable(GL_TEXTURE_2D);
	/*The render method draws the orignal how and shows the tansalation of the house of the grey plane */
	
	/*This set the coordinate for the texturing where the image will be displayed */
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(0.0, 0.0); glVertex3f(8.0,-0.1,-8.0);

	glTexCoord2d(0.0, 1.0); glVertex3f(8.0, 10.0, -8.0);

	glTexCoord2d(1.0, 1.0); glVertex3f(8.0, 10.0, 8.0);

	glTexCoord2d(1.0, 0.0); glVertex3f(8.0, -0.1, 8.0);
	
	glTexCoord2d(0.0, 0.0); glVertex3f(8.0, -0.1, -8.0);

	glTexCoord2d(1.0, 0.0); glVertex3f(-8.0, -0.1, -8.0);

	glTexCoord2d(1.0, 1.0); glVertex3f(-8.0, 10.0, -8.0);

	glTexCoord2d(0.0, 1.0); glVertex3f(8.0, 10.0, -8.0);

	glEnd();
	
	// original

	glDisable(GL_TEXTURE_2D);
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

	gluLookAt(-10.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

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