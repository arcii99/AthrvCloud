//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {

  char text[100];
  int happyCount = 0, sadCount = 0, neutralCount = 0;

  printf("Welcome to the Sentiment Analysis Tool!\n");

  printf("Type in some text and let me analyze the sentiment:\n");
  fgets(text, 100, stdin);

  char *word = strtok(text, " ");
  while (word != NULL) {
    if (strstr(word, "happy") != NULL || strstr(word, "excited") != NULL || strstr(word, "joyful") != NULL) {
      happyCount++;
    } else if (strstr(word, "sad") != NULL || strstr(word, "depressed") != NULL || strstr(word, "unhappy") != NULL) {
      sadCount++;
    } else {
      neutralCount++;
    }
    word = strtok(NULL, " ");
  }

  if (happyCount > sadCount && happyCount > neutralCount) {
    printf("Wow, you're a ray of sunshine! Your text has a positive sentiment.\n");
  } else if (sadCount > happyCount && sadCount > neutralCount) {
    printf("Cheer up, buttercup! Your text has a negative sentiment.\n");
  } else {
    printf("Your text is pretty neutral. It's neither good nor bad, just like Switzerland.\n");
  }

  return 0;
}