#pragma once
#include <cmath>

double sec(double value) {
	return 1 / cos(value);
}

double csc(double value) {
	return 1 / sin(value);
}

double ctg(double value) {
	return 1 / tan(value);
}

double sech(double value) {
	return 1 / cosh(value);
}

double csch(double value) {
	return 1 / sinh(value);
}

double ctgh(double value) {
	return 1 / tanh(value);
}