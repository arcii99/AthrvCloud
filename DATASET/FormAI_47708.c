//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitizeInput(char* input) {
  char* temp = input;

  while (*temp != '\0') {
    if (*temp == '\n' || *temp == '\r') {
      *temp = '\0';
      break;
    }
    temp++;
  }

  temp = input;
  char* output = input;

  while (*temp != '\0') {
    if (isalnum(*temp) || isspace(*temp)) {
      *output++ = *temp++;
    }
    else {
      temp++;
    }
  }

  *output = '\0';
}

int main() {
  char input[100];

  printf("Enter your input: ");
  fgets(input, 100, stdin);

  sanitizeInput(input);

  printf("Your sanitized input: %s\n", input);

  return 0;
}