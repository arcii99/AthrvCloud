//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

bool isPalindrome(char *str) {
  int len = strlen(str);
  int i = 0, j = len - 1;
  
  while (i < j) {
    if (str[i] != str[j])
      return false;
    i++;
    j--;
  }
  
  return true;
}

int main() {
  char input[MAX_LENGTH];
  
  printf("Palindrome checker - Enter a string: ");
  fgets(input, MAX_LENGTH, stdin);
  
  // Remove newline character from input
  input[strcspn(input, "\n")] = '\0';
  
  if (isPalindrome(input)) {
    printf("The string '%s' is a palindrome.\n", input);
  } else {
    printf("The string '%s' is not a palindrome.\n", input);
  }
  
  return 0;
}