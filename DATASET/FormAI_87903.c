//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: irregular
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

  char input[100];
  
  printf("Enter a string to sanitize: ");
  fgets(input, 100, stdin);
  
  // remove trailing newline character from input
  input[strcspn(input, "\n")] = '\0';
  
  // initialize sanitized version of input
  char sanitized[100];
  strcpy(sanitized, input);
  
  // loop through input, removing any non-alphanumeric characters
  int i;
  for (i = 0; i < strlen(sanitized); i++) {
    if (!isalnum(sanitized[i])) {
      memmove(&sanitized[i], &sanitized[i+1], strlen(sanitized) - i);
      i--;
    }
  }
  
  printf("Input sanitized to: %s", sanitized);
  
  return 0;
}