//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1000];
  printf("Enter a sentence:\n");
  fgets(input, 1000, stdin);

  // Check for positive words
  char *positive_list[] = {"good", "great", "amazing", "awesome", "fantastic", "excellent", "top-notch", "superb", "terrific"};
  int num_positive = sizeof(positive_list) / sizeof(positive_list[0]);
  
  int positive_count = 0;
  char *positive_word = strtok(input, " ,.-\n");
  while (positive_word != NULL) {
    for (int i = 0; i < num_positive; i++) {
      if (strcmp(positive_word, positive_list[i]) == 0) {
        positive_count++;
        break;
      }
    }
    positive_word = strtok(NULL, " ,.-\n");
  }

  // Check for negative words
  char *negative_list[] = {"bad", "terrible", "horrible", "awful", "disappointing", "poor", "mediocre", "lousy"};
  int num_negative = sizeof(negative_list) / sizeof(negative_list[0]);
  
  int negative_count = 0;
  char *negative_word = strtok(input, " ,.-\n");
  while (negative_word != NULL) {
    for (int i = 0; i < num_negative; i++) {
      if (strcmp(negative_word, negative_list[i]) == 0) {
        negative_count++;
        break;
      }
    }
    negative_word = strtok(NULL, " ,.-\n");
  }

  // Determine sentiment
  if (positive_count > negative_count) {
    printf("Sentiment: Positive");
  } else if (negative_count > positive_count) {
    printf("Sentiment: Negative");
  } else {
    printf("Sentiment: Neutral");
  }

  return 0;
}