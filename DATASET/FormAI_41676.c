//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum length of input string
#define MAX_LEN 100

// function to determine sentiment of input string
int determineSentiment(char *inputStr) {
  int sentimentScore = 0;

  // list of positive words
  char *positiveWords[] = {"happy", "excited", "love", "great", "nice", "enjoy", "fun", "wonderful", "amazing", "awesome"};

  // list of negative words
  char *negativeWords[] = {"sad", "angry", "hate", "terrible", "dislike", "upset", "annoy", "negative", "frustrated", "disappoint"};

  // split input string into individual words
  char *word = strtok(inputStr, " ");

  // loop through each word in the string
  while (word != NULL) {

    // check if word is positive
    for (int i = 0; i < 10; i++) {
      if (strcmp(word, positiveWords[i]) == 0) {
        sentimentScore++;
      }
    }

    // check if word is negative
    for (int i = 0; i < 10; i++) {
      if (strcmp(word, negativeWords[i]) == 0) {
        sentimentScore--;
      }
    }

    // move to next word
    word = strtok(NULL, " ");
  }

  return sentimentScore;
}

int main() {
  char inputStr[MAX_LEN];
  int sentiment;

  // get input string from user
  printf("Enter a string: ");
  fgets(inputStr, MAX_LEN, stdin);

  // remove newline character from input string
  inputStr[strcspn(inputStr, "\n")] = 0;

  // determine sentiment score of input string
  sentiment = determineSentiment(inputStr);

  // print sentiment score
  printf("Sentiment score: %d\n", sentiment);

  // determine sentiment category
  if (sentiment > 0) {
    printf("Positive sentiment.\n");
  } else if (sentiment < 0) {
    printf("Negative sentiment.\n");
  } else {
    printf("Neutral sentiment.\n");
  }

  return 0;
}