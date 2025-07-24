//FormAI DATASET v1.0 Category: Spam Detection System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char message[1000];
   int i, count = 0;
   printf("Enter a message: ");
   gets(message);
   char *spamwords[10] = {"make money fast", "earn $1000", "work from home", "hot deal", "limited time offer", "buy now", "free", "click here", "guaranteed", "winner"};
   char *token;
   token = strtok(message, " ");
   while (token != NULL)
   {
      for (i = 0; i < 10; i++)
      {
         if (strstr(token, spamwords[i]) != NULL)
         {
            count++;
         }
      }
      token = strtok(NULL, " ");
   }

   if (count >= 2)
   {
      printf("\nThis message appears to be spam.\n");
   }
   else
   {
      printf("\nThis message is not spam.\n");
   }

   return 0;
}