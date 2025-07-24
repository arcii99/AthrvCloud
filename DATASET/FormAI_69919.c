//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>

int main() {
  char sentence[1000];
  char c;
  int wordCount = 0, i = 0;
  
  printf("Enter a sentence: ");

  // Take input from user
  while ((c = getchar()) != '\n') {
    sentence[i++] = c;

    // If a space or end of sentence is found, increment word count
    if (c == ' ' || c == '\t' || c == '\r' || c == '\f' || c == '\v') {
      wordCount++;
    }
  }

  sentence[i] = '\0';
  
  // Increment word count for last word as well
  wordCount++;

  printf("Word count: %d\n", wordCount);

  return 0;
}