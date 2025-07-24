//FormAI DATASET v1.0 Category: Math exercise ; Style: scientific
#include <stdio.h>
#include <math.h>

int main() {
  double x, y, z;

  printf("Enter value of x: ");
  scanf("%lf", &x);
  
  while (x < 0) {
    printf("Invalid input. Enter value of x greater than or equal to 0: ");
    scanf("%lf", &x);
  }

  y = pow(x, 2) + 4;
  z = sin(y) * cos(x);

  printf("Value of y: %lf\n", y);
  printf("Value of z: %lf\n", z);

  return 0;
}