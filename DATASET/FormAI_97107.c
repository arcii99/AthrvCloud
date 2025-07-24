//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
/** 
 * AdaLovelace Spam Detection System
 * Written by: Ada Lovelace
 * Date: September 13, 2021
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_INPUT 200  // maximum length of input string

int is_spam(char *input);

int main()
{
   char input[MAX_INPUT];
   printf("Enter a message: ");
   fgets(input, MAX_INPUT, stdin);

   if(is_spam(input))
   {
      printf("This message contains spam.\n");
   }
   else
   {
      printf("This message is not spam.\n");
   }

   return 0;
}

int is_spam(char *input)
{
   // List of spam words
   char *spam_words[] = {"money", "free", "buy", "dollars", "rich", "million", "limited time offer", "earn money", 
                         "lowest price", "act now", "you have been selected", "discount", "bonus", "opportunity", 
                         "get rich quick", "prize", "credit card", "investment", "make money", "cash"};

   // Number of spam words
   int num_spam_words = sizeof(spam_words) / sizeof(spam_words[0]);

   // Loop through each word in the input string
   for(int i = 0; i < strlen(input); i++)
   {
      // Check for each spam word in the input string
      for(int j = 0; j < num_spam_words; j++)
      {
         // Size of the current spam word
         int size = strlen(spam_words[j]);

         // Check if the current substring matches the spam word
         if(strncmp(&input[i], spam_words[j], size) == 0)
         {
            return 1; // Spam detected
         }
      }
   }

   return 0; // No spam detected
}