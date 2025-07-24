//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sentiment {
  int positive;
  int negative;
  int neutral;
};

void analyze_sentence(char sentence[], struct sentiment *result) {
  //convert sentence to lowercase
  char lowercase_sentence[100];
  int i=0;
  while(sentence[i]) {
    lowercase_sentence[i] = tolower(sentence[i]);
    i++;
  }
  lowercase_sentence[i] = '\0';

  char positive_words[4][10] = {"happy", "excited", "good", "great"};
  char negative_words[4][10] = {"sad", "angry", "bad", "horrible"};

  int positive_count = 0, negative_count = 0;

  //check for positive words
  for(int i=0; i<4; i++) {
    if(strstr(lowercase_sentence, positive_words[i]) != NULL) {
      positive_count++;
    }
  }

  //check for negative words
  for(int i=0; i<4; i++) {
    if(strstr(lowercase_sentence, negative_words[i]) != NULL) {
      negative_count++;
    }
  }

  if(positive_count > negative_count) {
    result->positive++;
  }
  else if(negative_count > positive_count) {
    result->negative++;
  }
  else {
    result->neutral++;
  }
}

int main() {
  char input_sentence[100];
  struct sentiment result = {0, 0, 0};

  printf("Enter a sentence: ");
  fgets(input_sentence, sizeof(input_sentence), stdin);
  analyze_sentence(input_sentence, &result);

  printf("Analysis result:\n");
  printf("Positive: %d\n", result.positive);
  printf("Negative: %d\n", result.negative);
  printf("Neutral: %d\n", result.neutral);

  return 0;
}