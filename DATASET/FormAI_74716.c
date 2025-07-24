//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: enthusiastic
#include <stdio.h>

int main() {
  char userInput[50];

  printf("Welcome! Please enter some text: ");
  fgets(userInput, sizeof(userInput), stdin);

  printf("\nYou entered: %s\n", userInput);

  return 0;
}