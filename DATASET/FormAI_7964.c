//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter your input: ");
  fgets(input, 100, stdin);

  int valid = 0;

  // Sanitize input
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] > 31 && input[i] < 127) {
      valid++;
    }
    else {
      input[i] = '_';
    }
  }

  // Display sanitized input
  printf("\nSanitized input: %s\n", input);

  if(valid < strlen(input)) {
    printf("Attention: Invalid characters have been replaced with underscores.\n");
    printf("Sanitized input may not be accurate.\n");
  }

  return 0;
}