//FormAI DATASET v1.0 Category: Scientific ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int num1, num2;
  float num3, num4;

  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);
  printf("Enter two decimal numbers: ");
  scanf("%f %f", &num3, &num4);

  int sum = num1 + num2;
  float avg = (num3 + num4) / 2;
  int diff = abs(num1 - num2);
  float sqrt_sum = sqrt(num1 + num2);
  float pow_sum = pow(num1 + num2, 2);

  printf("Sum of integers: %d\n", sum);
  printf("Average of decimals: %.2f\n", avg);
  printf("Absolute difference of integers: %d\n", diff);
  printf("Square root of sum of integers: %.2f\n", sqrt_sum);
  printf("Square of sum of integers: %.2f\n", pow_sum);

  return 0;
}