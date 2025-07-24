//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100

int main() {
  char input_string[MAX_STRING_LENGTH];
  int score = 0;
  int positive_count = 0;
  int negative_count = 0;
  
  // Ask the user for input
  printf("Please enter a sentence or phrase for sentiment analysis:\n");
  fgets(input_string, MAX_STRING_LENGTH, stdin);

  // Check for positive and negative words
  char *positives[] = {"happy", "success", "love", "great", "nice", "awesome", "amazing"};
  char *negatives[] = {"disappointed", "failure", "hate", "horrible", "awful", "terrible", "bad"};
  char *word = strtok(input_string, " ");
  while (word != NULL) {
    for (int i = 0; i < 7; i++) {
      if (strcmp(word, positives[i]) == 0) {
        score++;
        positive_count++;
        break;
      }
      else if (strcmp(word, negatives[i]) == 0) {
        score--;
        negative_count++;
        break;
      }
    }
    word = strtok(NULL, " ");
  }

  // Determine overall sentiment
  printf("Positive words found: %d\n", positive_count);
  printf("Negative words found: %d\n", negative_count);
  if (score > 0) {
    printf("Overall sentiment is positive.");
  }
  else if (score < 0) {
    printf("Overall sentiment is negative.");
  }
  else {
    printf("Overall sentiment is neutral.");
  }

  return 0;
}