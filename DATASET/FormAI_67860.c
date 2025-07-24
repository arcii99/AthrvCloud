//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  int score = 0;
  char *positive_words[5] = {"good", "great", "amazing", "fantastic", "excellent"};
  char *negative_words[5] = {"bad", "terrible", "horrible", "disappointing", "awful"};

  printf("Enter your sentence: ");
  fgets(input, 100, stdin);

  char *token = strtok(input, " ");
  while (token != NULL) {
    for (int i=0; i<5; i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        score++;
      }
      if (strcmp(token, negative_words[i]) == 0) {
        score--;
      }
    }
    token = strtok(NULL, " ");
  }

  if (score > 0) {
    printf("Positive sentiment detected with score of %d", score);
  } else if (score < 0) {
    printf("Negative sentiment detected with score of %d", score);
  } else {
    printf("Neutral sentiment detected");
  }

  return 0;
}