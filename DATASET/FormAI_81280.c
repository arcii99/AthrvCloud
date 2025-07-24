//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

int main() {
  printf("Enter your input:\n");
  char input[MAX_INPUT_SIZE];
  fgets(input, MAX_INPUT_SIZE, stdin);

  char sanitized_input[MAX_INPUT_SIZE];
  int j = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (isalpha(input[i])) {
      sanitized_input[j] = input[i];
      j++;
    } else if (isdigit(input[i])) {
      sanitized_input[j] = input[i];
      j++;
    } else if (ispunct(input[i])) {
      if (input[i] == '_') {
        sanitized_input[j] = input[i];
        j++;
      }
    } else if (isspace(input[i])) {
      sanitized_input[j] = ' ';
      j++;
    }
  }
  sanitized_input[j] = '\0';

  printf("Sanitized input: %s\n", sanitized_input);
  return 0;
}