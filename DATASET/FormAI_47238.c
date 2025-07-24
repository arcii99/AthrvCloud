//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
  int length = strlen(str);
  
  // Loop through the string and compare characters
  for (int i = 0; i < length / 2; i++) {
    if (str[i] != str[length - i - 1])
      return 0;
  }
  return 1;
}

int main() {
  char str[100];
  printf("Please enter a string to check if it is a palindrome: ");
  fgets(str, 100, stdin);
  
  // Remove newline character from input
  str[strcspn(str, "\n")] = '\0';
  
  if (isPalindrome(str))
    printf("The string '%s' is a palindrome!\n", str);
  else
    printf("The string '%s' is not a palindrome.\n", str);
  
  return 0;
}