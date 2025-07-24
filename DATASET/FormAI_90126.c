//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
  
  char input[100];
  int length, i, j, flag = 0;
  
  printf("Welcome to the Palindrome Checker program!\n\n");
  
  // Get user input
  printf("Please enter a word or phrase: ");
  scanf("%[^\n]s", input);
  
  length = strlen(input);
  
  // Check if input is a palindrome
  for (i = 0, j = length - 1; i < j; i++, j--) {
    if (input[i] != input[j]) {
      flag = 1;
      break;
    }
  }
  
  if (flag == 0) {
    printf("Congratulations! '%s' is a palindrome!\n", input);
  } else {
    printf("Sorry, '%s' is not a palindrome.\n", input);
  }
  
  printf("\nThanks for using our program!");
  
  return 0;
}