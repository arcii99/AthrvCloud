//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void analyze_sentiment(char* review);

int main() {
  char review[500];
  
  printf("Please enter your review: ");
  fgets(review, 500, stdin);
  
  analyze_sentiment(review);
  
  return 0;
}

void analyze_sentiment(char* review) {
  int positive_count = 0;
  int negative_count = 0;
  
  char* word = strtok(review, " .,;:!?");
  while(word != NULL) {
    int flag = 0;
    for(int i = 0; i < strlen(word); i++) {
      if(!isalpha(word[i])) {
        flag = 1;
        break;
      }
      word[i] = tolower(word[i]);
    }
    
    if(flag) {
      word = strtok(NULL, " .,;:!?");
      continue;
    }
    
    if(strcmp(word, "good") == 0 || strcmp(word, "excellent") == 0 || strcmp(word, "nice") == 0) {
      positive_count++;
    } else if(strcmp(word, "bad") == 0 || strcmp(word, "horrible") == 0 || strcmp(word, "worst") == 0) {
      negative_count++;
    }
    
    word = strtok(NULL, " .,;:!?");
  }
  
  if(positive_count == 0 && negative_count == 0) {
    printf("The review is neutral.");
  } else if(positive_count > negative_count) {
    printf("The review is positive.");
  } else {
    printf("The review is negative.");
  }
}