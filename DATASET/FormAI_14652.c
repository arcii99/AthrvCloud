//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

int main() {

  char input[MAX_INPUT_SIZE];
  char *positive_words[] = {"good", "great", "happy", "love", "excellent", "amazing"};
  char *negative_words[] = {"bad", "terrible", "unhappy", "hate", "poor", "awful"};
  int positive_count = 0;
  int negative_count = 0;

  printf("Enter your text: ");
  fgets(input, MAX_INPUT_SIZE, stdin);

  // Count positive words
  for(int i=0; i<sizeof(positive_words)/sizeof(positive_words[0]); i++) {
    if(strstr(input, positive_words[i]) != NULL) {
      positive_count++;
    }
  }

  // Count negative words
  for(int i=0; i<sizeof(negative_words)/sizeof(negative_words[0]); i++) {
    if(strstr(input, negative_words[i]) != NULL) {
      negative_count++;
    }
  }

  // Output sentiment score
  if(positive_count > negative_count) {
    printf("Positive sentiment score: %d\n", (positive_count-negative_count)*100/positive_count);
  } else if(negative_count > positive_count) {
    printf("Negative sentiment score: %d\n", (negative_count-positive_count)*100/negative_count);
  } else {
    printf("Neutral sentiment\n");
  }

  return 0;
}