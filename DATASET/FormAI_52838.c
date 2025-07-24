//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1000];

  printf("Enter a sentence: ");
  fgets(sentence, 1000, stdin);

  int positive_count = 0;
  int negative_count = 0;
  int neutral_count = 0;

  char *positive_words[] = {"good", "happy", "awesome", "love", "excellent"};
  char *negative_words[] = {"bad", "sad", "terrible", "hate", "dislike", "awful"};
  
  char *word = strtok(sentence, " .,!?\n");

  while (word != NULL) {
    for (int i = 0; i < 5; i++) {
      if (strcmp(word, positive_words[i]) == 0) {
        positive_count++;
      }
      if (strcmp(word, negative_words[i]) == 0) {
        negative_count++;
      }
    }
    word = strtok(NULL, " .,!?\n");
  }

  neutral_count = strlen(sentence) - (positive_count + negative_count);

  printf("\nTotal number of sentiment words: %d\n", positive_count + negative_count);
  printf("Number of positive words: %d\n", positive_count);
  printf("Number of negative words: %d\n", negative_count);
  printf("Number of neutral words: %d\n", neutral_count);

  if (positive_count > negative_count) {
    printf("Overall sentiment is positive.\n");
  } else if (negative_count > positive_count) {
    printf("Overall sentiment is negative.\n");
  } else {
    printf("Overall sentiment is neutral.\n");
  }

  return 0;
}