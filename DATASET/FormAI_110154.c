//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
   char sentence[1000];
   int positiveCount = 0, negativeCount = 0, neutralCount = 0;

   printf("Enter your sentence:\n");
   // Take input from user
   fgets(sentence, sizeof(sentence), stdin);
   
   // Split the sentence into words
   char *word = strtok(sentence, " \n");

   // Loop through all words in the sentence
   while(word != NULL) {
      // Check if the word has positive sentiment
      if(strcasecmp(word, "good") == 0 || strcasecmp(word, "great") == 0 || strcasecmp(word, "happy") == 0 || strcasecmp(word, "love") == 0 || strcasecmp(word, "excellent") == 0 || strcasecmp(word, "wonderful") == 0 || strcasecmp(word, "awesome") == 0) {
         positiveCount++;
      }
      // Check if the word has negative sentiment
      else if(strcasecmp(word, "bad") == 0 || strcasecmp(word, "awful") == 0 || strcasecmp(word, "horrible") == 0 || strcasecmp(word, "hate") == 0 || strcasecmp(word, "dislike") == 0 || strcasecmp(word, "terrible") == 0 || strcasecmp(word, "poor") == 0) {
         negativeCount++;
      }
      // If not positive or negative, then it's neutral
      else {
         neutralCount++;
      }

      // Get the next word
      word = strtok(NULL, " \n");
   }

   printf("Positive words: %d\n", positiveCount);
   printf("Negative words: %d\n", negativeCount);
   printf("Neutral words: %d\n", neutralCount);

   // Determine the overall sentiment based on the count of positive and negative words
   if (positiveCount > negativeCount) {
      printf("\nOverall sentiment: Positive\n");
   } else if (negativeCount > positiveCount) {
      printf("\nOverall sentiment: Negative\n");
   } else {
      printf("\nOverall sentiment: Neutral\n");
   }

   return 0;
}