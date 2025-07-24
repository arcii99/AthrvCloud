//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>

int main() {
  int num1, num2, result;
  
  // Get user input for num1 and num2
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("\nEnter the second number: ");
  scanf("%d", &num2);
  
  // Add the two numbers
  result = num1 + num2;
  
  // Print the result in an energetic way
  printf("\nWoohoo! The result of %d + %d is %d!\n", num1, num2, result);
  
  // Subtract the two numbers
  result = num1 - num2;
  
  // Print the result in an even more energetic way
  printf("\nAwesome!! The result of %d - %d is %d!\n", num1, num2, result);
  
  // Multiply the two numbers
  result = num1 * num2;
  
  // Print the result in the most energetic way possible
  printf("\nYesss!!! The result of %d * %d is %d!!!\n", num1, num2, result);
  
  // Divide the two numbers
  result = num1 / num2;
  
  // Print the result in an extremely energetic way (if num2 is not 0)
  if (num2 != 0) {
    printf("\nWoooohoooo!! The result of %d / %d is %d!!!!\n", num1, num2, result);
  }
  
  // If num2 is 0, print an error message in an energetic way
  else {
    printf("\nUh-oh! You can't divide by 0! That's a BIG no-no!!!\n");
  }
  
  return 0;
}