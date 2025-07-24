//FormAI DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>

int main() {
  int a, b, c;
  float x, y, z;

  printf("Enter three integer values: ");
  scanf("%d %d %d", &a, &b, &c);
  printf("Enter three decimal values: ");
  scanf("%f %f %f", &x, &y, &z);

  // Perform arithmetic operations with integers
  printf("\nArithmetic operations with integers:\n");
  printf("%d + %d + %d = %d\n", a, b, c, a+b+c);
  printf("%d - %d - %d = %d\n", a, b, c, a-b-c);
  printf("%d * %d * %d = %d\n", a, b, c, a*b*c);
  printf("%d / %d = %d with a remainder of %d\n", a, b, a/b, a%b);

  // Perform arithmetic operations with decimal values
  printf("\nArithmetic operations with decimal values:\n");
  printf("%.2f + %.2f + %.2f = %.2f\n", x, y, z, x+y+z);
  printf("%.2f - %.2f - %.2f = %.2f\n", x, y, z, x-y-z);
  printf("%.2f * %.2f * %.2f = %.2f\n", x, y, z, x*y*z);
  printf("%.2f / %.2f = %.2f\n", x, y, x/y);

  // Calculate the average of the integer values
  float avg = (float)(a+b+c)/3;
  printf("\nThe average of %d, %d, and %d is %.2f\n", a, b, c, avg);

  // Determine if the decimal values are equal
  if (x == y && y == z) {
    printf("\nThe decimal values are equal.\n");
  }
  else {
    printf("\nThe decimal values are not equal.\n");
  }

  return 0;
}