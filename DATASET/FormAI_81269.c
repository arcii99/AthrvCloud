//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Sentiment Analysis Tool Example Program in C
  By: [Your Name]
  Date: [Current Date]

  This program takes an input string and analyzes the sentiment of each word in the string.
  It then prints out the sentiment analysis for each word as a positive, negative, or neutral score.

  Disclaimer: This program is for educational purposes only and is not intended for commercial use.
*/

int main() {
  
  // Define variables
  char input[1000]; // Input string
  int posScore = 0; // Positive score 
  int negScore = 0; // Negative score
  int neutralScore = 0; // Neutral score

  // Get input from user
  printf("Enter text to analyze: ");
  fgets(input, 1000, stdin);

  // Remove newline character from input
  input[strcspn(input, "\n")] = 0;

  // Tokenize input string
  char *token = strtok(input, " ");

  // Loop through tokens and analyze sentiment
  while (token != NULL) {

    // Compare token to positive words
    if (strcmp(token, "good") == 0 ||
        strcmp(token, "great") == 0 ||
        strcmp(token, "excellent") == 0 ||
        strcmp(token, "amazing") == 0 ||
        strcmp(token, "awesome") == 0 ||
        strcmp(token, "fantastic") == 0) {
      posScore++;
    }

    // Compare token to negative words
    else if (strcmp(token, "bad") == 0 ||
             strcmp(token, "terrible") == 0 ||
             strcmp(token, "horrible") == 0 ||
             strcmp(token, "awful") == 0 ||
             strcmp(token, "poor") == 0 ||
             strcmp(token, "disappointing") == 0) {
      negScore++;
    }

    // Token is neutral
    else {
      neutralScore++;
    }

    // Get next token
    token = strtok(NULL, " ");
  }

  // Print out sentiment analysis
  printf("\nSentiment Analysis:\n");
  printf("Positive: %d\n", posScore);
  printf("Negative: %d\n", negScore);
  printf("Neutral: %d\n", neutralScore);

  // End of program
  printf("\nPress any key to continue...");
  getchar();
  return 0;
}