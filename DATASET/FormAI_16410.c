//FormAI DATASET v1.0 Category: Arithmetic ; Style: multivariable
#include <stdio.h>

int main() {
  int a = 10, b = 20, c = 30, d = 40, e = 50;
  float f = 3.1415, g = 2.7182, h = 1.6180;
  double i = 123456789.12345, j = 6789101112.1314;

  // Arithmetic operations with integers
  int sum = a + b + c + d + e;
  int product = a * b * c * d * e;
  int difference = e - a;
  int quotient = d / b;
  int remainder = d % b;
  int power = a * c;

  printf("The sum of %d, %d, %d, %d, and %d is %d\n", a, b, c, d, e, sum);
  printf("The product of %d, %d, %d, %d, and %d is %d\n", a, b, c, d, e, product);
  printf("The difference between %d and %d is %d\n", e, a, difference);
  printf("%d divided by %d is %d with a remainder of %d\n", d, b, quotient, remainder);
  printf("%d raised to the power of %d is %d\n", a, c, power);

  // Arithmetic operations with floating point numbers
  float sum_f = f + g + h;
  float product_f = f * g * h;
  float difference_f = g - h;
  float quotient_f = i / j;

  printf("The sum of %f, %f, and %f is %f\n", f, g, h, sum_f);
  printf("The product of %f, %f, and %f is %f\n", f, g, h, product_f);
  printf("The difference between %f and %f is %f\n", g, h, difference_f);
  printf("%lf divided by %lf is %f\n", i, j, quotient_f);

  return 0;
}