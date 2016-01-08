#ifndef COMPLEX_H_
#define COMPLEX_H_

struct complex {
	double r;
	double i;
	double getAbsolute() {
		return r * r + i * i;
	}
	complex pow2() {
		return { r * r - i * i, 2 * r * i};
//		r = r * r - i * i;
//		i = 2 * r * i;
	}
	inline complex operator+(complex a) {
		return { r + a.r, i + a.i };
	}
};

#endif /* COMPLEX_H_ */
