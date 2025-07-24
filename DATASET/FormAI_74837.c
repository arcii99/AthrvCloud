//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1000];
  int i, positive_count = 0, negative_count = 0;

  printf("Enter a sentence to analyze: ");
  scanf("%[^\n]s", sentence);

  char positive_words[][20] = {"good", "great", "excellent", "amazing", "love", "happy", "fantastic"};
  char negative_words[][20] = {"bad", "terrible", "awful", "hate", "sad", "disappoint", "worst"};

  char *token = strtok(sentence, " ");
  while (token != NULL) {
    for (i = 0; i < sizeof(positive_words) / sizeof(positive_words[0]); i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        positive_count++;
      }
    }
    for (i = 0; i < sizeof(negative_words) / sizeof(negative_words[0]); i++) {
      if (strcmp(token, negative_words[i]) == 0) {
        negative_count++;
      }
    }
    token = strtok(NULL, " ");
  }

  printf("\nPositive words count: %d", positive_count);
  printf("\nNegative words count: %d", negative_count);

  if (positive_count > negative_count) {
    printf("\nOverall sentiment: Positive");
  } else if (positive_count < negative_count) {
    printf("\nOverall sentiment: Negative");
  } else {
    printf("\nOverall sentiment: Neutral");
  }

  return 0;
}