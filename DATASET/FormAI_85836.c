//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Prompt user for input
  printf("Enter a sentence: ");
  char sentence[1000];
  fgets(sentence, 1000, stdin);

  // Convert sentence to lowercase
  int i;
  for (i = 0; sentence[i]; i++) {
    sentence[i] = tolower(sentence[i]);
  }

  // Remove punctuation from sentence
  int len = strlen(sentence);
  for (i = 0; i < len; i++) {
    if (sentence[i] == '.' || sentence[i] == ',' || sentence[i] == '?' || sentence[i] == '!') {
      sentence[i] = ' ';
    }
  }

  // Split sentence into words
  char *word;
  char *words[1000];
  int count = 0;
  word = strtok(sentence, " ");
  while (word != NULL) {
    words[count] = word;
    count++;
    word = strtok(NULL, " ");
  }

  // Count number of positive and negative words
  char positive_words[][20] = {"good", "great", "excellent", "fantastic", "amazing"};
  char negative_words[][20] = {"bad", "terrible", "poor", "awful", "horrible"};
  int positive_count = 0;
  int negative_count = 0;
  for (i = 0; i < count; i++) {
    int j;
    for (j = 0; j < 5; j++) {
      if (strcmp(words[i], positive_words[j]) == 0) {
        positive_count++;
      }
      if (strcmp(words[i], negative_words[j]) == 0) {
        negative_count++;
      }
    }
  }

  // Determine sentiment and output result
  printf("\nSentiment Analysis Result:\n");
  if (positive_count > negative_count) {
    printf("Positive\n");
  } else if (positive_count < negative_count) {
    printf("Negative\n");
  } else {
    printf("Neutral\n");
  }

  return 0;
}