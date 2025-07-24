//FormAI DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  int character, wordCount = 0;
  int inWord = 0;

  printf("Please enter your text:\n");

  while ((character = getchar()) != EOF) {
    if (isspace(character)) {
      inWord = 0;
    } else {
      if (inWord == 0) {
        wordCount++;
        inWord = 1;
      }
    }
  }

  printf("Your text contains %d words.", wordCount);

  return 0;
}