//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[], int len) {
  int i, j;
  for (i = 0, j = len - 1; i < j; i++, j--) {
    if (tolower(str[i]) != tolower(str[j]))
      return 0;
  }
  return 1;
}

int main(void) {
  char str[100];
  int len;
  
  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  len = strlen(str) - 1;

  if (isPalindrome(str, len))
    printf("The string is a palindrome\n");
  else
    printf("The string is not a palindrome\n");

  return 0;
}