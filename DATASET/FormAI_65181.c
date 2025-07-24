//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char input[100];
  int pos = 0, neg = 0, neut = 0;

  printf("Welcome to the Love-O-Meter!\nEnter your text here (max of 100 characters): ");
  fgets(input, 100, stdin);

  char *goodWords[] = {"love", "happy", "smile", "heartbeat", "kiss", "romantic", "sunshine", "warm", "cuddle"};
  char *badWords[] = {"hate", "sad", "angry", "tears", "breakup", "lonely", "cold", "apathy", "fight"};

  //Splitting input string into tokens
  char *token = strtok(input, " ,.-\n");

  while (token != NULL)
  {
      for(int i=0;i<9;i++)
      {
          if(strcmp(token,goodWords[i])==0)
          {
              pos++;
          }
          else if(strcmp(token,badWords[i])==0)
          {
              neg++;
          }
      }
      token = strtok(NULL, " ,.-\n");
  }

  neut = strlen(input) - pos - neg;

  //Printing emotional analysis
  printf("\nEmotional Analysis:\nPositive Sentiments: %d\nNegative Sentiments: %d\nNeutral Sentiments: %d\n", pos, neg, neut);

  printf("\n");
  return 0;
}