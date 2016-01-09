#include "MandelbrotSet.h"

MandelbrotSet::MandelbrotSet(unsigned int width, unsigned int height) {
	this->width = width;
	this->height = height;
	this->iterations = 50;
	this->colorMode = 0;
	min.r = -2.0;
	min.i = -1.2;
	max.r = 1.0;
	max.i = min.i + (max.r - min.r) * height / width;
	factor.r = (max.r - min.r) / (width - 1);
	factor.i = (max.i - min.i) / (height - 1);
}

MandelbrotSet::~MandelbrotSet() {
	// TODO Auto-generated destructor stub
}

void MandelbrotSet::calculate() {
	complex c;
	for (unsigned int y = 0; y < height; y++) {
		c.i = max.i - y * factor.i;
		for (unsigned int x = 0; x < width; x++) {
			c.r = min.r + x * factor.r;
			draw(x, y, c);
		}
	}
}

void MandelbrotSet::draw(unsigned int x, unsigned int y, complex c) {
	complex z = c;
	unsigned int n = 0;

	for (n = 0; n < iterations; n++) {

		if (z.getAbsolute() > 4) {
			break;
		}
		z = z.pow2() + c;
	}

	glBegin(GL_POINTS);
	float* yolo = getColor(n);
	glColor3f(yolo[0], yolo[1], yolo[2]);
	glVertex2i(x, y);
	glEnd();
}

float* MandelbrotSet::getColor(unsigned int n) {
	float* array = new float[3];
	float step = 1.0 / iterations;
	float redValue = 0.0;

	switch (colorMode) {
	case 0: // all red
		redValue = 2 * n * step;
		if (n < iterations / 2 - 1) {
			array[1] = 0.0;
			array[2] = 0.0;
		} else if (n < iterations - 2){
			array[1] = 1.0;
			array[2] = 1.0;
		} else {
			redValue = 0.0;
			array[1] = 0.0;
			array[2] = 0.0;
		}
		array[0] = redValue;
		break;
	default:
		array[0] = 1.0;
		array[1] = 0.0;
		array[2] = 0.0;
	}

	return array;

}

void MandelbrotSet::setWidth(unsigned int width) {
	this->width = width;
}

void MandelbrotSet::setHeight(unsigned int Height) {
	this->height = height;
}

void MandelbrotSet::setIterations(unsigned int iterations) {
	this->iterations = iterations;
}

void MandelbrotSet::zoom(unsigned int x, unsigned int y) {
	// map x & y to function
	float xMapped = min.r + ((max.r - min.r) / width) * x;
	float yMapped = min.i + ((max.i - min.i) / height) * y;

	// make width and height in half
	float newWidth = (max.r - min.r) / 2;
	float newHeight = (max.i - min.i) / 2;

	// x & y as new middle point
	min.r = xMapped - (newWidth / 2);
	max.r = xMapped + (newWidth / 2);
	min.i = yMapped - (newHeight / 2);
	max.i = min.i + (max.r - min.r) * newHeight / newWidth;

	factor.r = (max.r - min.r) / (width - 1);
	factor.i = (max.i - min.i) / (height - 1);

	iterations += 10;
}
