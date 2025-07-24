//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function declaration for sentiment analysis
void analyze_sentiment(char*);

int main()
{
   char input[2000];

   // Taking input from user
   printf("Enter the text to analyze sentiment: \n");
   fgets(input, 2000, stdin);

   // Calling sentiment analysis function
   analyze_sentiment(input);

   return 0;
}

void analyze_sentiment(char* input)
{
   int pos_score = 0, neg_score = 0, i = 0;
   const char *token_rot = "r.o.t.";
   const char *token_bad = "bad";
   const char *token_worst = "worst";
   const char *token_good = "good";
   const char *token_best = "best";

   // Looping through the input string
   while(input[i]!='\0')
   {
      // Checking for rotating letters
      if((strchr(token_rot, input[i])) != NULL && (strchr(token_rot, input[i+1])) != NULL
        && (strchr(token_rot, input[i+2])) != NULL)
      {
         pos_score += 2;
         i = i+2;
      }
      // Checking for negative words
      else if((strchr(token_bad, input[i])) != NULL && (strchr(token_bad, input[i+1])) != NULL
            && (strchr(token_bad, input[i+2])) != NULL)
      {
         neg_score += 2;
         i = i+2;
      }
      else if((strchr(token_worst, input[i])) != NULL && (strchr(token_worst, input[i+1])) != NULL
            && (strchr(token_worst, input[i+2])) != NULL && (strchr(token_worst, input[i+3])) != NULL)
      {
         neg_score += 3;
         i = i+3;
      }
      // Checking for positive words
      else if((strchr(token_good, input[i])) != NULL && (strchr(token_good, input[i+1])) != NULL
            && (strchr(token_good, input[i+2])) != NULL)
      {
         pos_score += 2;
         i = i+2;
      }
      else if((strchr(token_best, input[i])) != NULL && (strchr(token_best, input[i+1])) != NULL
            && (strchr(token_best, input[i+2])) != NULL && (strchr(token_best, input[i+3])) != NULL)
      {
         pos_score += 3;
         i = i+3;
      }
      else
      {
         i++;
      }
   }

   // Calculating the final score
   int final_score = pos_score - neg_score;

   // Displaying the sentiment analysis result
   if(final_score>0)
   {
      printf("\nOverall sentiment: Positive");
   }
   else if(final_score<0)
   {
      printf("\nOverall sentiment: Negative");
   }
   else
   {
      printf("\nOverall sentiment: Neutral");
   }
}