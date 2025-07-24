//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  char reverse[1000];
  int i, length;
  
  printf("Welcome to the Palindrome Checker program!\n");
  printf("Please enter a word or phrase: ");
  scanf("%s", input);
  
  length = strlen(input);
  
  // Reverse the input
  for (i = 0; i < length; i++) {
    reverse[length - i - 1] = input[i];
  }
  
  reverse[length] = '\0';
  
  // Check if input is a palindrome
  if (strcmp(input, reverse) == 0) {
    printf("Congratulations! '%s' is a palindrome!\n", input);
  } else {
    printf("I'm sorry, '%s' is not a palindrome.\n", input);
  }
  
  return 0;
}