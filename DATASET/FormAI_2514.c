//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() {
   char sentence[100];
   int positive = 0, negative = 0, neutral = 0;
   float confidence;

   printf("Enter a sentence: ");
   fgets(sentence, 100, stdin);

   // Remove newline character from input
   sentence[strlen(sentence) - 1] = '\0';

   // Analyze sentiment for each word in sentence
   char *word = strtok(sentence, " ");
   while (word != NULL) {
      if (strncmp(word, "good", 4) == 0 || strncmp(word, "great", 5) == 0 ||
          strncmp(word, "excellent", 9) == 0 || strncmp(word, "fantastic", 9) == 0)
         positive++;
      else if (strncmp(word, "bad", 3) == 0 || strncmp(word, "poor", 4) == 0 ||
               strncmp(word, "terrible", 8) == 0 || strncmp(word, "awful", 5) == 0)
         negative++;
      else
         neutral++;

      word = strtok(NULL, " ");
   }

   // Calculate confidence in sentiment analysis
   int total = positive + negative + neutral;
   if (total > 0)
      confidence = (float)(positive - negative) / total;
   else
      confidence = 0;

   // Print sentiment analysis results
   printf("\nSentiment Analysis Results:\n");
   printf("Positive Words: %d\n", positive);
   printf("Negative Words: %d\n", negative);
   printf("Neutral Words: %d\n", neutral);
   printf("Confidence: %f\n", confidence);

   return 0;
}