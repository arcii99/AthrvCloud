//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: recursive
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isPalindrome(char* str, int start, int end);

int main() {
  char input[1000];
  printf("Enter a string: ");
  fgets(input, 1000, stdin);
  int len = strlen(input);
  if (input[len - 1] == '\n') {
    input[len - 1] = '\0';
    len--;
  }
  if (isPalindrome(input, 0, len - 1))
    printf("%s is a palindrome.\n", input);
  else
    printf("%s is not a palindrome.\n", input);
  return 0;
}

int isPalindrome(char* str, int start, int end) {
  if (start >= end) {
    return 1;
  }
  if (tolower(str[start]) == tolower(str[end]))
    return isPalindrome(str, start + 1, end - 1);
  else
    return 0;
}