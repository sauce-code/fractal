#ifndef MANDELBROTSET_H_
#define MANDELBROTSET_H_

#include <GL/freeglut.h>

#include "Complex.h"

#define MAX_ITERATIONS 50

class MandelbrotSet {
private:
	double width;
	double height;
	complex min;
	complex max;
	complex factor;
	void draw(unsigned int, unsigned int, complex);
public:
	MandelbrotSet(double, double);
	virtual ~MandelbrotSet();
	void calculate();
};

#endif /* MANDELBROTSET_H_ */
