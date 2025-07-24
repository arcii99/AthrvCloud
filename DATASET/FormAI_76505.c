//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// A function to calculate sentiment score of a sentence
int calculateSentiment(char sentence[]) {
  // Define positive and negative word sets
  char *positiveWords[] = {"good", "great", "awesome", "excellent", "happy", "love", "like"};
  char *negativeWords[] = {"bad", "terrible", "horrible", "awful", "angry", "hate", "dislike"};

  int len = strlen(sentence);
  int sentimentScore = 0;
  char *word;

  // Split the sentence by space and analyze each word
  word = strtok(sentence, " ");
  while (word != NULL) {
    // Check if the current word is in either positive or negative word set
    for (int i = 0; i < 7; i++) {
      if (strcmp(word, positiveWords[i]) == 0) {
        sentimentScore++;
        break;
      }
      else if (strcmp(word, negativeWords[i]) == 0) {
        sentimentScore--;
        break;
      }
    }
    // Get next word
    word = strtok(NULL, " ");
  }

  return sentimentScore;
}

int main() {
  char sentence[100];

  printf("Enter a sentence: ");
  fgets(sentence, 100, stdin);

  int sentimentScore = calculateSentiment(sentence);

  printf("Sentiment score: %d\n", sentimentScore);

  if (sentimentScore > 0) {
    printf("Overall sentiment: Positive");
  }
  else if (sentimentScore < 0) {
    printf("Overall sentiment: Negative");
  }
  else {
    printf("Overall sentiment: Neutral");
  }

  return 0;
}