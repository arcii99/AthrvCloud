//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

int is_palindrome(char str[]);
int main() {
  char str[MAX];
  printf("Enter a string: ");
  fgets(str, MAX, stdin);
  if (is_palindrome(str)) {
    printf("It's a palindrome.\n");
  } else {
    printf("It's not a palindrome.\n");
  }
  return 0;
}

int is_palindrome(char str[]) {
  int len = strlen(str) - 1;     // subtracting 1 for null character '\0'
  int i;
  for (i = 0; i < len / 2; i++) {
    if (tolower(str[i]) != tolower(str[len - i - 1])) {
      return 0;
    }
  }
  return 1;
}