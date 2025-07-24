//FormAI DATASET v1.0 Category: Scientific ; Style: peaceful
#include <stdio.h>

// Define a function to calculate the hypotenuse of a right triangle given its two legs
double calculate_hypotenuse(double a, double b) {
  double c_squared = (a*a) + (b*b);
  double c = sqrt(c_squared);
  return c;
}

int main() {
  printf("Welcome to the peaceful right triangle calculator!\n");

  double a, b;
  printf("Please enter the length of the first leg: ");
  scanf("%lf", &a);

  printf("Please enter the length of the second leg: ");
  scanf("%lf", &b);

  double c = calculate_hypotenuse(a, b);
  printf("The length of the hypotenuse is: %.2lf\n", c);

  printf("Peace out!\n");

  return 0;
}