//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1000];
  char word[100];
  int freq = 0;
  int found = 0;

  printf("Player 1, please input a sentence: ");
  fgets(sentence, 1000, stdin);

  do {
    printf("Player 2, please input a word: ");
    scanf("%s", word);

    char *ptr = strtok(sentence, " ");
    while (ptr != NULL) {
      if (strcmp(ptr, word) == 0) {
        freq++;
        found = 1;
      }
      ptr = strtok(NULL, " ");
    }

    if (found == 1) {
      printf("The frequency of '%s' in the sentence is %d\n", word, freq);
    } else {
      printf("'%s' is not in the sentence\n", word);
    }

    freq = 0;
    found = 0;
  } while (1);

  return 0;
}