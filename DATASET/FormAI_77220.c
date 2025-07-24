//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];

  printf("Enter a sentence for sentiment analysis: ");
  fgets(input, 100, stdin);

  // Remove newline character from input
  input[strcspn(input, "\n")] = '\0';

  // Split the input into words
  char* delim = " ";
  char* word;
  word = strtok(input, delim);

  int positive_count = 0;
  int negative_count = 0;

  // Loop through each word and determine sentiment
  while (word != NULL) {
    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
      positive_count++;
    } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "poor") == 0) {
      negative_count++;
    }

    word = strtok(NULL, delim);
  }

  // Determine overall sentiment based on word counts
  if (positive_count > negative_count) {
    printf("Overall sentiment: Positive\n");
  } else if (negative_count > positive_count) {
    printf("Overall sentiment: Negative\n");
  } else {
    printf("Overall sentiment: Neutral\n");
  }

  return 0;
}