#ifndef MANDELBROTSET_H_
#define MANDELBROTSET_H_

#include <GL/freeglut.h>

#include "Complex.h"

class MandelbrotSet {
private:
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
};

#endif /* MANDELBROTSET_H_ */
