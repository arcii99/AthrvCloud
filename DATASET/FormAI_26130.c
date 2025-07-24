//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[500];
  int sentimentScore = 0;

  printf("Greetings, my dear Watson. Do you have a sentence for us to analyze?\n");
  fgets(sentence, 500, stdin);

  printf("Let me take a closer look at what you have given us...\n");

  char* token = strtok(sentence, " ");

  while (token != NULL) {
    // Check for positive words
    if (strcmp(token, "happy") == 0 || strcmp(token, "joyful") == 0 || strcmp(token, "excited") == 0 || strcmp(token, "pleased") == 0) {
      sentimentScore += 2;
    } else if (strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "awesome") == 0) {
      sentimentScore += 1;
    }

    // Check for negative words
    if (strcmp(token, "sad") == 0 || strcmp(token, "unhappy") == 0 || strcmp(token, "depressed") == 0 || strcmp(token, "disappointed") == 0) {
      sentimentScore -= 2;
    } else if (strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "awful") == 0) {
      sentimentScore -= 1;
    }

    token = strtok(NULL, " ");
  }

  printf("Based on my analysis, the sentiment score of this sentence is: %d\n", sentimentScore);

  if (sentimentScore > 0) {
    printf("This appears to be a positive statement. Well done, Watson!\n");
  } else if (sentimentScore < 0) {
    printf("This appears to be a negative statement. We may need to investigate further, Watson!\n");
  } else {
    printf("This statement seems to have a neutral sentiment.\n");
  }

  return 0;
}