//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Sample program to read text input and count the total number of words 
   and each occurence of unique words */

int main() {
  char text[1000];
  int count = 0;
  char *word_ptr;
  char words[100][100];
  int frequency[100] = {0};
  int i, j;

  printf("Enter your text:\n\n");
  fgets(text, sizeof(text), stdin);

  /* Remove trailing newline character */
  text[strcspn(text, "\n")] = 0;

  /* Tokenize input into separate words */
  word_ptr = strtok(text, " \t");

  /* Populate words array and count number of unique words */
  while (word_ptr != NULL) {
    int word_exists = 0;
    for (i = 0; i < count; i++) {
      if (strcmp(words[i], word_ptr) == 0) {
        frequency[i]++;
        word_exists = 1;
        break;
      }
    }
    if (!word_exists) {
      strcpy(words[count], word_ptr);
      frequency[count]++;
      count++;
    }
    word_ptr = strtok(NULL, " \t");
  }

  /* Print out unique words and their frequency */
  printf("\nNumber of words: %d\n", count);
  printf("\nFrequency of unique words:\n");
  for (i = 0; i < count; i++) {
    printf("%s: %d\n", words[i], frequency[i]);
  }

  return 0;
}