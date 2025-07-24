//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char str[100], rev_str[100];
  int i, j, len;
  printf("Enter a string: ");
  fgets(str, 100, stdin);
  len = strlen(str) - 1;

  // make all the letters lowercase
  for (i = 0; i < len; i++) {
    str[i] = tolower(str[i]);
  }

  // remove all non-alphanumeric characters
  j = 0;
  for (i = 0; i < len; i++) {
    if (isalnum(str[i])) {
      rev_str[j++] = str[i];
    }
  }
  rev_str[j] = '\0';
  len = strlen(rev_str);

  // check if the string is a palindrome
  for (i = 0, j = len - 1; i < len; i++, j--) {
    if (rev_str[i] != rev_str[j]) {
      printf("%s is not a palindrome\n", str);
      return 0;
    }
  }
  printf("%s is a palindrome\n", str);

  return 0;
}