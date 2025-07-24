//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Hello! I'm your curious C Sentiment Analysis tool. \n");
  printf("Please enter a string to analyze: ");

  char input[100];
  fgets(input, 100, stdin); // gets user input
  input[strcspn(input, "\n")] = 0; // removes newline character

  int sentimentScore = 0;
  int i = 0;
  int wordCount = 0;
  while (input[i] != '\0') { // iterate through user input
    while (input[i] == ' ') { // skip whitespace
      i++;
    }
    if (input[i] == '\0') { // check for end of input
      break;
    }
    char currentWord[15];
    int j = 0;
    while (input[i] != ' ' && input[i] != '\0') { // add characters to current word
      currentWord[j] = input[i];
      i++;
      j++;
    }
    currentWord[j] = '\0'; // terminate string
    wordCount++;
    if (strcmp(currentWord, "good") == 0) { // add score for "good"
      sentimentScore++;
    }
    if (strcmp(currentWord, "bad") == 0) { // subtract score for "bad"
      sentimentScore--;
    }
  }

  if (wordCount == 0) { // handle empty input
    printf("You didn't enter anything!");
  } else if (sentimentScore == 0) { // neutral sentiment
    printf("Your input is neutral.");
  } else if (sentimentScore > 0) { // positive sentiment
    printf("Your input is positive!");
    for (int i = 0; i < sentimentScore; i++) { // print happy faces corresponding to score
      printf(":)");
    }
  } else { // negative sentiment
    printf("Your input is negative :(");
    for (int i = 0; i < abs(sentimentScore); i++) { // print sad faces corresponding to score
      printf(":(");
    }
  }
  return 0;
}