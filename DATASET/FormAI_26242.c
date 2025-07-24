//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main() {
   char input[100];
   char positive[10][30] = {"happy", "great", "fantastic", "awesome", "love", "excellent", "amazing", "good", "terrific", "nice"};
   char negative[10][30] = {"sad", "bad", "horrible", "awful", "dislike", "hate", "terrible", "worst", "negative", "unhappy"};
   int pos_count = 0, neg_count = 0;

   printf("Welcome to the Sentiment Analysis Tool. Please enter your text: \n");
   fgets(input, 100, stdin);

   char *word = strtok(input, " ");

   while (word != NULL) {
      for (int i = 0; i < 10; i++) {
         if (strcmp(word, positive[i]) == 0) {
            pos_count++;
            break;
         }
         else if (strcmp(word, negative[i]) == 0) {
            neg_count++;
            break;
         }
      }
      word = strtok(NULL, " ");
   }

   printf("\nPositive words count: %d\n", pos_count);
   printf("Negative words count: %d\n", neg_count);

   if (pos_count > neg_count) {
      printf("\nOverall Sentiment: Positive!\n");
   }
   else if (pos_count < neg_count) {
      printf("\nOverall Sentiment: Negative!\n");
   }
   else {
      printf("\nOverall Sentiment: Neutral!\n");
   }

   return 0;
}