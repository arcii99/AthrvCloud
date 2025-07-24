//FormAI DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <string.h>

int main()
{
   char str1[50], str2[50], temp[50];
   int i, j, k=0;

   printf("Enter two strings: \n");
   gets(str1);
   gets(str2);
 
   // find the common substring
   for(i=0; i<strlen(str1); i++)
   {
      for(j=0; j<strlen(str2); j++)
      {
         if (str1[i] == str2[j])
         {
            temp[k] = str1[i];
            k++;
         }
      }
   }

   temp[k] = '\0';

   // remove duplicates from the common substring
   for(i=0; i<strlen(temp); i++)
   {
      for(j=i+1; temp[j]!='\0'; j++)
      {
         if(temp[i] == temp[j])
         {
            for(k=j; temp[k]!='\0'; k++)
            {
               temp[k] = temp[k+1];
            }
            j--;
         }
      }
   }

   // print the result
   printf("The common substring without duplicate characters is: %s\n", temp);

   return 0;
}