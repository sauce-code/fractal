/*
* JuliaSet.h
*
*  Created on: 09.01.2016
*      Author: Maike
*/

#ifndef JULIASET_H_
#define JULIASET_H_

#include "MandelbrotSet.h"

class JuliaSet : public MandelbrotSet {
public:
	JuliaSet(unsigned int, unsigned int);
	//	virtual ~JuliaSet();
	void draw(unsigned int, unsigned int, complex);
	void calculate();
	void reset();
	complex k;
};

#endif /* JULIASET_H_ */
