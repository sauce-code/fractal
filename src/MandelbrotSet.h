#ifndef MANDELBROTSET_H_
#define MANDELBROTSET_H_

#include <GL/freeglut.h>
#include <stdio.h>
#include "Complex.h"

#define MAX_ITERATIONS 4096

class MandelbrotSet {
public:
	unsigned int width;
	unsigned int height;
	unsigned int iterations;
	unsigned int colorMode;
	complex min;
	complex max;
	complex factor;
	void draw(unsigned int, unsigned int, complex);
	float* getColor(unsigned int);
public:
	MandelbrotSet(unsigned int, unsigned int);
	virtual ~MandelbrotSet();
	void calculate();
	void setWidth(unsigned int);
	void setHeight(unsigned int);
	void setIterations(unsigned int);
	void reset();
	void zoom(unsigned int, unsigned int);
	void zoomOut(unsigned int, unsigned int);
	void setColorMode(int);
};

#endif /* MANDELBROTSET_H_ */
