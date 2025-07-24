//FormAI DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1000];
  int wordCount = 0;

  printf("Enter a sentence: ");
  fgets(sentence, sizeof(sentence), stdin);

  for (int i = 0; sentence[i] != '\0'; i++) {
    // Check if the current character is a space, tab, or newline
    if (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\n') {
      wordCount++;
    }
  }
  // Add one more for the last word
  wordCount++;

  printf("Word count: %d\n", wordCount);

  return 0;
}