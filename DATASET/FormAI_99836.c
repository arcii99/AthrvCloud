//FormAI DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>

int main() {
  int num1, num2, result;
  
  printf("Enter two numbers separated by a space: ");
  scanf("%d %d", &num1, &num2);

  // Addition
  result = num1 + num2;
  printf("\n%d + %d = %d\n", num1, num2, result);

  // Subtraction
  result = num1 - num2;
  printf("\n%d - %d = %d\n", num1, num2, result);

  // Multiplication
  result = num1 * num2;
  printf("\n%d * %d = %d\n", num1, num2, result);

  // Division
  if(num2 != 0) {
    float result_f = (float)num1 / num2;
    printf("\n%d / %d = %.2f\n", num1, num2, result_f);
  } else {
    printf("\nCannot divide by zero!\n");
  }

  // Modulus
  result = num1 % num2;
  printf("\n%d %% %d = %d\n", num1, num2, result);

  return 0;
}