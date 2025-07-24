//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
/*
Welcome to the Sentiment Analysis Tool!
This program takes in text input from a user and analyzes the sentiment behind it using a scoring system.
It will then output a score from -10 to 10, with -10 being extremely negative and 10 being extremely positive.
*/

#include <stdio.h>
#include <string.h>

int main() {
  char input[1000]; // Max length of input is set to 1000 characters
  int sentiment_score = 0; // Sentiment score will start at 0

  printf("Welcome to the Sentiment Analysis Tool!\nPlease enter your text below:\n");

  // Take user input and remove newline character at the end
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = 0;

  // Iterate through each character in the input
  for (int i = 0; i < strlen(input); i++) {
    char current_char = input[i];

    // Check if the current character is a positive keyword
    if (current_char == 'h') {
      if (input[i+1] == 'a' && input[i+2] == 'p' && input[i+3] == 'p' && input[i+4] == 'y') {
        sentiment_score++;
      }
      else if (input[i+1] == 'e' && input[i+2] == 'a' && input[i+3] == 'l' && input[i+4] == 't' && input[i+5] == 'h' && input[i+6] == 'y') {
        sentiment_score++;
      }
    }
    else if (current_char == 'g') {
      if (input[i+1] == 'o' && input[i+2] == 'o' && input[i+3] == 'd') {
        sentiment_score++;
      }
      else if (input[i+1] == 'r' && input[i+2] == 'e' && input[i+3] == 'a' && input[i+4] == 't') {
        sentiment_score++;
      }
      else if (input[i+1] == 'r' && input[i+2] == 'e' && input[i+3] == 'a' && input[i+4] == 't' && input[i+5] == 'f' && input[i+6] == 'u' && input[i+7] == 'l') {
        sentiment_score++;
      }
    }

    // Check if the current character is a negative keyword
    else if (current_char == 'b') {
      if (input[i+1] == 'a' && input[i+2] == 'd') {
        sentiment_score--;
      }
      else if (input[i+1] == 'o' && input[i+2] == 'r' && input[i+3] == 'i' && input[i+4] == 'n' && input[i+5] == 'g') {
        sentiment_score--;
      }
    }
    else if (current_char == 't') {
      if (input[i+1] == 'e' && input[i+2] == 'r' && input[i+3] == 'r' && input[i+4] == 'i' && input[i+5] == 'b' && input[i+6] == 'l' && input[i+7] == 'e') {
        sentiment_score--;
      }
    }
  }

  // Print out the sentiment score
  printf("Your sentiment score is: %d\n", sentiment_score);

  return 0;
}