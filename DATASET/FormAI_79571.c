//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  
  char input[1000];
  printf("Enter your input: ");
  fgets(input, sizeof(input), stdin);
  
  // Remove trailing newline from input
  input[strcspn(input, "\n")] = 0;
  
  // Sanitize input
  for(int i = 0; i < strlen(input); i++) {
    switch(input[i]) {
      case '<':
        input[i] = '[';
        break;
      case '>':
        input[i] = ']';
        break;
      case '\'':
        input[i] = '"';
        break;
      case '\\':
        input[i] = '/';
        break;
    }
    input[i] = tolower(input[i]);
  }
  
  // Print sanitized input
  printf("Sanitized input: %s\n", input);
  
  return 0;
}