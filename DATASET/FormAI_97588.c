//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

char* sanitize_input(char* input);

int main() {
  char input[MAX_INPUT_LENGTH];
  char* sanitized_input;

  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);

  sanitized_input = sanitize_input(input);

  printf("\nSanitized input: %s\n", sanitized_input);

  free(sanitized_input);

  return 0;
}

char* sanitize_input(char* input) {
  int i, j;
  char* sanitized_input = (char*) malloc(MAX_INPUT_LENGTH * sizeof(char));

  if (sanitized_input == NULL) {
    printf("Error: malloc failed to allocate memory.\n");
    exit(1);
  }

  for (i = 0, j = 0; i < strlen(input); i++) {
    if (isalpha(input[i])) {
      sanitized_input[j++] = tolower(input[i]);
    }
  }

  sanitized_input[j] = '\0';

  return sanitized_input;
}