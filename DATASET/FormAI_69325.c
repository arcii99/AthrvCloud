//FormAI DATASET v1.0 Category: Arithmetic ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Set up random number generator
  srand(time(NULL));
  
  // Declare variables
  int num1, num2, result;
  
  // Generate first random number
  num1 = rand() % 100 + 1;
  
  // Print surprise message
  printf("Wow! Your first number is %d!\n", num1);
  
  // Generate second random number
  num2 = rand() % 100 + 1;
  
  // Print another surprise message
  printf("Incredible! Your second number is %d!\n", num2);
  
  // Add the two numbers together
  result = num1 + num2;
  
  // Print out the result
  printf("Wait for it...the result of %d + %d is %d!\n", num1, num2, result);
  
  // Check if result is odd or even
  if(result % 2 == 0) {
    printf("Whoa! The sum is even!\n");
  } else {
    printf("Holy cow! The sum is odd!\n");
  }
  
  // Check if result is a multiple of 5
  if(result % 5 == 0) {
    printf("Stop the presses! The sum is a multiple of 5!\n");
  } else {
    printf("Unbelievable! The sum is not a multiple of 5!\n");
  }
  
  // Check if result is greater than 100
  if(result > 100) {
    printf("No way! The sum is greater than 100!\n");
  } else {
    printf("Marvelous! The sum is not greater than 100!\n");
  }
  
  // Check if result is less than 50
  if(result < 50) {
    printf("Hold on to your hats! The sum is less than 50!\n");
  } else {
    printf("Astounding! The sum is not less than 50!\n");
  }
  
  // Check if result is equal to 42
  if(result == 42) {
    printf("I can't believe it! The sum is exactly 42!\n");
  } else {
    printf("Sensational! The sum is not 42!\n");
  }
  
  // End program with surprise message
  printf("That was an amazing arithmetic program! Thanks for playing!\n");
  
  return 0;
}