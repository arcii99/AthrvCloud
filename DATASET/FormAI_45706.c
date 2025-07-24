//FormAI DATASET v1.0 Category: Math exercise ; Style: multivariable
#include <stdio.h>

int main() {
  float a, b, c, d, x, y, z;

  printf("Enter values for a, b, c, and d (separated by a space): ");
  scanf("%f %f %f %f", &a, &b, &c, &d);

  printf("Enter values for x, y, and z (separated by a space): ");
  scanf("%f %f %f", &x, &y, &z);

  float result = (a*x) + (b*y) + (c*z) + d;

  printf("The result of the multivariable equation (%.2f * %.2f) + (%.2f * %.2f) + (%.2f * %.2f) + %.2f is: %.2f\n", a, x, b, y, c, z, d, result);

  return 0;
}