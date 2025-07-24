//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, result;
  
  printf("Hello there! Let's do some arithmetic!\n");
  
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  printf("Calculating...\n");
  
  //Addition
  result = num1 + num2;
  printf("The sum of %d and %d is %d!\n", num1, num2, result);
  
  //Subtraction
  result = num1 - num2;
  printf("The difference between %d and %d is %d!\n", num1, num2, result);
  
  //Multiplication
  result = num1 * num2;
  printf("The product of %d and %d is %d!\n", num1, num2, result);
  
  //Division
  if(num2 == 0) {
    printf("Uh oh! You can't divide by zero!\n");
    printf("Don't worry, I'll fix it for you!\n");
    num2 = 1;
  }
  result = num1 / num2;
  printf("The quotient of %d and %d is %d!\n", num1, num2, result);
  
  
  printf("Thanks for doing arithmetic with me! See you next time!\n");
  
  return 0;
}