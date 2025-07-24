//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: visionary
#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 50

int main() {
  char userInput[MAX_LEN + 1];
  int i = 0;

  printf("Please enter your input:\n");
  fgets(userInput, MAX_LEN, stdin);

  while (userInput[i] != '\0') {
    // Convert to lowercase
    if (isupper(userInput[i])) {
      userInput[i] = tolower(userInput[i]);
    }

    // Remove non-alphanumeric characters
    if (!isalnum(userInput[i])) {
      for (int j = i; j < MAX_LEN; j++) {
        userInput[j] = userInput[j + 1];
      }
    }

    i++;
  }

  printf("Your sanitized input is: %s\n", userInput);

  return 0;
}