//FormAI DATASET v1.0 Category: Scientific ; Style: sophisticated
#include <stdio.h>
#include <math.h>

int main() {
  int num, power;
  double result;

  printf("Enter a number: ");
  scanf("%d", &num);

  printf("Enter a power: ");
  scanf("%d", &power);

  result = pow(num, power);

  printf("%d raised to the power of %d is %lf\n", num, power, result);

  return 0;
}