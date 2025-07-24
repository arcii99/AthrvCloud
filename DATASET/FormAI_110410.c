//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void sanitizeInput(char* userInput);

int main() {
  char userInput[MAX_LEN];
  printf("Enter input:\n");
  fgets(userInput, MAX_LEN, stdin);  // read user input

  sanitizeInput(userInput);

  printf("Sanitized input: %s\n", userInput);
  return 0;
}

void sanitizeInput(char* userInput) {
  int i, j, len = strlen(userInput);

  // remove leading/trailing whitespace
  char* end;
  while (*userInput == ' ') userInput++;  // remove leading spaces
  end = userInput + len - 1;  // past null terminator
  while (end > userInput && *end == ' ') end--;  // remove trailing spaces
  *(end + 1) = '\0';  // add null terminator to end of sanitized input

  // remove consecutive spaces
  for (i = 0, j = 0; i < len; i++, j++) {
    if (userInput[i] == ' ' && userInput[i + 1] == ' ') j--;
    userInput[j] = userInput[i];
  }
  userInput[j] = '\0';

  // remove non-alphanumeric characters
  for (i = 0; userInput[i]; i++) {
    if ((userInput[i] < 'A' || userInput[i] > 'Z') && (userInput[i] < 'a' || userInput[i] > 'z') && (userInput[i] < '0' || userInput[i] > '9')) {
      for (j = i; userInput[j]; j++) {
        userInput[j] = userInput[j + 1];
      }
      len--;
      i--;
    }
  }
}