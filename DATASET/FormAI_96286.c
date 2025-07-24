//FormAI DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>

// Define constant values
#define PI 3.14159
#define E 2.71828

// Function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  else {
    return n * factorial(n-1);
  }
}

int main() {
  float x, y, z;
  int n;

  // Take user input
  printf("Enter the value of x: ");
  scanf("%f", &x);

  printf("Enter the value of y: ");
  scanf("%f", &y);

  printf("Enter the value of z: ");
  scanf("%f", &z);

  printf("Enter the value of n: ");
  scanf("%d", &n);

  // Perform arithmetic calculations
  float result = (x * y) + (z / x) - (n * PI);
  result *= E;

  // Perform factorial calculation
  int f = factorial(n);

  // Print the results
  printf("Result: %f\n", result);
  printf("Factorial of %d: %d\n", n, f);

  return 0;
}