//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: calm
#include <stdio.h>
#include <string.h>

/* Function prototypes */
char* sanitizeInput(char*);

int main() {
  char input[100];

  printf("Enter your input: ");
  fgets(input, 100, stdin);

  printf("Your input was: %s\n", input);

  char* sanitizedInput = sanitizeInput(input);

  printf("Your sanitized input is: %s\n", sanitizedInput);

  return 0;
}

/* Function to sanitize user input */
char* sanitizeInput(char* input) {
  /* Remove newline character from input */
  if(input[strlen(input)-1] == '\n') {
    input[strlen(input)-1] = '\0';
  }

  /* Replace characters with asterisks */
  int i;
  for(i = 0; i < strlen(input); i++) {
    if(input[i] == '&' || input[i] == '<' || input[i] == '>' || input[i] == '\"' || input[i] == '\'') {
      input[i] = '*';
    }
  }

  return input;
}