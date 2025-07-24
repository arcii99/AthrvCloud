//FormAI DATASET v1.0 Category: Math exercise ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables
  double x, y, z, ans1, ans2, ans3;
  
  // Prompt user for input of x, y, and z values
  printf("Enter a value for x: ");
  scanf("%lf", &x);
  printf("Enter a value for y: ");
  scanf("%lf", &y);
  printf("Enter a value for z: ");
  scanf("%lf", &z);
  
  // Perform mathematical operations
  ans1 = (sqrt(x) + pow(y, 2)) / (z + 1);
  ans2 = fabs(x - y) + log10(z);
  ans3 = (sin(x) * cos(y)) / exp(z);
  
  // Display results
  printf("\n");
  printf("The result of the first operation is: %.2lf\n", ans1);
  printf("The result of the second operation is: %.2lf\n", ans2);
  printf("The result of the third operation is: %.2lf\n", ans3);
  
  return 0;
}