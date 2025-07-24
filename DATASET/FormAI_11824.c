//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {

  char input[1000];
  printf("Enter your string: ");
  fgets(input, 1000, stdin);

  // Removing the newline character from fgets
  input[strcspn(input, "\n")] = 0;

  int count = 0;
  int i;
  char prevChar = ' ';
  for (i = 0; i < strlen(input); i++) {
    char currentChar = input[i];
    if (currentChar == ' ' && prevChar != ' ') {
      count++;
    }
    prevChar = currentChar;
  }

  if (count == 0 && strlen(input) > 0) {
    count = 1;
  }

  printf("Word count: %d\n", count);

  return 0;
}