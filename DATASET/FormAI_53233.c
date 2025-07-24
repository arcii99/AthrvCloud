//FormAI DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int main()
{
   char message[1000];
   int spam_flag = 0;
   int uppercase_count = 0;
   int exclamation_count = 0;

   printf("Enter a message: \n");
   fgets(message, sizeof(message), stdin);

   // Check for all uppercase letters
   for(int i = 0; message[i] != '\0'; i++)
   {
      if(message[i] >= 'A' && message[i] <= 'Z')
      {
         uppercase_count++;
      }
   }

   // Check for exclamation marks
   for(int i = 0; message[i] != '\0'; i++)
   {
      if(message[i] == '!')
      {
         exclamation_count++;
      }
   }

   // Determine if message is spam
   if(uppercase_count > 10 || exclamation_count > 5)
   {
      spam_flag = 1;
   }

   // Print results
   if(spam_flag)
   {
      printf("\nThis message appears to be spam.");
   }
   else
   {
      printf("\nThis message is not spam.");
   }

   return 0;
}