//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1000];
  int sentiment = 0; //initialize sentiment score to 0
  char *pos_words[10] = {"awesome", "good", "great", "fantastic", "excellent", "beautiful", "amazing", "wonderful", "love", "like"}; //list of positive words
  char *neg_words[10] = {"bad", "terrible", "awful", "horrible", "lousy", "poor", "disappointing", "hate", "not good", "not great"}; //list of negative words
  printf("Welcome to our Sentiment Analysis Tool!\n");
  printf("Please enter your input: ");
  fgets(input, sizeof(input), stdin); //take input from user
  
  //search for positive words in input
  for (int i = 0; i < 10; i++) {
    if (strstr(input, pos_words[i]) != NULL) //if positive word is found
      sentiment++; //increase sentiment score by 1
  }
  
  //search for negative words in input
  for (int i = 0; i < 10; i++) {
    if (strstr(input, neg_words[i]) != NULL) //if negative word is found
      sentiment--; //decrease sentiment score by 1
  }
  
  //evaluate sentiment score and print output
  if (sentiment > 0) printf("Your input has a positive sentiment!\n");
  else if (sentiment < 0) printf("Your input has a negative sentiment.\n");
  else printf("Your input has a neutral sentiment.\n");
  
  return 0;
}