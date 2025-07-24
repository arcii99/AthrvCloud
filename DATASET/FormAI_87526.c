//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void getInput(char *input) {
  fgets(input, MAX_INPUT_LENGTH, stdin);
}

void sanitizeInput(char *input) {
  int i = 0;
  while (input[i] != '\n') {
    if (isalnum(input[i])) {
      input[i] = tolower(input[i]);
    } else {
      input[i] = '_';
    }
    i++;
  }
}

int main() {
  char input[MAX_INPUT_LENGTH];
  
  printf("Enter your input: ");
  getInput(input);
  
  sanitizeInput(input);

  printf("Your sanitized input: %s\n", input);

  return 0;
}