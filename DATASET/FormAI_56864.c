//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main()
{
   char text[100];
   printf("Enter a sentence to analyze its sentiment: ");
   scanf("%[^\n]%*c", text);

   int score = 0;
   for (int i = 0; i < strlen(text); i++) {
      score += text[i];
   }

   if (score % 2 == 0) {
      printf("The sentiment of the sentence is positive.\n");
   } else {
      printf("The sentiment of the sentence is negative.\n");
   }

   return 0;
}