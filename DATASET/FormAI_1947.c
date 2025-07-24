//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  printf("Enter a sentence: ");
  fgets(input, sizeof(input), stdin);

  int positive_count = 0;
  int negative_count = 0;

  char positive_words[10][15] = {"great", "awesome", "excellent", "fantastic", "amazing", "good", "love", "happy", "best", "nice"};

  char negative_words[10][15] = {"bad", "terrible", "awful", "disappointing", "poor", "hate", "sad", "worst", "annoying", "disgusting"};

  char *token = strtok(input, " ");

  while (token != NULL) {
    for (int i = 0; i < 10; i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        positive_count++;
      } else if (strcmp(token, negative_words[i]) == 0) {
        negative_count++;
      }
    }
    token = strtok(NULL, " ");
  }

  printf("\nPositive words count: %d", positive_count);
  printf("\nNegative words count: %d", negative_count);

  if (positive_count > negative_count) {
    printf("\nThis sentence is positive.");
  } else if (negative_count > positive_count) {
    printf("\nThis sentence is negative.");
  } else {
    printf("\nThis sentence is neutral.");
  }

  return 0;
}