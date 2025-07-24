//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <string.h>

int main()
{
   char string[100];
   int i, j, len;
   
   printf("Wow, I'm so surprised to see you here!\n\n");
   printf("What string would you like to process? ");
   scanf("%s", string);

   len = strlen(string);

   printf("\n\nProcessing your string...\n\n");

   for(i=0; i<len; i++)
   {
      for(j=0; j<=i; j++)
      {
          printf("%c", string[j]);
      }
      printf("\n");
   }

   printf("\n");
   return 0;
}