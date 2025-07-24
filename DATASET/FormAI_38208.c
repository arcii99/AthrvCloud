//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: synchronous
/*
  Program: User Input Sanitizer
  
  Description: This program sanitizes user input by removing any non-alphanumeric characters
  and converting all characters to lowercase.
  
  Author: Your Name
  
  Date: DD/MM/YYYY
  
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

int main() {

  char input[MAX_INPUT_SIZE];
  char sanitized[MAX_INPUT_SIZE];
  
  printf("Enter a string: ");
  fgets(input, MAX_INPUT_SIZE, stdin);
  
  for (int i = 0; i < strlen(input); i++) {
    if (isalnum(input[i])) {
      sanitized[i] = tolower(input[i]);
    }
  }
  
  printf("Sanitized input: %s", sanitized);
  
  return 0;
}