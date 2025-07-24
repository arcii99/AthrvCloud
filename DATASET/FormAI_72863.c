//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  int count = 0;
  float score = 0;

  printf("Enter text to analyze sentiment:\n");
  fgets(input, 100, stdin);

  // remove newline character from input
  char *pos;
  if ((pos=strchr(input, '\n')) != NULL)
      *pos = '\0';

  // tokenize input by space
  char *token = strtok(input, " ");
  while (token != NULL) {
    // check if token is negative and modify score accordingly
    if (strcmp(token, "hate") == 0 || strcmp(token, "dislike") == 0)
      score--;
    // check if token is positive and modify score accordingly
    else if (strcmp(token, "love") == 0 || strcmp(token, "like") == 0)
      score++;
    count++;
    token = strtok(NULL, " ");
  }

  // calculate final sentiment score
  score /= count;
  printf("Sentiment score: %.2f\n", score);

  // determine sentiment classification
  if (score < -0.5)
    printf("The text has a very negative sentiment.\n");
  else if (score < 0)
    printf("The text has a negative sentiment.\n");
  else if (score < 0.5)
    printf("The text has a neutral sentiment.\n");
  else
    printf("The text has a positive sentiment.\n");

  return 0;
}