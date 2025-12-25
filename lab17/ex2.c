#include <stdio.h>

double foo (double a, int b);

int main(void) {
  printf("%f\n", foo(3.5, 4));
  printf("%f\n", foo(3.5, -4));
  printf("%f\n", foo(-3.5, 4));
  printf("%f\n", foo(-3.5, -4));
  return 0;
}