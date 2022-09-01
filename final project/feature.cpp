/* Athabasca University
   
   Comp390 - Introduction to Computer Graphics
   Final Project Option 1
   @author: chukwufumnanya obi
   @date: july 30, 2022
   Program: The purpose of this program is to set the materials properties
   */
#include "feature.h"

//setmaterial determines the properties of the obejct set by an int value
void setMaterial(int selection) {

	switch (selection) {

		// black dull

	case 0:

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, black_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, black_shininess);

		break;


		// black shiny

	case 1:

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, black_diffuse);

		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 99.0);

		break;


		// white shiny

	case 2:

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, white_shininess);

		break;


		// red

	case 3:
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, red_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, red_shininess);
		break;


		// rooof

	case 4:
		
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, roof_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, roof_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, roof_shininess);
	
		break;


		// farmer

	case 5:
		
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, farmer_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, farmer_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, farmer_shininess);
		
		break;


		// windows

	case 6:

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, window_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, window_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, window_shininess);

		break;


		// yellow shirt

	case 7:
		
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, shirt_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, shirt_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shirt_shininess);
		
		break;


		// navy pants

	case 8:
		
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, pants_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, pants_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, pants_shininess);
		
		break;


		// orange light

	case 9:


		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, orange_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, orange_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, orange_shininess);

		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, orange_emissive);

		break;


		// red light

	case 10:

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, red_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, red_shininess);

		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, red_emissive);

		break;


		//  dark brown 

	case 12:
	

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, door_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, door_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, door_shininess);
	
		break;


		// light brown 

	case 13:
		

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, house_specular); 

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, house_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, house_shininess);
		
		break;


		// green grass

	case 14:

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grass_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, grass_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, grass_shininess);

		break;


		

	


		// road black

	case 15:

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, road_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, road_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, road_shininess);

		break;


		// white crosslane

	case 16:
		

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, crosslane_specular);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, crosslane_diffuse);

		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, crosslane_shininess);
		
		break;
	}
	// set emission properties for all but the red/orange lights

	if (selection != 9 || selection != 10)
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black_emissive);

}