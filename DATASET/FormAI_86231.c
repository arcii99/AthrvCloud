//FormAI DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char text[1000], word[1000];
  int wc = 0, i;

  printf("Enter text to count words: ");
  fgets(text, sizeof(text), stdin);

  printf("Enter word to count occurrences of: ");
  scanf("%s", word);

  // split the text into words
  char *token = strtok(text, " ");

  while (token != NULL) {
    if (strcmp(token, word) == 0) {
      wc++; // increment word count if matching
    }
    token = strtok(NULL, " ");
  }

  printf("The word '%s' appears %d times in the text.\n", word, wc);

  return 0;
}