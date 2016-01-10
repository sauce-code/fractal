/*
* JuliaSet.cpp
*
*  Created on: 09.01.2016
*      Author: Maike
*/

#include "JuliaSet.h"

JuliaSet::JuliaSet(unsigned int width, unsigned int height) :
MandelbrotSet(width, height) {
	k.r = 0.353;
	k.i = 0.288;
	min.r = -1.4;
	min.i = -2.5;
	max.r = 1.5;
	max.i = min.i + (max.r - min.r) * height / width;
	factor.r = (max.r - min.r) / (width - 1);
	factor.i = (max.i - min.i) / (height - 1);
}

//JuliaSet::~JuliaSet() {
//	// TODO Auto-generated destructor stub
//}

void JuliaSet::calculate() {
	complex c;
	for (unsigned int y = 0; y < height; y++) {
		c.i = max.i - y * factor.i;
		for (unsigned int x = 0; x < width; x++) {
			c.r = min.r + x * factor.r;
			draw(x, y, c);
		}
	}
}

void JuliaSet::draw(unsigned int x, unsigned int y, complex c) {
	complex z = c;
	unsigned int n = 0;

	for (n = 0; n < iterations; n++) {

		if (z.getAbsolute() > 4) {
			break;
		}
		z = z.pow2() + k;
	}

	glBegin(GL_POINTS);
	float* yolo = getColor(n);
	glColor3f(yolo[0], yolo[1], yolo[2]);
	glVertex2i(x, y);
	glEnd();
}

void JuliaSet::reset() {
	k.r = 0.353;
	k.i = 0.288;
	min.r = -1.4;
	min.i = -2.5;
	max.r = 1.5;
	max.i = min.i + (max.r - min.r) * height / width;
	factor.r = (max.r - min.r) / (width - 1);
	factor.i = (max.i - min.i) / (height - 1);
}
