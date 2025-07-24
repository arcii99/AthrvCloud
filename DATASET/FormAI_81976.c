//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {

  char input[1000];
  int wordCount = 0;

  printf("Enter a sentence: ");
  fgets(input, sizeof(input), stdin);

  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ' && input[i+1] != ' ') {
      wordCount++;
    }
  }

  printf("There are %d words in the sentence.\n", wordCount + 1);

  return 0;
}