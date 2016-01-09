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

void mouse(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		ms->zoom(x, y);
		ms->calculate();
		glutPostRedisplay();
	}

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowSize(WIDTH - 10, HEIGHT);
	glutCreateWindow("Mandelbrot Set");
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

//	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(mouse);

	glutMainLoop();

	return EXIT_FAILURE;
}
