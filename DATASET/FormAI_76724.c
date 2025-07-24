//FormAI DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int num1, num2, num3, result;
  printf("Welcome to the surreal math exercise program!\n");
  printf("Please enter 3 surreal numbers separated by spaces: \n");
  scanf("%d %d %d", &num1, &num2, &num3);

  result = pow(num1, num2) + sqrt(num3);

  printf("The result of the surreal math exercise is: %d\n", result);
  printf("But wait! This result is not what it seems...\n");
  printf("Let's apply our special surreal transformation to it...\n");

  int transformed_result = abs(result) * 11 - num3;

  printf("The transformed result is: %d\n", transformed_result);
  printf("Congratulations! You have completed the surreal math exercise!\n");

  return 0;
}