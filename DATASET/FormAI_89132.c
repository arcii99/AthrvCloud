//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
/*
Author: Dennis Ritchie
Date: 5-Oct-2021
Description: A sentiment analysis tool using C Language
*/

#include <stdio.h>
#include <string.h>

// Function for sentiment analysis
int sentiment_analysis(char *sentence)
{
  int score = 0;
  char positiveWords[10][15] = {"good", "great", "awesome", "excellent", "fantastic", "nice", "superb", "happy", "love", "amazing"};
  char negativeWords[10][15] = {"bad", "terrible", "horrible", "awful", "poor", "dislike", "unfortunate", "hate", "sad", "disappoint"};

  char *word = strtok(sentence, " ");
  
  while (word != NULL)
  {
    for (int i = 0; i < 10; i++)
    {
      if (strcmp(word, positiveWords[i]) == 0)
      {
        score++;
      }
      
      if (strcmp(word, negativeWords[i]) == 0)
      {
        score--;
      }
    }
    
    word = strtok(NULL, " ");
  }
  
  return score;
}

// Main function
int main()
{
  char sentence[200];
  
  printf("Enter a sentence to get its sentiment score:\n");
  fgets(sentence, 200, stdin);  // get input from user
  
  int score = sentiment_analysis(sentence);  // call sentiment_analysis function
  
  printf("\nSentiment score: %d\n", score);
  
  if (score > 0)
  {
    printf("It's a positive sentence.\n");
  }
  else if (score < 0)
  {
    printf("It's a negative sentence.\n");
  }
  else
  {
    printf("It's a neutral sentence.\n");
  }
  
  return 0;
}