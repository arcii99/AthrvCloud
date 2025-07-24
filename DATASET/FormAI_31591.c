//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>

int main() {
  float a = 8;
  float b = 5;
  float c = 4;
  float d = 10;
  float result;

  printf("Calculating the value of ((a + b) * c) / d\n");
  result = ((a + b) * c) / d;
  printf("Result : %.2f\n", result);

  printf("\nCalculating the value of sqrt(a * b + c / d)\n");
  result = sqrt(a * b + c / d);
  printf("Result : %.2f\n", result);

  printf("\nCalculating the value of exp(a) * sin(b) - pow(c, d)\n");
  result = exp(a) * sin(b) - pow(c, d);
  printf("Result : %.2f\n", result);

  printf("\nCalculating the value of log10(a) + ceil(b) * floor(c)\n");
  result = log10(a) + ceil(b) * floor(c);
  printf("Result : %.2f\n", result);

  printf("\nCalculating the value of fabs((-a) + b + c * (-d))\n");
  result = fabs((-a) + b + c * (-d));
  printf("Result : %.2f\n", result);

  return 0;
}