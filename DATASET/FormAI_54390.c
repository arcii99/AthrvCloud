//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int main() {
  printf("Welcome to the Sentiment Analysis Tool!\n");
  printf("Please input your text:\n");
  char text[1000];
  fgets(text, 1000, stdin);
  int sentiment_score = 0;

  // Analyzing the sentiment of the input text
  char* token = strtok(text, " ");
  while (token != NULL) {
    if (strstr(token, "good") || strstr(token, "great") || strstr(token, "excellent") || strstr(token, "awesome")) {
      sentiment_score += 2;
    }
    else if (strstr(token, "bad") || strstr(token, "terrible") || strstr(token, "awful") || strstr(token, "horrible")) {
      sentiment_score -= 2;
    }
    else if (strstr(token, "like") || strstr(token, "love") || strstr(token, "enjoy")) {
      sentiment_score += 1;
    }
    else if (strstr(token, "dislike") || strstr(token, "hate") || strstr(token, "annoy")) {
      sentiment_score -= 1;
    }
    token = strtok(NULL, " ");
  }

  // Printing the sentiment score
  printf("The sentiment score of the text is: %d\n", sentiment_score);

  // Determining the overall sentiment of the text
  if (sentiment_score > 0) {
    printf("The overall sentiment of the text is positive!\n");
  }
  else if (sentiment_score < 0) {
    printf("The overall sentiment of the text is negative!\n");
  }
  else {
    printf("The overall sentiment of the text is neutral!\n");
  }

  return 0;
}