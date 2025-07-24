//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mind-bending
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the Sentiment Analysis Tool!\n");
  
  // Get user input
  char text[100];
  printf("Please enter some text:\n");
  scanf("%s", text);
  
  // Analyze sentiment
  int sentiment_score = 0;
  for (int i = 0; i < strlen(text); i++) {
    char c = text[i];
    if (c == 'good') {
      sentiment_score++;
    } else if (c == 'bad') {
      sentiment_score--;
    }
  }
  
  // Output result
  if (sentiment_score > 0) {
    printf("That was a positive sentiment!\n");
  } else if (sentiment_score < 0) {
    printf("That was a negative sentiment.\n");
  } else {
    printf("That sentiment was neutral.\n");
  }
  
  return 0;
}