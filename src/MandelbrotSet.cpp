#include "MandelbrotSet.h"

MandelbrotSet::MandelbrotSet(unsigned int width, unsigned int height) {
	this->width = width;
	this->height = height;
	this->iterations = 50;
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
	bool isInside = true;
	for (unsigned int n = 0; n < iterations; n++) {
		if (z.getAbsolute() > 4) {
			isInside = false;
			break;
		}
		z = z.pow2() + c;
	}
	if (isInside) {
		glBegin(GL_POINTS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(x, y);
		glEnd();
	}
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
