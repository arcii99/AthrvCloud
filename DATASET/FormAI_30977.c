//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000

int positiveWordsCount = 0;
int negativeWordsCount = 0;

char* positiveWords[] = {"happy", "good", "love", "great", "excellent"};
char* negativeWords[] = {"sad", "bad", "hate", "terrible", "awful"};

void getSentiment(char* sentence) {
  char* word = strtok(sentence, " ");
  while(word != NULL) {
    for(int i = 0; i < 5; i++) {
      if(strcmp(word, positiveWords[i]) == 0) {
        positiveWordsCount++;
      }
      if(strcmp(word, negativeWords[i]) == 0) {
        negativeWordsCount++;
      }
    }
    word = strtok(NULL, " ");
  }
  if(positiveWordsCount > negativeWordsCount) {
    printf("Positive sentiment\n");
  } else if(negativeWordsCount > positiveWordsCount) {
    printf("Negative sentiment\n");
  } else {
    printf("Neutral sentiment\n");
  }
}

int main() {
  char sentence[MAX_SENTENCE_LENGTH] = "";
  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
  
  getSentiment(sentence);
  
  return 0;
}