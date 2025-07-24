//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {

  char sentence[1000];
  int positiveCount = 0;
  int negativeCount = 0;

  // Prompt user to enter a sentence
  printf("Enter a sentence: ");
  fgets(sentence, 1000, stdin);

  // Convert the sentence to lowercase
  for (int i = 0; i < strlen(sentence); i++) {
    sentence[i] = tolower(sentence[i]);
  }

  // Remove any punctuation from the sentence
  for (int i = 0; i < strlen(sentence); i++) {
    if (ispunct(sentence[i])) {
      for (int j = i; j < strlen(sentence); j++) {
        sentence[j] = sentence[j + 1];
      }
    }
  }

  // Tokenize the sentence into words
  char *word = strtok(sentence, " ");

  while (word != NULL) {
    // Check if the word is positive or negative
    if (strcmp(word, "good") == 0 || strcmp(word, "happy") == 0 || strcmp(word, "great") == 0) {
      positiveCount++;
    } else if (strcmp(word, "bad") == 0 || strcmp(word, "sad") == 0 || strcmp(word, "terrible") == 0) {
      negativeCount++;
    }

    word = strtok(NULL, " ");
  }

  // Determine the sentiment of the sentence
  if (positiveCount > negativeCount) {
    printf("The sentence is positive.\n");
  } else if (negativeCount > positiveCount) {
    printf("The sentence is negative.\n");
  } else {
    printf("The sentence is neutral.\n");
  }

  return 0;
}