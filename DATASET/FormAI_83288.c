//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

void sanitizeInput(char *input);

int main(void) {
  char input[MAX_LENGTH];

  printf("Enter some input: ");
  fgets(input, MAX_LENGTH, stdin);

  sanitizeInput(input);

  printf("Sanitized input: %s\n", input);

  return 0;
}

void sanitizeInput(char *input) {
  int i, j;

  for (i = 0, j = 0; input[i] != '\0'; i++) {
    // remove leading/trailing white space
    if (i == 0 && isspace(input[i])) continue;

    if (isspace(input[i]) && isspace(input[i + 1])) continue;

    // remove non-alphanumeric characters
    if (isalnum(input[i]) || isspace(input[i])) {
      input[j++] = tolower(input[i]);
    }
  }

  input[j] = '\0';
}