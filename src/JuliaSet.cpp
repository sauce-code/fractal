/*
 * JuliaSet.cpp
 *
 *  Created on: 09.01.2016
 *      Author: Maike
 */

#include "JuliaSet.h"

JuliaSet::JuliaSet(unsigned int width, unsigned int height): MandelbrotSet(width, height) {

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
	complex k;
	k.r = 0.353;
	k.i = 0.288;
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
