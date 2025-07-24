//FormAI DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>

int main() {
  int num1, num2;
  
  printf("Enter first number: ");
  if (scanf("%d", &num1) != 1) {
    printf("Sorry, that input was not a number");
    return 1;
  }
  
  printf("Enter second number: ");
  if (scanf("%d", &num2) != 1) {
    printf("Sorry, that input was not a number");
    return 1;
  }
  
  if (num2 == 0) {
    printf("Undefined result! Division by zero is not allowed\n");
    return 1;
  }
  
  int result = num1 / num2;
  
  if (result < 0) {
    printf("Negative result! Taking the absolute value...\n");
    result = abs(result);
  }
  
  printf("The result is: %d\n", result);
  
  return 0; 
}