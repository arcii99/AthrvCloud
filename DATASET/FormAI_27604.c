//FormAI DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
  char text[10000];
  int wordCount = 0;

  printf("Welcome to C Word Count Tool!\n\n");
  printf("Please enter your text.\n");
  // get user input
  fgets(text, 10000, stdin);

  // count the words in the input string
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == ' ') {
      wordCount++;
    }
  }
  // increment word count for last word
  wordCount++;

  printf("\n");
  printf("Your text has %d words.\n", wordCount);

  return 0;
}