//FormAI DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <ctype.h>

int main() {
  char sentence[1000];
  int wordCount = 0, sentenceLength = 0;

  printf("Enter a sentence: ");
  fgets(sentence, 1000, stdin);

  while (sentence[sentenceLength] != '\0') {
    if (isspace(sentence[sentenceLength])) {
      wordCount++;
    }
    sentenceLength++;
  }

  if (sentenceLength > 0) {
    wordCount++;
  }

  printf("Word count: %d\n", wordCount);

  return 0;
}