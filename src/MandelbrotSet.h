#ifndef MANDELBROTSET_H_
#define MANDELBROTSET_H_

#include <GL/freeglut.h>

#include "Complex.h"

#define MAX_ITERATIONS 50

class MandelbrotSet {
private:
	unsigned int width;
	unsigned int height;
	complex min;
	complex max;
	complex factor;
	void draw(unsigned int, unsigned int, complex);
public:
	MandelbrotSet(unsigned int, unsigned int);
	virtual ~MandelbrotSet();
	void calculate();
	void setWidth(unsigned int);
	void setHeight(unsigned int);
};

#endif /* MANDELBROTSET_H_ */
