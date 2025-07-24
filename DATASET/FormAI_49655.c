//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>

int main() 
{
  int num1, num2, result;
  printf("Welcome to the Amazing Arithmetic Adventure!\n");
  printf("Please enter the first number: ");
  scanf("%d", &num1);
  printf("\nPlease enter the second number: ");
  scanf("%d", &num2);
  
  result = num1 + num2;
  printf("\nWoo hoo! The sum of %d and %d is %d!\n", num1, num2, result);
  
  result = num1 - num2;
  printf("\nOh yeah! The difference of %d and %d is %d!\n", num1, num2, result);
  
  result = num1 * num2;
  printf("\nAmazing! The product of %d and %d is %d!\n", num1, num2, result);
  
  if (num2 == 0) {
    printf("\nOops! You can't divide by zero! Please try another number.\n");
  } else {
    result = num1 / num2;
    printf("\nIncredible! The quotient of %d and %d is %d, with a remainder of %d!\n", num1, num2, result, num1%num2);
  }
  printf("\nThanks for joining us on this Amazing Arithmetic Adventure!\n");

  return 0;
}