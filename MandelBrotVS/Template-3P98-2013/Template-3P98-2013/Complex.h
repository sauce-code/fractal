#ifndef COMPLEX_H_
#define COMPLEX_H_

struct complex {
	double r, i;
	double getAbsolute() {
		return r * r + i * i;
	}
	complex pow2() {
		return{ r * r - i * i, 2 * r * i };
	}
	inline complex operator+(complex a) {
		return{ r + a.r, i + a.i };
	}
	inline complex operator*(complex a) {
		return{ r * a.r - i * a.i, r * a.i + i * a.r };
	}
};

#endif /* COMPLEX_H_ */
