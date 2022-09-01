/* Athabasca University

   Comp390 - Introduction to Computer Graphics

   
	The purpose of this program is to create a menu that is used with the mouse to demostrate the use of the lighing model 
	by allowing changes to the colour of the light the material properties and the lighing elements
	a sphere is used by displaying 3 lights and the menu is able to make changes to these light on the sphere


   @author: chukwufumnanya obi

   @date: june 15 2022

*/



#include "gl/glut.h"
//Assigne integer to colours
#define WHITE 0

#define RED 1

#define BLUE 2

#define GREEN 3


//create menus
GLint Menu_light0, Menu_light1, Menu_light2, Menu_material, Menu_element;

//store the state of the light in an array
GLint light_state[] = { WHITE, RED, BLUE, GREEN};

// lights

GLfloat light_position0[] = { -10.0, 10.0, 10.0, 0.0 };

GLfloat light_position1[] = { 10.0, 10.0, 10.0, 0.0 };

 GLfloat light_position2[] = { -10.0,-10.0,-10.0,0.0 };   // add some numbers here



GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat red_light[] = { 1.0, 0.0, 0.0, 1.0 };

 GLfloat blue_light[] = { 0.0, 0.0, 1.0, 1.0 };	// maybe useful
 GLfloat green_light[] = { 0.2, 1.0, 0.2, 1.0 };
 GLfloat yellow_light[] = { 1.0, 1.0, 0.0, 1.0 };
 GLfloat black_light[] = { 0.0, 0.0, 0.0, 1.0 };
 GLfloat cyan_light[] = { 0.0, 1.0, 1.0, 1.0 };

GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };



// some surface materials parameters

	// gold

GLfloat gold_ambient[] = { 0.24725, 0.1995, 0.0745, 1.0 };

GLfloat gold_diffuse[] = { 0.75164, 0.60648, 0.22658, 1.0 };

GLfloat gold_specular[] = { 0.628281, 0.555802, 0.366065, 1.0 };

GLfloat gold_shininess[] = { 51.2 };

//silver
GLfloat silver_ambient[] = { 0.19225, 0.19225, 0.19225, 1.0 };

GLfloat silver_diffuse[] = { 0.50754, 0.50754, 0.50754, 1.0 };

GLfloat silver_specular[] = { 0.508273, 0.508273, 0.508273, 1.0 };

GLfloat silver_shininess[] = { 51.2 };

// copper

GLfloat copper_ambient[] = { 0.2295, 0.08825, 0.0275, 1.0 };

GLfloat copper_diffuse[] = { 0.5508, 0.2118, 0.066, 1.0 };

GLfloat copper_specular[] = { 0.580594, 0.223257, 0.0695701, 1.0 };

GLfloat copper_shininess[] = { 51.2 };



// initialize

void initialize() {

	// set background color

	glClearColor(0.5, 0.7, 0.5, 0.0);



	// enable depth test

	glEnable(GL_DEPTH_TEST);



	// enable lighting

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

	glEnable(GL_LIGHT1);

	 glEnable(GL_LIGHT2);			// don't forget to enable light 2



	// set lights

	// light 0

	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);

	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);



	// light 1

	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, red_light);

	glLightfv(GL_LIGHT1, GL_SPECULAR, red_light);



	// light 2

	 glLightfv(GL_LIGHT2, GL_POSITION, light_position2);

	 glLightfv(GL_LIGHT2, GL_DIFFUSE, blue_light);

	 glLightfv(GL_LIGHT2, GL_SPECULAR, blue_light);



	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

}



// render create trhe sphere 

void render() {

	glColor3f(0.5, 0.5, 0.5);

	glPushMatrix();



	glutSolidSphere(1.0, 64, 10);

	glPopMatrix();

}



