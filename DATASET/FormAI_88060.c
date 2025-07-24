//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int positiveCount = 0, negativeCount = 0, neutralCount = 0;
  char feedback[1000];
  printf("Enter feedback: ");
  fgets(feedback, 1000, stdin);
  char* words = strtok(feedback, " \n");
  while(words != NULL)
  {
    if(strcmp(words, "good") == 0 || strcmp(words, "great") == 0 || strcmp(words, "excellent") == 0)
      positiveCount++;
    else if(strcmp(words, "bad") == 0 || strcmp(words, "poor") == 0 || strcmp(words, "terrible") == 0)
      negativeCount++;
    else
      neutralCount++;
    words = strtok(NULL, " \n");
  }
  float positivePercentage = ((float)positiveCount/strlen(feedback))*100;
  float negativePercentage = ((float)negativeCount/strlen(feedback))*100;
  float neutralPercentage = ((float)neutralCount/strlen(feedback))*100;
  printf("\nPositive: %.2f%%", positivePercentage);
  printf("\nNegative: %.2f%%", negativePercentage);
  printf("\nNeutral: %.2f%%", neutralPercentage);
  return 0;
}