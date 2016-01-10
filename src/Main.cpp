#include <GL/freeglut.h>

#include "MandelbrotSet.h"
#include "JuliaSet.h"

#define WIDTH 800
#define HEIGHT 600

#define ZOOM_IN 0
#define ZOOM_OUT 1
#define RESET 2
#define SHOW_JULIA 3
#define SAVE_IMAGE 4

MandelbrotSet* ms = new MandelbrotSet(WIDTH, HEIGHT);
JuliaSet* js = new JuliaSet(WIDTH / 2, HEIGHT);
GLint WindowID1, WindowID2;
int mouseX, mouseY;

void processMenuEvents(int option) {
	MandelbrotSet* set;

	if (glutGetWindow() == WindowID1) {
		set = ms;
	} else {
		set = js;
	}

	float xMapped = 0;
	float yMapped = 0;

	switch (option) {
	case ZOOM_IN:
		printf("Zoom to %i|%i", mouseX, mouseY);
		set->zoom(mouseX, mouseY);
		set->calculate();
		glutPostRedisplay();
		break;
	case ZOOM_OUT:
		printf("Zoom out");
		set->zoomOut(mouseX, mouseY);
		set->calculate();
		glutPostRedisplay();
		break;
	case RESET:
		set->reset();
		set->calculate();
		glutPostRedisplay();
		break;
	case SHOW_JULIA:
		glutSetWindow(WindowID2);
		xMapped = js->min.r + ((js->max.r - js->min.r) / WIDTH) * mouseX;
		yMapped = js->min.i + ((js->max.i - js->min.i) / HEIGHT) * mouseY;
		js->k.r = xMapped;
		js->k.i = yMapped;
		js->calculate();
		printf("This is the Julia Set for c  %f", xMapped);
		printf(" + %f", yMapped);
		printf("i");
		glutPostRedisplay();
		glutSetWindow(WindowID1);
		break;
	case SAVE_IMAGE: // TODO
		printf("Image Saved as");
		break;
	}
}

void processColorMenu(int option) {
	MandelbrotSet* set;

	if (glutGetWindow() == WindowID1) {
		set = ms;
	} else {
		set = js;
	}

	switch (option) {
	case 0:
		set->setColorMode(0);
		break;
	case 1:
		set->setColorMode(1);
		break;
	case 2:
		set->setColorMode(2);
		break;
	case 3:
		set->setColorMode(3);
		break;
	case 4:
		set->setColorMode(4);
		break;
	default:
		set->setColorMode(2);
		break;
	}

	set->calculate();
	glutPostRedisplay();

}

void createMenuMandelbrot() {
	int menu, colorSubmenu;

	colorSubmenu = glutCreateMenu(processColorMenu);
	glutAddMenuEntry("Red & White", 0);
	glutAddMenuEntry("RGB", 1);
	glutAddMenuEntry("Flowers", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Greyscale", 4);

	menu = glutCreateMenu(processMenuEvents);
	//add entries to our menu
	glutAddMenuEntry("Zoom in", ZOOM_IN);
	glutAddMenuEntry("Zoom out", ZOOM_OUT);
	glutAddMenuEntry("Reset", RESET);
	if (glutGetWindow() == WindowID1){
		glutAddMenuEntry("Show Julia", SHOW_JULIA);
	}
	glutAddSubMenu("Change Colors", colorSubmenu);
	glutAddMenuEntry("Save Image", SAVE_IMAGE);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void reshapeMandelbrot(int width, int height) {
	glutReshapeWindow(WIDTH - 10, HEIGHT);
//	ms->setWidth(width);
//	ms->setHeight(height);
}

void reshapeJulia(int width, int height) {
	glutReshapeWindow((WIDTH / 2) - 10, HEIGHT);
//	js->setWidth(width);
//	js->setHeight(height);
}

void displayMandelbrot() {
	glClear(GL_COLOR_BUFFER_BIT);

	ms->calculate();

	glFlush();
}

void displayJulia() {
	glClear(GL_COLOR_BUFFER_BIT);

	js->calculate();

	glFlush();
}

void mouseMandelbrot(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		ms->zoom(x, y);
		ms->calculate();
		glutPostRedisplay();
	}
}

void mousePassiveMandelbrot(int x, int y) {
	mouseX = x;
	mouseY = y;
}

void mouseJulia(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		js->zoom(x, y);
		js->calculate();
		glutPostRedisplay();
	}
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

// first window for Mandebrot Sets
	glutInitWindowSize(WIDTH - 10, HEIGHT);
	glutInitWindowPosition(50, 20);
	WindowID1 = glutCreateWindow("Mandelbrot Set");
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutReshapeFunc(reshapeMandelbrot);
	glutDisplayFunc(displayMandelbrot);
	glutMouseFunc(mouseMandelbrot);
	glutPassiveMotionFunc(mousePassiveMandelbrot);
	createMenuMandelbrot();

	// second Window for Julia Sets
	glutInitWindowSize((WIDTH / 2) - 10, HEIGHT);
	glutInitWindowPosition(900, 20);
	WindowID2 = glutCreateWindow("Julia Set");
	gluOrtho2D(0.0, (WIDTH / 2), 0.0, HEIGHT);
	glutReshapeFunc(reshapeJulia);
	glutDisplayFunc(displayJulia);
	glutMouseFunc(mouseJulia);
	glutPassiveMotionFunc(mousePassiveMandelbrot);
	createMenuMandelbrot();

	glutMainLoop();

	return EXIT_FAILURE;
}
