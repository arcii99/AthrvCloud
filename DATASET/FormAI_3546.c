//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {
  char input[100]; // declare a character array of size 100
  int i, length;
  int palindrome = 1; // assuming the input is a palindrome
  printf("Enter a string to check for palindrome: ");
  fgets(input, sizeof(input), stdin); // read input from user using fgets()
  
  length = strlen(input) - 1; // exclude the newline character

  for (i = 0; i < length / 2; i++) { // compare characters from both ends of the string
    if (input[i] != input[length - 1 - i]) {
      palindrome = 0; // mark the input as not a palindrome
      break;
    }
  }
  
  if (palindrome) {
    printf("%s is a palindrome.\n", input);
  } else {
    printf("%s is not a palindrome.\n", input);
  }

  return 0;
}