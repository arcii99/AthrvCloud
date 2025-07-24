//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENT_LEN 1000

int countWords(char* sentence);

int main() {
  char sentence[MAX_SENT_LEN];
  int wordCount = 0;

  printf("Enter your sentence: ");

  // Read in sentence from user input
  fgets(sentence, MAX_SENT_LEN, stdin);

  // Remove newline character from sentence
  if (sentence[strlen(sentence) - 1] == '\n') {
    sentence[strlen(sentence) - 1] = '\0';
  }

  // Count the number of words in the sentence
  wordCount = countWords(sentence);

  // Display the results to the user
  printf("Your sentence contains %d words.\n", wordCount);

  return 0;
}

int countWords(char* sentence) {
  int i, wordCount = 0, len = strlen(sentence);

  // Loop through the sentence and count the number of whitespace characters
  for (i = 0; i < len; i++) {
    if (sentence[i] == ' ') {
      wordCount++;
    }
  }

  // Add one to the word count for the final word in the sentence
  wordCount++;

  return wordCount;
}