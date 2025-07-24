//FormAI DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>   // standard input and output library
#include <stdlib.h>  // standard library for various functionality

int main() {
    
  printf("Welcome to Math Fun!\n");
  
  int num1, num2;
  
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  // Let's do some math!
  
  printf("\n");
  printf("=========MATH TIME!=========\n");
  printf("Addition: %d + %d = %d\n", num1, num2, num1 + num2);
  printf("Subtraction: %d - %d = %d\n", num1, num2, num1 - num2);
  printf("Multiplication: %d x %d = %d\n", num1, num2, num1*num2);
  if (num2 != 0){
    printf("Division: %d / %d = %d\n", num1, num2, num1 / num2);
  }
  
  printf("=========COOL RESULT!=========\n");
  
  int quotient = num1/num2;
  int remainder = num1%num2;
  printf("The quotient is %d and the remainder is %d\n", quotient, remainder);
  
  printf("The absolute value of %d is %d\n",num1,abs(num1));
  printf("The absolute value of %d is %d\n",num2,abs(num2));
  
  printf("The power of %d raised to %d is %.2f\n", num1, num2, pow(num1, num2));
  
  printf("The square root of %d is %.2f\n", num2, sqrt(num2));
  
  return 0;      
}