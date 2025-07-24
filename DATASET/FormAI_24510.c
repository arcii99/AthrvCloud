//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  int positiveWords = 0;
  int negativeWords = 0;
  int neutralWords = 0;

  printf("Enter a sentence: ");
  fgets(input, 100, stdin);

  // Create an array of positive words
  char positive[6][10] = {"good", "great", "amazing", "excellent", "awesome", "fantastic"};

  // Create an array of negative words
  char negative[6][10] = {"bad", "terrible", "horrible", "awful", "disappointing", "poor"};

  // Split the input sentence into words
  char *token = strtok(input, " ");
  while(token != NULL) {

    // Check if word is positive
    for(int i = 0; i < 6; i++) {
      if(strcmp(token, positive[i]) == 0) {
        positiveWords++;
      }
    }

    // Check if word is negative
    for(int i = 0; i < 6; i++) {
      if(strcmp(token, negative[i]) == 0) {
        negativeWords++;
      }
    }

    // Check if word is neutral
    if((!positiveWords && !negativeWords) || (positiveWords > 0 && negativeWords > 0)) {
      neutralWords++;
    }

    token = strtok(NULL, " ");
  }

  // Calculate sentiment
  if(positiveWords > negativeWords) {
    printf("Sentiment: Positive\n");
  } else if(negativeWords > positiveWords) {
    printf("Sentiment: Negative\n");
  } else {
    printf("Sentiment: Neutral\n");
  }

  // Print word counts
  printf("Positive words: %d\n", positiveWords);
  printf("Negative words: %d\n", negativeWords);
  printf("Neutral words: %d\n", neutralWords);

  return 0;
}