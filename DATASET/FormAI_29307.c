//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mathematical
#include <stdio.h>

/* A function to calculate the sum of two integers */
int sum(int a, int b) {
  int result = a + b;
  return result;
}

/*
  A program that takes the input of two integers
  and outputs their sum on the screen
*/
int main() {
  int num1, num2, result;
  
  /* Prompt the user to enter the numbers */
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  /* Call the sum function */
  result = sum(num1, num2);
  
  /* Print the result */
  printf("The sum of %d and %d is %d.\n", num1, num2, result);
  
  return 0;
}