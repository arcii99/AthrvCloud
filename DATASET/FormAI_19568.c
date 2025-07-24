//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void toLowerCase(char *string) {
  for (int i = 0; i < strlen(string); i++) {
    string[i] = tolower(string[i]);
  }
}

void sanitizeInput(char *string) {
  toLowerCase(string);
  
  char sanitizedString[strlen(string)];
  int index = 0;
  
  for (int i = 0; i < strlen(string); i++) {
    if (isalpha(string[i])) {
      sanitizedString[index++] = string[i];
    }
  }
  
  sanitizedString[index] = '\0';
  
  strcpy(string, sanitizedString);
}

int main() {
  char input[100];
  printf("Enter a string: ");
  fgets(input, 100, stdin);
  
  sanitizeInput(input);
  
  printf("Your sanitized input is: %s", input);
  
  return 0;
}