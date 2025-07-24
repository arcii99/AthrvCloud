//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100]; // Initialize a character array with a max size of 100
  int length, i, j, flag = 0; // Declare variables for later use

  printf("Welcome to the palindrome checker program!\n");
  printf("Please enter the string you want to check: ");
  fgets(input, 100, stdin); // Reads user input and stores it as a string

  length = strlen(input); // Find the length of the input string (including \0)
  
  for (i = 0, j = length - 2; i <= (length - 2)/2; i++, j--) {
    if (input[i] != input[j]) { // Compare the characters at each end of the string
      flag = 1; // If characters are not the same, set flag to 1
      break; // Break out of the for loop
    }
  }
  
  if (flag == 1) {
    printf("Sorry, %s is not a palindrome.\n", input);
  }
  else {
    printf("%s is a palindrome!\n", input);
  }
  
  return 0; // End of program
}