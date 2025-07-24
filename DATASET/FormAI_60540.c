//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void toLowerCase(char* str);
int isPalindrome(char* str);

int main() {
  char input[MAX_LENGTH];

  printf("Welcome to Palindrome Checker!\n");
  printf("Please enter a string to check for palindrome: ");

  fgets(input, MAX_LENGTH, stdin);
  
  // remove newline from input
  input[strcspn(input, "\n")] = 0;

  toLowerCase(input);

  if(isPalindrome(input)) {
    printf("The string \"%s\" is a palindrome. Peace out!\n", input);
  } else {
    printf("The string \"%s\" is not a palindrome. Sorry not sorry.\n", input);
  }

  return 0;
}

void toLowerCase(char* str) {
  for(int i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
}

int isPalindrome(char* str) {
  int length = strlen(str);
  int half = length / 2;

  for(int i = 0; i < half; i++) {
    if(str[i] != str[length-1-i]) {
      return 0;
    }
  }

  return 1;
}