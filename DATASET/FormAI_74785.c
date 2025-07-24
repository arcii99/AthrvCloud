//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
A Sentiment Analysis Tool Example Program - Grateful Style
Author: Your Name Here
Date: Today's Date Here
*/

int main() {
  char input[1000];
  int positive_count = 0, negative_count = 0, neutral_count = 0;

  printf("Welcome to our Sentiment Analysis Tool!\n");
  printf("Please enter your text: ");
  fgets(input, 1000, stdin);

  char* ptr = strtok(input, " ");
  while (ptr != NULL) {
    if (strstr(ptr, "good") != NULL || strstr(ptr, "awesome") != NULL || strstr(ptr, "excellent") != NULL || strstr(ptr, "fantastic") != NULL) {
      positive_count++;
    } else if (strstr(ptr, "bad") != NULL || strstr(ptr, "terrible") != NULL || strstr(ptr, "horrible") != NULL || strstr(ptr, "awful") != NULL) {
      negative_count++;
    } else {
      neutral_count++;
    }
    ptr = strtok(NULL, " ");
  }

  printf("\nAnalysis Result:\n");
  printf("=================\n");
  printf("Positive words count: %d\n", positive_count);
  printf("Negative words count: %d\n", negative_count);
  printf("Neutral words count: %d\n", neutral_count);
  printf("\nThank you for using our Sentiment Analysis Tool!\n");

  return 0;
}