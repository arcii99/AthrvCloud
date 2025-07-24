//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void sanitizeInput(char* input) {
  int i, j = 0;
  char sanitized[MAX_SIZE];

  for(i = 0; input[i] != '\0'; i++) {
    if(isalnum(input[i])) {
      sanitized[j] = input[i];
      j++;
    }
  }

  sanitized[j] = '\0';

  strcpy(input, sanitized);
}

int main() {
  char input[MAX_SIZE];

  printf("Enter text: ");
  fgets(input, MAX_SIZE, stdin);

  sanitizeInput(input);

  printf("Sanitized input: %s\n", input);

  return 0;
}