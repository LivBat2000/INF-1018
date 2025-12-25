#include <stdio.h>

float foo (double a, float b);

int main() {
	double a = 2.4;
	float b = 5.2;
	printf("%f", foo(a, b));
	return 0;
}