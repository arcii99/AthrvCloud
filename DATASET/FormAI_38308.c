//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void sanitize(char *input);

int main() {
  char input[MAX_INPUT_LENGTH];
  printf("Enter your input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);
  sanitize(input);
  printf("Sanitized input: %s\n", input);
  return 0;
}

void sanitize(char *input) {
  // Remove any non-alphabetic characters and convert to lowercase
  for (int i = 0; i < strlen(input); i++) {
    if (!isalpha(input[i])) { 
      memmove(&input[i], &input[i + 1], strlen(input) - i); 
      i--;
    } else {
      input[i] = tolower(input[i]);
    }
  }

  // Ensure input is exactly 10 characters
  if (strlen(input) > 10) {
    input[10] = '\0';
  } else if (strlen(input) < 10) {
    int len = strlen(input);
    for (int i = 0; i < (10 - len); i++) {
      strcat(input, "x");
    }
  }
}