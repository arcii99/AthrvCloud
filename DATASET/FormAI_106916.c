//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include <stdio.h>
#include <string.h>

int main() {
   char input[100];
   int pos_sentiment = 0;
   int neg_sentiment = 0;
   int neutral_sentiment = 0;
   int total_sentiment = 0;
   float sentiment_score;

   printf("Please enter a sentence or paragraph: ");
   fgets(input, 100, stdin);

   char *token = strtok(input, " ");

   while (token != NULL) {
      if (strstr(token, "good") || strstr(token, "great") || strstr(token, "excellent") || strstr(token, "awesome")) {
         pos_sentiment++;
         total_sentiment++;
      } else if (strstr(token, "bad") || strstr(token, "terrible") || strstr(token, "poor") || strstr(token, "horrible")) {
         neg_sentiment++;
         total_sentiment++;
      } else {
         neutral_sentiment++;
         total_sentiment++;
      }

      token = strtok(NULL, " ");
   }

   if (total_sentiment == 0) {
      printf("No sentiment detected.\n");
   } else {
      sentiment_score = ((float) pos_sentiment - (float) neg_sentiment) / (float) total_sentiment;
      printf("Positive Sentiment: %d\n", pos_sentiment);
      printf("Negative Sentiment: %d\n", neg_sentiment);
      printf("Neutral Sentiment: %d\n", neutral_sentiment);
      printf("Sentiment Score: %.2f\n", sentiment_score);
   }
   
   return 0;
}