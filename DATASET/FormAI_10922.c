//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* sanitizeInput(char* userInput) {
  int len = strlen(userInput);
  char* sanitizedInput = (char*)malloc(sizeof(char)*len);
  int j = 0;
  for(int i = 0; i < len; i++) {
    if(isalnum(userInput[i]) || isspace(userInput[i])) {
      sanitizedInput[j] = userInput[i];
      j++;
    }
  }
  sanitizedInput[j] = '\0';
  return sanitizedInput;
}

int main() {
  char userInput[100];
  printf("Enter your input: ");
  scanf("%[^\n]", userInput);
  char* sanitizedOutput = sanitizeInput(userInput);
  printf("Sanitized output: %s\n", sanitizedOutput);
  free(sanitizedOutput);
  return 0;
}