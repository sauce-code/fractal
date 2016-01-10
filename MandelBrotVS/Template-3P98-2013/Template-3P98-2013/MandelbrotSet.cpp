#include "MandelbrotSet.h"

MandelbrotSet::MandelbrotSet(unsigned int width, unsigned int height) {
	this->width = width;
	this->height = height;
	this->iterations = 128;
	this->colorMode = 2;
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
	float step = 1.0f / iterations;
	float red = 0.0;
	float green = 0.0;
	float blue = 0.0;

	switch (colorMode) {
	case 0: // all red
		red = 2 * n * step;
		if (n < iterations / 2 - 1) {
			green = 0.0;
			blue = 0.0;
		}
		else if (n < iterations - 2) {
			green = 1.0;
			blue = 1.0;
		}
		else {
			red = 0.0;
			green = 0.0;
			blue = 0.0;
		}
		break;
	case 1:
		if (n < iterations / 3) {
			red = 3.0f * n * step;
		}
		else if (n < iterations / 3 * 2) {
			//			red = 1.0f - 3.0f / 2.0f * n * step;
			green = 3.0f / 2.0f * n * step;
		}
		else if (n < iterations - 1) {
			//			green = 1.0f - n * step;
			blue = n * step;
		}
		break;
	case 2:
		if (n == iterations) {

		}
		else if (n < 64) {
			red = n * 2.0f / 256.0f;
		}
		else if (n < 128) {
			red = ((((n - 64.0f) * 128.0f) / 126.0f) + 128.0f) / 256.0f;
		}
		else if (n < 265) {
			red = ((((n - 128.0f) * 62.0f) / 127.0f) + 193.0f) / 256.0f;
		}
		else if (n < 512) {
			red = 1.0f;
			green = ((((n - 256.0f) * 62.0f) / 255.0f) + 1.0f) / 256.0f;
		}
		else if (n < 1024) {
			red = 1.0f;
			green = ((((n - 512.0f) * 63.0f) / 511.0f) + 64.0f) / 256.0f;
		}
		else if (n < 2048) {
			red = 1.0f;
			green = ((((n - 1024.0f) * 63.0f) / 1023.0f) + 128.0f) / 256.0f;
		}
		else /*if (n < 4096)*/ {
			red = 1.0f;
			green = ((((n - 2048.0f) * 63.0f) / 2047.0f) + 192.0f) / 256.0f;
		}
		//		else {
		//			red = 1.0f;
		//			green = 1.0f;
		//		}
		break;
	case 3:
		if (n == iterations) {

		}
		else if (n < 64) {
			blue = n * 2.0f / 256.0f;
		}
		else if (n < 128) {
			blue = ((((n - 64.0f) * 128.0f) / 126.0f) + 128.0f) / 256.0f;
		}
		else if (n < 265) {
			blue = ((((n - 128.0f) * 62.0f) / 127.0f) + 193.0f) / 256.0f;
		}
		else if (n < 512) {
			blue = 1.0f;
			green = ((((n - 256.0f) * 62.0f) / 255.0f) + 1.0f) / 256.0f;
		}
		else if (n < 1024) {
			blue = 1.0f;
			green = ((((n - 512.0f) * 63.0f) / 511.0f) + 64.0f) / 256.0f;
		}
		else if (n < 2048) {
			blue = 1.0f;
			green = ((((n - 1024.0f) * 63.0f) / 1023.0f) + 128.0f) / 256.0f;
		}
		else if (n < 4096) {
			blue = 1.0f;
			green = ((((n - 2048.0f) * 63.0f) / 2047.0f) + 192.0f) / 256.0f;
		}
		else {
			blue = 1.0f;
			green = 1.0f;
		}
		break;
	case 4: // greyscale
		red = 2 * n * step;
		if (n > iterations - 2) {
			red = 0.0;
		}
		blue = red;
		green = red;

		break;
	default:
		red = 1.0;
		green = 0.0;
		blue = 0.0;
		break;
	}

	float* ret = new float[3];
	ret[0] = red;
	ret[1] = green;
	ret[2] = blue;
	return ret;
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

void MandelbrotSet::reset() {
	this->width = width;
	this->height = height;
	this->iterations = 128;
	this->colorMode = 2;
	min.r = -2.0;
	min.i = -1.2;
	max.r = 1.0;
	max.i = min.i + (max.r - min.r) * height / width;
	factor.r = (max.r - min.r) / (width - 1);
	factor.i = (max.i - min.i) / (height - 1);
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

	iterations *= 2;

	if (iterations > MAX_ITERATIONS) {
		iterations = MAX_ITERATIONS;
	}
}

void MandelbrotSet::zoomOut(unsigned int x, unsigned int y) {
	// map x & y to function
	float xMapped = min.r + ((max.r - min.r) / width) * x;
	float yMapped = min.i + ((max.i - min.i) / height) * y;

	// double height and with
	float newWidth = (max.r - min.r) * 2;
	float newHeight = (max.i - min.i) * 2;

	// x & y as new middle point
	min.r = xMapped - (newWidth / 2);
	max.r = xMapped + (newWidth / 2);
	min.i = yMapped - (newHeight / 2);
	max.i = min.i + (max.r - min.r) * newHeight / newWidth;

	factor.r = (max.r - min.r) / (width - 1);
	factor.i = (max.i - min.i) / (height - 1);

	iterations /= 2;
}

void MandelbrotSet::setColorMode(int colorMode) {
	this->colorMode = colorMode;
}
