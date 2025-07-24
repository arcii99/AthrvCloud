//FormAI DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Set seed for random number generation
  srand(time(NULL));

  // Declare variables
  int a = 12, b = 8;
  float x = 4.5, y = 2.0;
  double pi = 3.14159;
  char c = 'R', d = 'T';

  // Use arithmetic operators on variables
  int sum = a + b;
  int difference = a - b;
  float product = x * y;
  float quotient = x / y;
  double circumference = 2 * pi * x;
  char shifted = c + 2;
  char inverted = ~d;

  // Generate random number between 1 and 10
  int random = rand() % 10 + 1;

  // Print results
  printf("Sum of %d and %d is %d\n", a, b, sum);
  printf("Difference of %d and %d is %d\n", a, b, difference);
  printf("Product of %.2f and %.2f is %.2f\n", x, y, product);
  printf("Quotient of %.2f and %.2f is %.2f\n", x, y, quotient);
  printf("Circumference of circle with radius %.2f is %.2f\n", x, circumference);
  printf("Character %c shifted by 2 is %c\n", c, shifted);
  printf("Inverted character of %c is %c\n", d, inverted);
  printf("Random number between 1 and 10 is %d\n", random);

  return 0;
}