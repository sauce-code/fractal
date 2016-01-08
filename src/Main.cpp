#include <GL/freeglut.h>

void green(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("green");

	glutDisplayFunc(green);
	glClearColor(0.0, 1.0, 0.0, 1.0);

	glutMainLoop();
	return (0);
}
