//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: happy
/* Happy User Input Sanitizer Example Program */

#include <stdio.h>
#include <ctype.h>

int main() {
  char input[100];
  
  printf("Hello! Welcome to the Happy User Input Sanitizer Program.\n");
  printf("Please enter your name: \n");
  fgets(input, sizeof(input), stdin);
  
  printf("Hi, %s! Let's start.\n", input);
  printf("Please enter any text, and I will remove any non-alphabetic characters: \n");
  fgets(input, sizeof(input), stdin);
  
  int i, j;
  char c;
  char sanitized_input[100];
  for (i = 0, j = 0; input[i] != '\0'; i++) {
    c = input[i];
    if (isalpha(c)) {
      sanitized_input[j++] = c;
    }
  }
  sanitized_input[j] = '\0';
  
  printf("Here's your sanitized input: %s\n", sanitized_input);
  printf("Isn't it lovely to have clean input?\n");
  
  return 0;
}