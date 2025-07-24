//FormAI DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 10000

int countWords(char *string);

int main() {
  char text[MAX_CHARACTERS];

  printf("Enter text: ");
  fgets(text, MAX_CHARACTERS, stdin);

  int wordCount = countWords(text);

  printf("Word count: %d\n", wordCount);

  return 0;
}

int countWords(char *string) {
  int wordCount = 0;
  int i = 0;

  while (string[i]) {
    // If current character is not a space or a newline, it's part of a word
    if (string[i] != ' ' && string[i] != '\n') {
      // If the previous character was a space or a newline, it means we have encountered a new word
      if (i > 0 && (string[i - 1] == ' ' || string[i - 1] == '\n')) {
        wordCount++;
      }
    }
    i++;
  }

  // Handle the case when the last character is not a space or a newline
  if (i > 0 && (string[i - 1] != ' ' && string[i - 1] != '\n')) {
    wordCount++;
  }

  return wordCount;
}