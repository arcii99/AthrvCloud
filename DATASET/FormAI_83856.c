//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>

int main() {
   char sentence[1000];
   int positiveCount = 0;
   int negativeCount = 0;
   int neutralCount = 0;
   int i;
   
   printf("Enter a sentence: ");
   fgets(sentence, 1000, stdin);
   
   for(i=0; sentence[i]!='\0'; i++) {
      if(sentence[i] == ' ') {
         continue;
      }
      if(sentence[i] == 'n' && sentence[i+1] == 'o' && sentence[i+2] == 't' && (sentence[i+3] == ' ' || sentence[i+3] == '\0')) {
         negativeCount++;
         i += 2;
      } else if(sentence[i] == 'g' && sentence[i+1] == 'o' && sentence[i+2] == 'o' && sentence[i+3] == 'd' && (sentence[i+4] == ' ' || sentence[i+4] == '\0')) {
         positiveCount++;
         i += 3;
      } else {
         neutralCount++;
      }
   }
   
   printf("\nPositive words count: %d", positiveCount);
   printf("\nNegative words count: %d", negativeCount);
   printf("\nNeutral words count: %d", neutralCount);
   
   if(positiveCount > negativeCount) {
      printf("\nThe sentence has a positive sentiment.");
   } else if(negativeCount > positiveCount) {
      printf("\nThe sentence has a negative sentiment.");
   } else {
      printf("\nThe sentence is neutral.");
   }
   
   return 0;
}