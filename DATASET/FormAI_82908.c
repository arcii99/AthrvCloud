//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of input string

int is_valid_character(char c) {
  return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

int is_palindrome(char *str, int n) {
  int start = 0;
  int end = n - 1;

  while(start < end) {
    while(start < n && !is_valid_character(str[start])) start++;

    if(start == n) return 1; // If string contains only special characters

    while(end >= 0 && !is_valid_character(str[end])) end--;

    if(str[start] != str[end]) {
      return 0;
    }

    start++;
    end--;
  }

  return 1;
}

int main() {
  char str[MAX_LENGTH];

  printf("Enter a string:\n");
  scanf("%[^\n]s", &str);

  int n = strlen(str);

  if(is_palindrome(str, n)) {
    printf("String is a palindrome!\n");
  } else {
    printf("String is not a palindrome.\n");
  }

  return 0;
}