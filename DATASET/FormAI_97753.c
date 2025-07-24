//FormAI DATASET v1.0 Category: Word Count Tool ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  int count = 0;

  printf("Enter a sentence: ");
  fgets(input, 1000, stdin);

  // remove the newline character from input
  input[strcspn(input, "\n")] = 0;

  // count number of words in input
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      count++;
    }
  }

  printf("Number of words in sentence: %d", count + 1);

  return 0;
}