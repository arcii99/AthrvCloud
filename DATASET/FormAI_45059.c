//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *s);

int main(void) {
  char s[1000];

  printf("Enter a string: ");
  fgets(s, 1000, stdin);

  if (is_palindrome(s)) {
    printf("The string is a palindrome\n");
  } else {
    printf("The string is not a palindrome\n");
  }

  return 0;
}

int is_palindrome(char *s) {
  int i = 0;
  int j = strlen(s) - 1;

  while (i < j) {
    while (!isalnum(s[i]) && i < j) {
      i++;
    }

    while (!isalnum(s[j]) && i < j) {
      j--;
    }

    if (tolower(s[i]) != tolower(s[j])) {
      return 0;
    }

    i++;
    j--;
  }

  return 1;
}