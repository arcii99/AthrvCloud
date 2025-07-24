//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char sentence[1000];
  int positiveWords = 0, negativeWords = 0;

  printf("Enter a sentence: \n");
  fgets(sentence, 1000, stdin);

  char *word = strtok(sentence, " ");
  while (word != NULL) {
    if (strstr("happy joy love good great", word) != NULL) {
      positiveWords++;
    } else if (strstr("sad hate fear bad terrible", word) != NULL) {
      negativeWords++;
    }
    word = strtok(NULL, " ");
  }

  if (positiveWords > negativeWords) {
    printf("This sentence has a positive sentiment.\n");
  } else if (negativeWords > positiveWords) {
    printf("This sentence has a negative sentiment.\n");
  } else {
    printf("It's hard to determine the sentiment of this sentence.\n");
  }

  return 0;
}