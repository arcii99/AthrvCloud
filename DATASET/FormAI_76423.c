//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_LENGTH 1000

void format_input(char inputs[MAX_LENGTH]);
int is_palindrome(char inputs[MAX_LENGTH]);

void format_input(char inputs[MAX_LENGTH]) {
  int length = strlen(inputs);
  for (int i = 0; i < length; i++) {
    inputs[i] = tolower(inputs[i]);
    if (inputs[i] == ' ' || ispunct(inputs[i])) {
      for (int j = i; j < length; j++) {
        inputs[j] = inputs[j+1];
      }
      length--;
      i--;
    }
  }
}

int is_palindrome(char inputs[MAX_LENGTH]) {
  int length = strlen(inputs);
  for (int i = 0; i < length/2; i++) {
    if (inputs[i] != inputs[length-i-1]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char inputs[MAX_LENGTH];
  printf("Enter a word or phrase: ");
  fgets(inputs, MAX_LENGTH, stdin);
  format_input(inputs);
  if (is_palindrome(inputs)) {
    printf("\n%s is a palindrome.\n", inputs);
  }
  else {
    printf("\n%s is not a palindrome.\n", inputs);
  }
  return 0;
}