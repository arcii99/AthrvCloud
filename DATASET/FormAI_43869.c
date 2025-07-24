//FormAI DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <string.h>

// This function counts the number of words in a string.
int countWords(char str[]) {
  int count = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      count++;
    }
  }

  return count + 1;
}

int main() {
  char input[100];

  printf("Enter a string: ");
  fgets(input, 100, stdin);

  // Removing the newline character from the input
  input[strcspn(input, "\n")] = 0;

  int wordCount = countWords(input);

  printf("The number of words in the string is: %d", wordCount);

  return 0;
}