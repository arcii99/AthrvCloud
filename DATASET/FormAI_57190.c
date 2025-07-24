//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to check if a given string is a palindrome */
int isPalindrome(char *str) {
  int left = 0;
  int right = strlen(str) - 1;

  while (right > left) {
    if (tolower(str[left++]) != tolower(str[right--])) {
      return 0; // If the characters at left and right are not equal, return 0
    }
  }
  return 1;
}

int main() {
  char str[50];
  printf("Enter a string: ");
  scanf("%s", str);

  if (isPalindrome(str)) {
    printf("The given string is a palindrome.\n");
  } else {
    printf("The given string is not a palindrome.\n");
  }

  return 0;
}