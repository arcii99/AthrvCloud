//FormAI DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
   char message[100];
   int i, spam = 0;
   
   printf("Enter a message: ");
   scanf("%[^\n]s", message);

   char *spam_list[] = {"viagra", "money", "prince", "inheritance", "nigerian"};
   int size = sizeof(spam_list)/sizeof(char *);

   char *word = strtok(message, " ");

   while(word != NULL)
   {
      for(i = 0; i < size; i++)
      {
         if(strcmp(word, spam_list[i]) == 0)
         {
            spam = 1;
            break;
         }
      }

      if(spam == 1)
      {
         printf("This is a spam message.\n");
         break;
      }

      word = strtok(NULL, " ");
   }

   if(spam == 0)
   {
      printf("This is not a spam message.\n");
   }

   return 0;
}