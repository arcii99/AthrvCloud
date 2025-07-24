//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: curious
#include <stdio.h>
#include <string.h>

// Declare function to check for palindrome
void palindromeChecker(char str[]);

// Main function
int main() {

  printf("Welcome to the Palindrome Checker!\n");
  printf("Enter a word or phrase to check if it's a palindrome: ");

  // Declare string variable and input from user
  char str[100];
  scanf("%[^\n]", str);

  // Call palindromeChecker function
  palindromeChecker(str);

  printf("\nThanks for using the Palindrome Checker! Bye bye ...\n");

  return 0;
}

// Function to check for palindrome
void palindromeChecker(char str[]) {

  // Declare length of string
  int length = strlen(str);
  
  // Declare new string variable to store reversed string
  char newStr[length];

  // Copy string into new string variable in reverse order
  for (int i = 0; i < length; i++) {
    newStr[i] = str[length - 1 - i];
  }

  // Null-terminate new string variable
  newStr[length] = '\0';

  // Compare original string and reversed string
  if (strcmp(str, newStr) == 0) {
    printf("\n%s is a palindrome! Yay!\n", str);
  } else {
    printf("\n%s is not a palindrome. :( \n", str);
  }
}