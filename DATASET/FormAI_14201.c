//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_STRING 1000
#define MAX_WORDS 100

char *positive_words[MAX_WORDS] = {"happy", "love", "awesome", "amazing", "exciting", "fantastic", "good", "great", "joy", "like"};
int num_positive_words = 10;

char *negative_words[MAX_WORDS] = {"sad", "hate", "awful", "terrible", "disgusting", "horrible", "bad", "difficult", "pain", "uncomfortable"};
int num_negative_words = 10;

int get_sentiment_score(char sentence[]) {
  char *token, *str;
  char copy_sen[MAX_STRING];
  int sentiment_score = 0;

  strcpy(copy_sen, sentence);
  str = copy_sen;

  token = strtok(str, " ");
  while (token != NULL) {
    for (int i=0; i<num_positive_words; i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        sentiment_score++;
      }
    }
    for (int i=0; i<num_negative_words; i++) {
      if (strcmp(token, negative_words[i]) == 0) {
        sentiment_score--;
      }
    }
    token = strtok(NULL, " ");
  }

  return sentiment_score;
}

int main() {
  char sentence[MAX_STRING];

  printf("Enter a sentence: ");
  fgets(sentence, MAX_STRING, stdin);
  
  int sentiment_score = get_sentiment_score(sentence);
  if (sentiment_score > 0) {
    printf("Sentiment: Positive (%d)\n", sentiment_score);
  } else if (sentiment_score < 0) {
    printf("Sentiment: Negative (%d)\n", sentiment_score);
  } else {
    printf("Sentiment: Neutral\n");
  }

  return 0;
}