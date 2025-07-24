//FormAI DATASET v1.0 Category: Data validation ; Style: relaxed
#include<stdio.h>

/* This program validates user input of an integer value */

int main() {
  int userInput;
  
  // Prompt user for input
  printf("Enter an integer value: ");
  
  // Loop until valid input is entered
  while(scanf("%d", &userInput) != 1) {
    // If scanf fails to read an integer value, clear input buffer and prompt user again
    printf("Invalid input! Please enter an integer value: ");
    fflush(stdin); // Clear input buffer
  }
  
  // Display user input
  printf("You entered: %d\n", userInput);
  
  return 0;
}