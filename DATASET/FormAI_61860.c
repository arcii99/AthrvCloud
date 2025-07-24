//FormAI DATASET v1.0 Category: Calculator ; Style: creative
#include <stdio.h>

int main() {
  printf("Welcome to the Calculator program!\n");
  printf("Please enter your first number:");
  float num1;
  scanf("%f", &num1);
  
  printf("Please enter your second number:");
  float num2;
  scanf("%f", &num2);
  
  // ADDITION
  float sum = num1 + num2;
  printf("\n%f + %f = %f\n", num1, num2, sum);
  
  // SUBTRACTION
  float difference = num1 - num2;
  printf("%f - %f = %f\n", num1, num2, difference);
  
  // MULTIPLICATION
  float product = num1 * num2;
  printf("%f * %f = %f\n", num1, num2, product);
  
  // DIVISION
  if (num2 != 0) {
    float quotient = num1 / num2;
    printf("%f / %f = %f\n", num1, num2, quotient);
  }
  else {
    printf("Undefined (division by zero)\n");
  }
  
  // MODULUS
  if ((int)num2 != 0) {
    int modulus = (int)num1 % (int)num2;
    printf("%d %% %d = %d\n", (int)num1, (int)num2, modulus);
  }
  else {
    printf("Undefined (remainder by zero)\n");
  }
  
  // EXPONENTIATION
  float power = 1;
  for (int i = 0; i < (int)num2; i++) {
    power *= num1;
  }
  printf("%f ^ %f = %f\n", num1, num2, power);
  
  printf("\nThanks for using the Calculator program! Goodbye.\n");
  
  return 0;
}