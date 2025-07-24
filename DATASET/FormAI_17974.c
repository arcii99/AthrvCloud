//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   char *palindrome;
   int len, i, j, flag = 1;
   palindrome = (char*)malloc(100*sizeof(char));
   scanf("%s", palindrome);
   len = strlen(palindrome);
   for(i = 0, j = len - 1; i <= len/2; i++, j--)
   {
      if(palindrome[i] != palindrome[j])
      {
         flag = 0;
         break;
      }
   }
   if(flag == 1)
   {
      printf("Given String is a Palindrome\n");
   }
   else
   {
      printf("Not a Palindrome\n");
   }
   return 0;
}