// display registry

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();



	gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



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
/*function used for the main menu function 
it also allows th user exit the program when they are done 
*/
void mainMenu(GLint input) {
	if (input == 0)

		exit(0);
}
/* this is the submenu for light1 which allows the user to change the light and also turn of the light 
*/
void light1menu(GLint input) {
	//enables the off light
	if (input == 0) {
		glDisable(GL_LIGHT0);
	}
	//changes the light to white
	else if (input == 1) {
		glEnable(GL_LIGHT0);

		light_state[0] = WHITE;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

	}
	else if (input == 2) {
		//changes the light to red
		glEnable(GL_LIGHT0);

		light_state[0] = RED;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, red_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, red_light);


	}
	//changes the light to blue
	else if (input == 3) {

		glEnable(GL_LIGHT0);

		light_state[0] = BLUE;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, blue_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, blue_light);


	}
	//changes the light to Green
	else if (input == 4) {

		glEnable(GL_LIGHT0);

		light_state[0] = GREEN;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, green_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, green_light);

	}

}
/* this is the submenu for light2 which allows the user to change the light and also turn of the light
*/
void light2menu(GLint input) {
	//enables the off light
	if (input == 0) {
		glDisable(GL_LIGHT0);
	}
	//changes the light to white
	else if (input == 1) {
		glEnable(GL_LIGHT0);

		light_state[1] = WHITE;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

	}
	else if (input == 2) {
		//changes the light to red
		glEnable(GL_LIGHT0);

		light_state[1] = RED;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, red_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, red_light);



	}
	//changes the light to blue
	else if (input == 3) {

		glEnable(GL_LIGHT0);

		light_state[1] = BLUE;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, blue_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, blue_light);


	}
	//changes the light to Green
	else if (input == 4) {

		glEnable(GL_LIGHT0);

		light_state[1] = GREEN;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, green_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, green_light);

	}

}
/* this is the submenu for light3 which allows the user to change the light and also turn of the light
*/
void light3menu(GLint input) {
	//enables the off light
	if (input == 0) {
		glDisable(GL_LIGHT0);
	}
	//changes the light to white
	else if (input == 1) {
		glEnable(GL_LIGHT0);

		light_state[2] = WHITE;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);


	}
	else if (input == 2) {
		//changes the light to red
		glEnable(GL_LIGHT0);

		light_state[2] = RED;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, red_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, red_light);


	}
	//changes the light to blue
	else if (input == 3) {

		glEnable(GL_LIGHT0);

		light_state[2] = BLUE;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, blue_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, blue_light);


	}
	//changes the light to Green
	else if (input == 4) {

		glEnable(GL_LIGHT0);

		light_state[2] = GREEN;

		glLightfv(GL_LIGHT0, GL_DIFFUSE, green_light);

		glLightfv(GL_LIGHT0, GL_SPECULAR, green_light);

	}

}
/* this is the submenu for material properties  which allows the user to change the properties of the sphere to gold silver or copper 
*/
void materialmenu(GLint input) {
	if (input == 1) {
		glMaterialfv(GL_FRONT, GL_SPECULAR, gold_specular);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, gold_diffuse);

		glMaterialfv(GL_FRONT, GL_AMBIENT, gold_ambient);

		glMaterialfv(GL_FRONT, GL_SHININESS, gold_shininess);
	}
	else if (input == 2) {
		glMaterialfv(GL_FRONT, GL_SPECULAR, silver_specular);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, silver_diffuse);

		glMaterialfv(GL_FRONT, GL_AMBIENT, silver_ambient);

		glMaterialfv(GL_FRONT, GL_SHININESS, silver_shininess);

	}
	else if (input == 3) {
		glMaterialfv(GL_FRONT, GL_SPECULAR, copper_specular);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, copper_diffuse);

		glMaterialfv(GL_FRONT, GL_AMBIENT, copper_ambient);

		glMaterialfv(GL_FRONT, GL_SHININESS, copper_shininess);

	}

}
/* this is the submenu for light element  properties  which allows the user to change the lighr element of the sphere 
*/
void elementmenu(GLint input) {
	if (input == 0) {
		glDisable(GL_LIGHT0);

		glDisable(GL_LIGHT1);

		glDisable(GL_LIGHT2);

	}
	else if (input == 1) {
		glEnable(GL_LIGHT0);

		glEnable(GL_LIGHT1);

		glEnable(GL_LIGHT2);


		glLightfv(GL_LIGHT0, GL_SPECULAR, black_light);

		glLightfv(GL_LIGHT1, GL_SPECULAR, black_light);

		glLightfv(GL_LIGHT2, GL_SPECULAR, black_light);
	}
	else if (input == 2) {

		glEnable(GL_LIGHT0);

		glEnable(GL_LIGHT1);

		glEnable(GL_LIGHT2);


		glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

		glLightfv(GL_LIGHT1, GL_SPECULAR, red_light);

		glLightfv(GL_LIGHT2, GL_SPECULAR, blue_light);
	}
}
/*This function allows for display for the menu and give the ability to interact with the mouse to make changes to the light*/
void createMenu() {

	// create light1 submenu

	Menu_light0 = glutCreateMenu(light1menu);

	glutAddMenuEntry("Off", 0);

	glutAddMenuEntry("White Light", 1);

	glutAddMenuEntry("Red Light", 2);

	glutAddMenuEntry("Blue Light", 3);

	glutAddMenuEntry("Green Light", 4);


	// create light 2 submenu

	Menu_light1 = glutCreateMenu(light2menu);

	glutAddMenuEntry("Off", 0);

	glutAddMenuEntry("White Light", 1);

	glutAddMenuEntry("Red Light", 2);

	glutAddMenuEntry("Blue Light", 3);

	glutAddMenuEntry("Green Light", 4);


	// create light3 submenu

	Menu_light2 = glutCreateMenu(light3menu);

	glutAddMenuEntry("Off", 0);

	glutAddMenuEntry("White Light", 1);

	glutAddMenuEntry("Red Light", 2);

	glutAddMenuEntry("Blue Light", 3);

	glutAddMenuEntry("Green Light", 4);


	// create materials submenu

	Menu_material = glutCreateMenu(materialmenu);

	glutAddMenuEntry("Gold", 1);

	glutAddMenuEntry("Silver", 2);

	glutAddMenuEntry("Copper", 3);


	// create elements submenu

	Menu_element = glutCreateMenu(elementmenu);

	glutAddMenuEntry("Ambient only", 0);

	glutAddMenuEntry("Ambient and Diffuse", 1);

	glutAddMenuEntry("Ambient, Diffuse and Specular", 2);


	// create main menu
	glutCreateMenu(mainMenu);

	glutAddSubMenu("Light0", Menu_light0);

	glutAddSubMenu("Light1", Menu_light1);

	glutAddSubMenu("Light2", Menu_light2);

	glutAddSubMenu("Material Properties", Menu_material);

	glutAddSubMenu("Light Elements", Menu_element);

	glutAddMenuEntry("Quit", 0);


	// set menu to activate with right mouse click

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}




// main program

void main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(100, 100);



	int windowHandle = glutCreateWindow("Athabasca University - Comp390 U8 S2 O1");

	glutSetWindow(windowHandle);



	glutDisplayFunc(display);

	glutReshapeFunc(reshape);



	initialize();

	createMenu();

	glutMainLoop();

}