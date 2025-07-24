//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char sentence[1000];
  printf("Enter any sentence:\n");
  scanf("%[^\n]s", sentence);

  int happyCount = 0;
  int sadCount = 0;
  int i = 0;

  char *word = strtok(sentence, " ");
  
  while (word != NULL) {
    if (strcmp(word, "happy") == 0 || strcmp(word, "smile") == 0 || strcmp(word, "love") == 0 || strcmp(word, "great") == 0) {
      happyCount++;
    }
    if (strcmp(word, "sad") == 0 || strcmp(word, "cry") == 0 || strcmp(word, "hate") == 0 || strcmp(word, "worst") == 0) {
      sadCount++;
    }
    word = strtok(NULL, " ");
    i++;
  }

  if (happyCount > sadCount) {
    printf("This sentence has a positive sentiment.\n");
  } else if (happyCount < sadCount) {
    printf("This sentence has a negative sentiment.\n");
  } else {
    printf("This sentence has a neutral sentiment.\n");
  }

  return 0;
}