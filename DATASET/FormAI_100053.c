//FormAI DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 100

int main()
{
   char text[MAX_SIZE];
   int alphabetCount = 0, digitsCount = 0, specialCharsCount = 0;
   int i;

   printf("Enter any text: ");
   fgets(text, MAX_SIZE, stdin);

   for(i=0; text[i] != '\0'; i++)
   {
      if(isalpha(text[i]))
      {
         alphabetCount++;
      }
      else if(isdigit(text[i]))
      {
         digitsCount++;
      }
      else
      {
         specialCharsCount++;
      }
   }

   printf("\n\nTotal Alphabets: %d", alphabetCount);
   printf("\nTotal Digits: %d", digitsCount);
   printf("\nTotal Special Characters: %d", specialCharsCount);

   return 0;
}