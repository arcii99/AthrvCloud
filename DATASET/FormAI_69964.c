//FormAI DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include<stdio.h>

int main() {
  // Declare variables to store user inputs
  int num1, num2;
  
  // Ask user to input two integer numbers
  printf("Enter first integer number: ");
  scanf("%d", &num1);
  printf("Enter second integer number: ");
  scanf("%d", &num2);
  
  // Perform arithmetic operations and print results
  printf("\nThe sum of %d and %d is: %d", num1, num2, num1 + num2);
  printf("\nThe difference of %d and %d is: %d", num1, num2, num1 - num2);
  printf("\nThe product of %d and %d is: %d", num1, num2, num1 * num2);
  
  // Check if second number is zero for division operation
  if(num2 == 0) {
    printf("\nCannot perform division operation as second number is zero!");
  } else {
    printf("\nThe quotient of %d and %d is: %d", num1, num2, num1 / num2);
    printf("\nThe remainder of %d divided by %d is: %d", num1, num2, num1 % num2);
  }
  
  return 0;
}