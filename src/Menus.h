/*
 * Menus.h
 *
 *  Created on: 09.01.2016
 *      Author: Maike
 */

#ifndef MENUS_H_
#define MENUS_H_

#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4

void processMenuEvents(int option) {

	switch (option) {
		case RED :

		case GREEN :

		case BLUE :

		case ORANGE :
			break;
	}
}

void createMenu() {

	int menu;

	// create the menu and
	// tell glut that "processMenuEvents" will
	// handle the events
	menu = glutCreateMenu(processMenuEvents);

	//add entries to our menu
	glutAddMenuEntry("Red",RED);
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("Orange",ORANGE);

	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}



#endif /* MENUS_H_ */
