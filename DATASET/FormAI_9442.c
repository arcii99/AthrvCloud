//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double a, b, c, result;
  printf("Enter values for a, b, and c:\n");
  scanf("%lf%lf%lf", &a, &b, &c);
  if (a == 0) {
    printf("Error: a cannot equal 0.\n");
    exit(EXIT_FAILURE);
  }
  result = b*b - 4*a*c;
  if (result < 0) {
    printf("Error: negative discriminant.\n");
    exit(EXIT_FAILURE);
  }
  double x1 = (-b + sqrt(result)) / (2 * a);
  double x2 = (-b - sqrt(result)) / (2 * a);
  printf("The roots are %lf and %lf.\n", x1, x2);
  return 0;
}