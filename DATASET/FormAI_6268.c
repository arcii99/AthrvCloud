//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
  // Sentiment analysis matrix
  int sentimentMatrix[3][3] = {{-1, 0, 1},
                               {0, 1, -1},
                               {1, -1, 0}};

  // Test input sentence
  char *sentence = "This technology is amazing";

  // Remove punctuation
  char punctuation[] = ".,;:!?";
  for (int i = 0; i < strlen(punctuation); i++) {
    for (int j = 0; j < strlen(sentence); j++) {
      if (sentence[j] == punctuation[i]) {
        sentence[j] = ' ';
      }
    }
  }

  // Create array of words
  char *words[100];
  int wordCount = 0;
  words[wordCount] = strtok(sentence, " ");
  while (words[wordCount] != NULL) {
    wordCount++;
    words[wordCount] = strtok(NULL, " ");
  }

  // Calculate sentiment score
  int sentimentScore = 0;
  for (int i = 0; i < wordCount; i++) {
    if (strcmp(words[i], "amazing") == 0) {
      sentimentScore += sentimentMatrix[0][2];
    }
    else if (strcmp(words[i], "technology") == 0) {
      sentimentScore += sentimentMatrix[1][0];
    }
    else {
      sentimentScore += sentimentMatrix[1][1];
    }
  }

  // Determine sentiment
  if (sentimentScore > 0) {
    printf("Positive sentiment.\n");
  }
  else if (sentimentScore < 0) {
    printf("Negative sentiment.\n");
  }
  else {
    printf("Neutral sentiment.\n");
  }

  return 0;
}