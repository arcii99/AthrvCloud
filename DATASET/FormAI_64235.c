//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 1000

int main() {

  char input_str[MAX_STRING_LEN];
  printf("Enter a sentence:\n");
  
  fgets(input_str, MAX_STRING_LEN, stdin);
  
  int positive_terms = 0;
  int negative_terms = 0;
  
  // Positive terms
  char *positive[] = {"good", "great", "excellent", "awesome", "fantastic"};

  // Negative terms
  char *negative[] = {"bad", "terrible", "horrible", "awful", "poor"};

  char *token = strtok(input_str, " ,.-"); // Split the sentence up into words

  while(token != NULL) {

    // Check for positive term
    for(int i = 0; i < 5; i++) {
      if (strcmp(token, positive[i]) == 0) { // String comparison
        positive_terms++;
        break; // Found a positive term, no need to keep looping
      }
    }

    // Check for negative term
    for(int i = 0; i < 5; i++) {
      if (strcmp(token, negative[i]) == 0) { // String comparison
        negative_terms++;
        break; // Found a negative term, no need to keep looping
      }
    }

    token = strtok(NULL, " ,.-"); // Move to next token
  }

  if (positive_terms > negative_terms) {
    printf("Wow, what a positive statement! You used %d positive terms and %d negative terms.\n", positive_terms, negative_terms);
  } else if (positive_terms < negative_terms) {
    printf("Oh no! Your statement was negative. You used %d positive terms and %d negative terms.\n", positive_terms, negative_terms);
  } else {
    printf("Your statement was neutral. You used %d positive terms and %d negative terms.\n", positive_terms, negative_terms);
  }

  return 0;
}