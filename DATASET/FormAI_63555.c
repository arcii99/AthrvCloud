//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {
  char input[MAX_INPUT_LENGTH];
  int input_length;
  printf("Please enter some input:");
  fgets(input, MAX_INPUT_LENGTH, stdin);
  input_length = strlen(input);
  printf("Sanitized input:");
  for (int i = 0; i < input_length; i++) {
    if (isalpha(input[i])) {
      putchar(tolower(input[i]));
    }
    else if (isdigit(input[i])) {
      putchar(input[i]);
    }
    else if (input[i] != ' ') {
      putchar('?');
    }
  }
  putchar('\n');
  return 0;
}