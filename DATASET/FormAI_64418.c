//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: introspective
#include <stdio.h>

int main() {
  printf("Welcome to my Sentiment Analysis Tool!\n");
  printf("Please enter a sentence: ");
  char sentence[100];
  fgets(sentence, 100, stdin);
  int positive = 0;
  int negative = 0;
  int neutral = 0;
  
  for(int i = 0; sentence[i] != '\0'; i++) {
    if(sentence[i] == 'good' || sentence[i] == 'great' || sentence[i] == 'excellent') {
      positive++;
    } else if(sentence[i] == 'bad' || sentence[i] == 'awful' || sentence[i] == 'terrible') {
      negative++;
    } else {
      neutral++;
    }
  }
  
  if(positive > negative) {
    printf("This sentence has a positive sentiment!\n");
  } else if(negative > positive) {
    printf("This sentence has a negative sentiment.\n");
  } else {
    printf("This sentence has a neutral sentiment.\n");
  }
  
  printf("Positive words: %d\n", positive);
  printf("Negative words: %d\n", negative);
  printf("Neutral words: %d\n", neutral);
  
  return 0;
}