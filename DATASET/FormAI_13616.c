//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Function to check if a given string is a palindrome */
int isPalindrome(char *string, int length) {
  int i, j;
  /* Ignore any non-alphanumeric characters */
  for (i = 0, j = length - 1; i < j; i++, j--) {
    while (!isalnum(string[i]) && i < j) i++;
    while (!isalnum(string[j]) && i < j) j--;
    if (tolower(string[i]) != tolower(string[j])) return 0;
  }
  return 1;
}

int main() {
  char string[100];
  int length;
  printf("Enter a string: ");
  /* Read the input string from the user */
  fgets(string, sizeof(string), stdin);
  length = strlen(string) - 1; /* Ignore the newline character */
  if (isPalindrome(string, length))
    printf("%s is a palindrome.\n", string);
  else
    printf("%s is not a palindrome.\n", string);
  return 0;
}