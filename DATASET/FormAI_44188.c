//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

void main()
{
   char sentence[1000];
   int positive=0, negative=0, neutral=0, i=0, j=0, k=0;

   printf("Enter the sentence: ");
   fgets(sentence, sizeof(sentence), stdin);

   char *positive_words[] = {"success", "profit", "win", "achievement", "victory"};
   char *negative_words[] = {"failure", "loss", "defeat", "unhappy", "sad"};

   char *ptr = strtok(sentence, " ,.-\n");

   while (ptr != NULL)
   {
      i++;
      j = 0;
      k = 0;

      while (*(positive_words + j))
      {
         if (strcmp(ptr, *(positive_words + j)) == 0)
         {
            positive++;
            k = 1;
            break;
         }
         j++;
      }

      j = 0;

      while (*(negative_words + j))
      {
         if (strcmp(ptr, *(negative_words + j)) == 0)
         {
            negative++;
            k = 1;
            break;
         }
         j++;
      }

      if (k == 0)
      {
         neutral++;
      }

      ptr = strtok(NULL, " ,.-\n");
   }

   printf("\nPositive words: %d\nNegative words: %d\nNeutral words: %d\n", positive, negative, neutral);

   if (positive > negative)
   {
      printf("\nSentiment: Positive");
   }
   else if (negative > positive)
   {
      printf("\nSentiment: Negative");
   }
   else
   {
      printf("\nSentiment: Neutral");
   }
}