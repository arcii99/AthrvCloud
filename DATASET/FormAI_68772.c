//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 50

char *sanitize_input(char *input) {
  int i, j = 0;
  char *sanitized_input = (char*)malloc(sizeof(char) * MAX_LENGTH);

  for(i = 0; i < strlen(input); i++) {
    if(isalpha(input[i]) || isdigit(input[i])) {
      sanitized_input[j] = input[i];
      j++;
    }
  }

  // Add null terminator
  sanitized_input[j] = '\0';

  return sanitized_input;
}

int main() {
  char input[MAX_LENGTH], *sanitized_input;

  printf("Enter your input: ");
  fgets(input, MAX_LENGTH, stdin);

  sanitized_input = sanitize_input(input);

  printf("The sanitized input: %s\n", sanitized_input);

  free(sanitized_input);

  return 0;
}