//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *positive_words[] = {"good", "great", "awesome", "excellent", "nice", "fantastic"};
  int num_positive_words = sizeof(positive_words) / sizeof(char*);
  
  char *negative_words[] = {"bad", "terrible", "horrible", "awful", "poor", "miserable"};
  int num_negative_words = sizeof(negative_words) / sizeof(char*);
  
  char input[1000];
  printf("Enter a sentence: ");
  fgets(input, 1000, stdin);
  
  int positive_score = 0;
  int negative_score = 0;
  
  char *token = strtok(input, " ");
  while (token != NULL) {
    for (int i = 0; i < num_positive_words; i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        positive_score++;
      }
    }
    
    for (int i = 0; i < num_negative_words; i++) {
      if (strcmp(token, negative_words[i]) == 0) {
        negative_score++;
      }
    }
    
    token = strtok(NULL, " ");
  }
  
  if (positive_score > negative_score) {
    printf("Positive sentiment\n");
  } else if (negative_score > positive_score) {
    printf("Negative sentiment\n");
  } else {
    printf("Neutral sentiment\n");
  }
  
  return 0;
}