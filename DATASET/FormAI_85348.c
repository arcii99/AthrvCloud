//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char sentence[100];
  int sentiment_score = 0;
  int positive_count = 0, negative_count = 0;

  printf("Enter a sentence: ");
  fgets(sentence, 100, stdin);

  // Remove trailing newline character
  sentence[strcspn(sentence, "\n")] = 0;

  // Convert sentence to lowercase
  for (int i = 0; sentence[i]; i++) {
    sentence[i] = tolower(sentence[i]);
  }

  // Split sentence into words using whitespace as delimiter
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    // Check if word is positive or negative
    if (strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "happy") == 0) {
      positive_count++;
      sentiment_score += 1;
    } else if (strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "sad") == 0) {
      negative_count++;
      sentiment_score -= 1;
    }
    token = strtok(NULL, " ");
  }

  // Display sentiment analysis result
  printf("\nSentiment analysis of the sentence \"%s\":\n", sentence);
  printf("Positive words: %d\n", positive_count);
  printf("Negative words: %d\n", negative_count);
  if (sentiment_score > 0) {
    printf("Overall sentiment score: +%d (Positive)\n", sentiment_score);
  } else if (sentiment_score < 0) {
    printf("Overall sentiment score: %d (Negative)\n", sentiment_score);
  } else {
    printf("Overall sentiment score: 0 (Neutral)\n");
  }

  return 0;
}