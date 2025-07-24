//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int x, y;
  float num, result;

  printf("Enter an integer for x: ");
  scanf("%d", &x);
  printf("Enter another integer for y: ");
  scanf("%d", &y);
  printf("Enter a floating-point number for num: ");
  scanf("%f", &num);

  result = pow(x, y) + sqrt(num) - pow((x+y), 2);

  printf("------------------------------\n");
  printf("The result of the calculation:\n\n");
  printf("x to the power of y = %f\n", pow(x,y));
  printf("Square root of num = %f\n", sqrt(num));
  printf("Sum of x and y squared = %f\n", pow((x+y), 2));
  printf("------------------------------\n");
  printf("The final result = %f\n", result);

  return 0;
}