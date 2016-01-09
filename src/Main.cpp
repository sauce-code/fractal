#include <GL/freeglut.h>

#include "MandelbrotSet.h"

#define WIDTH 800

#define HEIGHT 600

MandelbrotSet* ms = new MandelbrotSet(WIDTH, HEIGHT);

void reshape(int width, int height) {
	ms->setWidth(width);
	ms->setHeight(height);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	ms->calculate();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
//	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
//	GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowSize(WIDTH - 10, HEIGHT);
	glutCreateWindow("Mandelbrot Set");
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

//	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(mouse);

	glutMainLoop();

	return EXIT_FAILURE;
}
