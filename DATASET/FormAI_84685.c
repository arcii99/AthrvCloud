//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include<stdio.h>
#include<string.h>

int main() {
   char sentence[1000];
   int i = 0, count = 0, positive = 0, negative = 0;

   printf("Enter a statement: ");
   fgets(sentence, 1000, stdin);

   //Checking whether the inputted sentence is positive or not
   for (i = 0; sentence[i] != '\0'; i++)
      {
      if ((sentence[i] == 'g' && sentence[i+1] == 'o' && sentence[i+2] == 'o' && sentence[i+3] == 'd')
          || (sentence[i] == 'n' && sentence[i+1] == 'i' && sentence[i+2] == 'c' && sentence[i+3] == 'e')
          || (sentence[i] == 'h' && sentence[i+1] == 'a' && sentence[i+2] == 'p' && sentence[i+3] == 'p' && sentence[i+4] == 'y')
          || (sentence[i] == 'g' && sentence[i+1] == 'r' && sentence[i+2] == 'e' && sentence[i+3] == 'a' && sentence[i+4] == 't'))
         {
            positive++;
            count++;
         }
      //Checking whether the inputted sentence is negative or not
      else if ((sentence[i] == 'b' && sentence[i+1] == 'a' && sentence[i+2] == 'd')
              || (sentence[i] == 's' && sentence[i+1] == 'a' && sentence[i+2] == 'd')
              || (sentence[i] == 'a' && sentence[i+1] == 'n' && sentence[i+2] == 'g' && sentence[i+3] == 'r' && sentence[i+4] == 'y')
              || (sentence[i] == 'h' && sentence[i+1] == 'a' && sentence[i+2] == 't' && sentence[i+3] == 'e'))
         {
            negative++;
            count++;
         }
      }

   if (positive == negative && count != 0)
   {
       printf("\nNeutral sentiment.");
   }

   else if (positive > negative)
   {
       printf("\nPositive sentiment!");
   }

   else if (negative > positive)
   {
       printf("\nNegative sentiment.");
   }

   else
   {
       printf("\nUnable to determine sentiment.");
   }

   return 0;
}