#include <GL/freeglut.h>

#include "MandelbrotSet.h"
#include "JuliaSet.h"
#include "Menus.h"

#define WIDTH 800

#define HEIGHT 600

MandelbrotSet* ms = new MandelbrotSet(WIDTH, HEIGHT);
JuliaSet* js = new JuliaSet(WIDTH / 2, HEIGHT);
GLint WindowID1, WindowID2;

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
