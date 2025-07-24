//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <string.h>

int main()
{
   char funnyQuote[] = "Why was the math book sad? Because it had too many problems.";

   // Show the original quote
   printf("Original Quote: %s\n", funnyQuote);

   // Convert all characters to uppercase
   int len = strlen(funnyQuote);
   for(int i = 0; i < len; i++)
   {
      funnyQuote[i] = toupper(funnyQuote[i]);
   }

   // Show the funny quote in all caps
   printf("Funny Quote in All Caps: %s\n", funnyQuote);

   // Count the number of words in the quote
   int wordCount = 0;
   char *token = strtok(funnyQuote, " ");
   while(token != NULL)
   {
      wordCount++;
      token = strtok(NULL, " ");
   }

   // Show the word count of the quote
   printf("Word Count of the Quote: %d\n", wordCount);

   // Reverse the order of the words in the quote
   char *words[wordCount];
   token = strtok(funnyQuote, " ");
   int index = 0;
   while(token != NULL)
   {
      words[index] = token;
      index++;
      token = strtok(NULL, " ");
   }

   printf("Quote in Reverse Order: ");
   for(int i = wordCount - 1; i >= 0; i--)
   {
      printf("%s ", words[i]);
   }
   printf("\n");

   return 0;
}