#include <GL/freeglut.h>

#include "MandelbrotSet.h"

MandelbrotSet* ms = new MandelbrotSet(800, 600);

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(40, 40);
	glEnd();
	ms->calculate();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
//	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
//	GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowSize(800, 600);
	glutCreateWindow("Mandelbrot Set");
	gluOrtho2D(0.0, 800, 0.0, 600);
	glClearColor(0.0, 1.0, 1.0, 1.0);

	glutDisplayFunc(display);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(mouse);

	glutMainLoop();

	return EXIT_FAILURE;
}
