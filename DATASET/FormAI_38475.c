//FormAI DATASET v1.0 Category: Math exercise ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
  int num1, num2, sum, difference, product, quotient, remainder;
  float root1, root2, discriminant;

  srand(time(NULL)); // initialize random seed with current time

  num1 = rand() % 101; // generate random numbers between 0 and 100
  num2 = rand() % 101;

  // perform mathematical operations
  sum = num1 + num2;
  difference = abs(num1 - num2);
  product = num1 * num2;
  quotient = num1 / num2;
  remainder = num1 % num2;

  // calculate roots using quadratic formula
  discriminant = pow(difference, 2) - (4 * product);
  if (discriminant > 0) {
    root1 = (-difference + sqrt(discriminant)) / (2 * num1);
    root2 = (-difference - sqrt(discriminant)) / (2 * num1);
  } else if (discriminant == 0) {
    root1 = root2 = -difference / (2 * num1);
  } else {
    printf("The roots are imaginary.\n");
    return 1;
  }

  // print out results
  printf("Welcome to the math exercise example program!\n\n");
  printf("Two random numbers have been generated: %d and %d.\n", num1, num2);
  printf("Their sum is %d.\n", sum);
  printf("Their difference is %d.\n", difference);
  printf("Their product is %d.\n", product);
  printf("Their quotient is %d with a remainder of %d.\n", quotient, remainder);
  printf("The roots of the quadratic equation with coefficients %d, %d, and %d are %f and %f.\n", num1, -difference, product, root1, root2);

  return 0;
}