//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check if a string is a valid palindrome
int isPalindrome(char *str) {
  int i = 0;
  int j = strlen(str) - 1;
  while (i < j) {
    if (tolower(str[i]) != tolower(str[j])) {
      return 0;
    }
    i++;
    j--;
  }
  return 1;
}

int main() {
  char input[100];
  printf("Enter a string: ");
  fgets(input, 100, stdin);
  // remove newline character
  if (input[strlen(input) - 1] == '\n') {
    input[strlen(input) - 1] = '\0';
  }
  // check if input is a valid palindrome and print result
  if (isPalindrome(input)) {
    printf("%s is a valid palindrome\n", input);
  } else {
    printf("%s is not a valid palindrome\n", input);
  }
  return 0;
}