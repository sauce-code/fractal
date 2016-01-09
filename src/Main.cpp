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
	float xMapped = 0;
	float yMapped = 0;

	switch (option) {
	case ZOOM_IN:
		printf("Zoom to %i|%i", mouseX, mouseY);
		ms->zoom(mouseX, mouseY);
		ms->calculate();
		glutPostRedisplay();
		break;
	case ZOOM_OUT: // TODO
		printf("Zoom out");
		break;
	case RESET: // TODO
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

	switch (option) {
	case 0:
		ms->colorMode = 0;
		break;
	case 1:
		ms->colorMode = 1;
		break;
	case 2:
		ms->colorMode = 2;
		break;
	}

	ms->calculate();
	glutPostRedisplay();

}

void createMenu() {

	int menu, colorSubmenu;

	colorSubmenu = glutCreateMenu(processColorMenu);
	glutAddMenuEntry("Red & White", 0);
	glutAddMenuEntry("RGB", 1);
	glutAddMenuEntry("flowers", 2);

	menu = glutCreateMenu(processMenuEvents);
	//add entries to our menu
	glutAddMenuEntry("Zoom in", ZOOM_IN);
	glutAddMenuEntry("Zoom out", ZOOM_OUT);
	glutAddMenuEntry("Reset", RESET);
	glutAddMenuEntry("Show Julia", SHOW_JULIA);
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
//	} else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//
//		float xMapped = js->min.r + ((js->max.r - js->min.r) / WIDTH) * x;
//		float yMapped = js->min.i + ((js->max.i - js->min.i) / HEIGHT) * y;
//		js->k.r = xMapped;
//		js->k.i = yMapped;
//		js->calculate();
//		printf("This is the Julia Set for c  %f", xMapped);
//		printf(" + %f", yMapped);
//		printf("i");
//		glutSetWindow(WindowID2);
//		glutPostRedisplay();
//		glutSetWindow(WindowID1);
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

	createMenu();

	// second Window for Julia Sets
	glutInitWindowSize((WIDTH / 2) - 10, HEIGHT);
	glutInitWindowPosition(900, 20);
	WindowID2 = glutCreateWindow("Julia Set");
	gluOrtho2D(0.0, (WIDTH / 2), 0.0, HEIGHT);
	glutReshapeFunc(reshapeJulia);
	glutDisplayFunc(displayJulia);
	glutMouseFunc(mouseJulia);

	glutMainLoop();

	return EXIT_FAILURE;
}
