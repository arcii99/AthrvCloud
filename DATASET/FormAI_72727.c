//FormAI DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

void checkSpelling(char *fileName);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s filename\n", argv[0]);
    return 1;
  }

  checkSpelling(argv[1]);

  return 0;
}

void checkSpelling(char *fileName) {
  FILE *fp;
  char word[MAX_WORD_LENGTH];
  int lineCount = 1;
  int wordCount = 0;

  if ((fp = fopen(fileName, "r")) == NULL) {
    printf("Error: Could not open file \"%s\"\n", fileName);
    return;
  }

  while (fscanf(fp, "%s", word) != EOF) {
    int len = strlen(word);
    int i;

    // Remove any non-alphabetic characters from the word
    for (i = 0; i < len; i++) {
      if (!isalpha(word[i])) {
        memmove(&word[i], &word[i + 1], len - i);
        len--;
        i--;
      }
    }

    // Check if the word is correctly spelled
    if ((strlen(word) > 0) && (strlen(word) < MAX_WORD_LENGTH)) {
      wordCount++;

      // Add your unique spelling code here
      // For example, you could print out the spelling of each word backwards
      printf("Word %d on line %d is spelled backwards as: ", wordCount, lineCount);
      for (i = strlen(word) - 1; i >= 0; i--) {
        printf("%c", word[i]);
      }
      printf("\n");
    }

    // Check if we've reached the end of the line
    if (word[len - 1] == '\n') {
      lineCount++;
    }
  }

  fclose(fp);
}