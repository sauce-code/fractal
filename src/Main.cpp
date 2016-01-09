#include <GL/freeglut.h>

#include "MandelbrotSet.h"
#include "JuliaSet.h"

#define WIDTH 800

#define HEIGHT 600

MandelbrotSet* ms = new MandelbrotSet(WIDTH, HEIGHT);
JuliaSet* js = new JuliaSet(WIDTH, HEIGHT);

void reshape(int width, int height) {
	ms->setWidth(width);
	ms->setHeight(height);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	ms->calculate();

	glFlush();
}

void displayJulia() {
	glClear(GL_COLOR_BUFFER_BIT);

	js->calculate();

	glFlush();
}

void mouse(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		ms->zoom(x, y);
		ms->calculate();
		glutPostRedisplay();
	}
}

int main(int argc, char** argv) {
	GLint WindowID1, WindowID2;

	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	// first window for Mandebrot Sets
	glutInitWindowSize(WIDTH- 10, HEIGHT);
	glutInitWindowPosition(50, 20);
	WindowID1 = glutCreateWindow("Mandelbrot Set");
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);

	// second Window for Julia Sets
	glutInitWindowSize(WIDTH /2, HEIGHT);
	glutInitWindowPosition(900, 20);
	WindowID2 = glutCreateWindow("Julia Set");
	gluOrtho2D(0.0, WIDTH / 2, 0.0, HEIGHT);
	glutDisplayFunc(displayJulia);


	glutMainLoop();

	return EXIT_FAILURE;
}
