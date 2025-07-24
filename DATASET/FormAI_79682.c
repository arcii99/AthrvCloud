//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char sentence[1000];

  printf("Enter a sentence: ");
  fgets(sentence, 1000, stdin);

  // remove newline
  sentence[strcspn(sentence, "\n") - 1] = '\0';

  int sentenceLength = strlen(sentence);
  int wordCount = 1;
  int vowelCount = 0;

  for(int i=0; i<sentenceLength; i++) {
    if (sentence[i] == ' ') {
      wordCount++;
    } else if (sentence[i] == 'a' || sentence[i] == 'e'
               || sentence[i] == 'i' || sentence[i] == 'o'
               || sentence[i] == 'u') {
      vowelCount++;
    }
  }

  printf("Your sentence is: %s\n", sentence);
  printf("It has %d words\n", wordCount);
  printf("It has %d vowels\n", vowelCount);

  return 0;
}