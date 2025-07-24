//FormAI DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include<stdio.h>

// Function to calculate the factorial of a number
int factorial(int num) {
  // Base case: if the number is 0 or 1, the factorial is 1
  if(num == 0 || num == 1) {
    return 1;
  }
  // Recursive case: multiply the number with the factorial of the number-1
  else {
    return num * factorial(num-1);
  }
}

// Main function
int main() {
  int number;
  printf("Enter a number to calculate its factorial:");
  scanf("%d", &number);
  // Handle negative numbers
  if(number < 0) {
    printf("Factorial of negative numbers does not exist.\n");
  }
  else {
    printf("Factorial of %d is %d.\n", number, factorial(number));
  }
  return 0;
}