//FormAI DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>

int main() {
  int num1, num2, result;
  
  printf("Welcome to the Arithmetic program!\n");
  printf("Enter a number: ");
  scanf("%d", &num1);
  printf("Great! Now enter another number: ");
  scanf("%d", &num2);
  
  // Addition
  result = num1 + num2;
  printf("\n%d + %d = %d\n", num1, num2, result);
  
  // Subtraction
  result = num1 - num2;
  printf("%d - %d = %d\n", num1, num2, result);
  
  // Multiplication
  result = num1 * num2;
  printf("%d x %d = %d\n", num1, num2, result);
  
  // Division
  if (num2 != 0) {
    result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);
  } else {
    printf("Sorry, cannot divide by zero.\n");
  }
  
  // Modulus
  if (num2 != 0) {
    result = num1 % num2;
    printf("%d %% %d = %d\n", num1, num2, result);
  } else {
    printf("Sorry, cannot divide by zero.\n");
  }
  
  printf("\nThank you for using the Arithmetic program!\n");

  return 0;
}