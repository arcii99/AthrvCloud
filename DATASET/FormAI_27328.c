//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to calculate sentiment score of a given word
int calculate_sentiment(char word[]) {
  int score = 0;

  // List of positive and negative words
  char positive_words[][20] = {"love", "hope", "happy", "excited", "joy"};
  char negative_words[][20] = {"hate", "pain", "sorrow", "angry", "fear"};

  // Check if the given word is positive or negative
  int i;
  for (i = 0; i < 5; i++) {
    if (strcmp(word, positive_words[i]) == 0) {
      score = 1;
      break;
    }
    else if (strcmp(word, negative_words[i]) == 0) {
      score = -1;
      break;
    }
  }

  return score;
}

int main() {
  char text[1000];
  printf("Enter the text you want to analyse: ");
  fgets(text, 1000, stdin);

  int sentiment_score = 0;
  char *word = strtok(text, " \t\n");

  // Iterate through each word in the given text
  while (word != NULL) {
    // Calculate sentiment score of current word
    int score = calculate_sentiment(word);
    sentiment_score += score;
    word = strtok(NULL, " \t\n");
  }

  // Determine overall sentiment of the given text
  if (sentiment_score > 0) {
    printf("The given text is positive.");
  }
  else if (sentiment_score < 0) {
    printf("The given text is negative.");
  }
  else {
    printf("The given text is neutral.");
  }

  return 0;
}