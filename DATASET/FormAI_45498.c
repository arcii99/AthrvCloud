//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input[100];
  printf("Please enter your input: ");
  fgets(input, 100, stdin);

  // Removing leading and trailing spaces
  int i = 0;
  while (isspace(input[i])) {
    i++;
  }
  int j = strlen(input) - 1;
  while (j >= i && isspace(input[j])) {
    input[j] = '\0';
    j--;
  }

  // Converting all letters to lowercase
  for (i = 0; i < strlen(input); i++) {
    input[i] = tolower(input[i]);
  }

  // Replacing all non-alphanumeric characters with spaces
  for (i = 0; i < strlen(input); i++) {
    if (!isalnum(input[i])) {
      input[i] = ' ';
    }
  }

  // Removing consecutive spaces
  for (i = 0; i < strlen(input); i++) {
    if (isspace(input[i])) {
      j = i + 1;
      while (isspace(input[j])) {
        j++;
      }
      if (j - i > 1) {
        memmove(&input[i], &input[j], strlen(&input[j]) + 1);
      }
    }
  }

  printf("Your sanitized input is: %s\n", input);
  return 0;
}