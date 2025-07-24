//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function prototype
char *sanitize_input(char *input);

int main(void) {
  char input[100];

  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = 0;

  char *sanitized_input = sanitize_input(input);
  printf("Sanitized input: %s\n", sanitized_input);
  
  free(sanitized_input);
  return 0;
}

char *sanitize_input(char *input) {
  int len = strlen(input);
  char *sanitized = (char *) malloc(sizeof(char) * len + 1);

  for (int i = 0; i < len; i++) {
    if (isalnum(input[i])) {
      sanitized[i] = input[i];
    } else {
      sanitized[i] = '_';
    }
  }

  sanitized[len] = '\0';

  return sanitized;
}