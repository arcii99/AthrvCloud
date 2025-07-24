//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main() {
  char input[MAX_INPUT_LENGTH];
  printf("Enter some input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);
  input[strcspn(input, "\n")] = '\0'; // remove trailing newline
  printf("Input before sanitization: %s\n", input);

  char san_input[MAX_INPUT_LENGTH];
  int i = 0;
  int j = 0;

  while (input[i] != '\0') {
    if (isalpha(input[i])) {
      san_input[j] = tolower(input[i]); // convert to lowercase
      j++;
    }
    i++;
  }

  san_input[j] = '\0'; // terminate sanitized input string with null character
  printf("Input after sanitization: %s\n", san_input);
  return 0;
}