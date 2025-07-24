//FormAI DATASET v1.0 Category: String manipulation ; Style: Ada Lovelace
/*
This program demonstrates string manipulation in C using Ada Lovelace's analytical engine. 
This program reverses a given input string and compares the reversed string to the original string.
If they are equal, it outputs "The string is a palindrome". If not, it outputs "The string is not a palindrome". 
*/

#include <stdio.h>
#include <string.h>

// function prototype
char* reverse(char*);

int main() {
  char str[100];
  char* rev;

  // get input string
  printf("Enter a string:");
  fgets(str, 100, stdin);

  // remove newline character from input string
  str[strcspn(str, "\n")] = 0;

  // reverse the input string
  rev = reverse(str);

  // compare the input string with its reverse
  if (strcmp(str, rev) == 0) {
    printf("The string is a palindrome");
  } else {
    printf("The string is not a palindrome");
  }

  return 0;
}

// function definition to reverse a string
char* reverse(char* str) {
  static char rev[100];

  int length = strlen(str);
  int i;
  for (i = 0; i < length; i++) {
    rev[i] = str[length - i - 1];
  }
  rev[length] = '\0';

  return rev;
}