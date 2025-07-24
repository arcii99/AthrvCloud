//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: curious
#include <stdio.h>
#include <ctype.h>

int main() {
  char input[100], sanitized[100];
  int i, j = 0;

  printf("Hello there! Give me a string and I'll sanitize it for you.\n");
  fgets(input, 100, stdin);

  for(i = 0; input[i] != '\0'; i++) {
    if(isalpha(input[i])) {
      sanitized[j] = input[i];
      j++;
    }
  }
  sanitized[j] = '\0';

  printf("Your sanitized string is:\n%s", sanitized);

  return 0;
}