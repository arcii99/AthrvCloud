//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: immersive
#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

char *sanitize_input(char *input);

int main(void) {
  char input[MAX_INPUT_LENGTH], *sanitized_input;

  printf("Please enter some input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  sanitized_input = sanitize_input(input);

  printf("The sanitized input is: %s\n", sanitized_input);

  return 0;
}

char *sanitize_input(char *input) {
  char *sanitized_input = "";
  int i = 0;

  while (input[i] != '\0') {
    if (isalnum(input[i])) {
      char character[2] = { input[i], '\0' };
      sanitized_input = strcat(sanitized_input, character);
    } else if (isspace(input[i])) {
      sanitized_input = strcat(sanitized_input, " ");
    }

    i++;
  }

  return sanitized_input;
}