//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  int positive_count = 0, negative_count = 0;

  printf("Enter a sentence: ");
  fgets(sentence, 100, stdin);  /* Get input from user */

  char *word = strtok(sentence, " ");  /* Split input into words */
  while (word != NULL) {
    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 ||
        strcmp(word, "excellent") == 0 || strcmp(word, "awesome") == 0) {
      positive_count++;  /* Count positive words */
    } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 ||
               strcmp(word, "horrible") == 0 || strcmp(word, "awful") == 0) {
      negative_count++;  /* Count negative words */
    }
    word = strtok(NULL, " ");
  }

  /* Determine overall sentiment */
  if (positive_count > negative_count) {
    printf("This sentence has a positive sentiment.\n");
  } else if (negative_count > positive_count) {
    printf("This sentence has a negative sentiment.\n");
  } else {
    printf("This sentence has a neutral sentiment.\n");
  }

  return 0;
}