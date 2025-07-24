//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Claude Shannon
#include <stdio.h>

// Below is the main function
int main() {
  
  // Initializing two integer variables
  int num1, num2;
  
  // Asking the user for input for num1
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  // Asking the user for input for num2
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  // Performing addition operation on num1 and num2
  int sum = num1 + num2;
  
  // Performing subtraction operation on num1 and num2
  int diff = num1 - num2;
  
  // Performing multiplication operation on num1 and num2
  int prod = num1 * num2;
  
  // Performing division operation on num1 and num2
  float div = (float)num1 / num2;
  
  // Displaying the result of addition
  printf("Sum: %d\n", sum);
  
  // Displaying the result of subtraction
  printf("Difference: %d\n", diff);
  
  // Displaying the result of multiplication
  printf("Product: %d\n", prod);
  
  // Displaying the result of division
  printf("Quotient: %.2f\n", div);
  
  // Returning 0 to indicate successful completion of the program
  return 0;
}