//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main () {

  char sentence[1000];
  int positive_words = 0, negative_words = 0;

  printf("Please enter a sentence: ");
  fgets(sentence, 1000, stdin); // read input sentence

  // list of positive and negative words
  char positive_list[10][20] = {"good", "great", "excellent", "happy", "love", "amazing", "fantastic", "wonderful", "nice", "awesome"};
  char negative_list[10][20] = {"bad", "poor", "terrible", "sad", "hate", "disgusting", "horrible", "awful", "ugly", "miserable"};

  // loop through the sentence to search for positive and negative words
  for (int i = 0; i < strlen(sentence); i++) {
    // check for positive words
    for (int j = 0; j < 10; j++) {
      if (strstr(&sentence[i], positive_list[j]) == &sentence[i]) {
        positive_words++;
        i += strlen(positive_list[j]) - 1;
      }
    }

    // check for negative words
    for (int k = 0; k < 10; k++) {
      if (strstr(&sentence[i], negative_list[k]) == &sentence[i]) {
        negative_words++;
        i += strlen(negative_list[k]) - 1;
      }
    }
  }

  // determine sentiment of the sentence based on number of positive and negative words
  if (positive_words > negative_words) {
    printf("\nPositive sentence!\n");
  } else if (negative_words > positive_words) {
    printf("\nNegative sentence!\n");
  } else {
    printf("\nNeutral sentence!\n");
  }

  return 0;
}