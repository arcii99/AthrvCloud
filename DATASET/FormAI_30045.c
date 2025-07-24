//FormAI DATASET v1.0 Category: Arithmetic ; Style: genious
#include <stdio.h>

int main() {
  int num1, num2, result;
  
  printf("Welcome to Genius Calculator!\n");
  printf("Enter first number: ");
  scanf("%d", &num1);
  printf("Enter second number: ");
  scanf("%d", &num2);
  
  result = ((num1 + num2) * (num1 - num2)) / (num1 * num2);
  
  printf("Result of the Genius Calculation is: %d\n", result);
  printf("Did you know that this calculation is equivalent to (num1^2 - num2^2)/(num1*num2)?\n");
  
  printf("But wait, there's more!\n");
  
  result = (num1 + num2) / (num1 - num2) + (num1 * num2) - (num1 % num2) + (num1 / 3);
  
  printf("The new Genius Calculation result is: %d\n", result);
  printf("And that is equivalent to ((num1 + num2) / (num1 - num2)) + (num1 * num2) - (num1 modulo num2) + (num1 divided by 3).\n");
  
  printf("Thank you for using the Genius Calculator!\n");
  return 0;
}