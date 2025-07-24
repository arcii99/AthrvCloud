//FormAI DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <string.h>
#define MAX 100

void compress(char []);

void main()
{
   char str[MAX];
 
   printf("Enter the string to compress: ");
   fgets(str, MAX, stdin);
 
   compress(str);
}

void compress(char str[])
{
   int i, j, count;
   char temp[MAX];
   
   int n = strlen(str);
   temp[0] = str[0];
   j = 1;
   count = 1;
 
   for (i = 1; i < n; i++)
   {
      if (str[i] == temp[j-1])
      {
         count++;
      }
      else
      {
         if (count > 1)
         {
            temp[j++] = count + '0';
         }
         temp[j++] = str[i];
         count = 1;
      }
   }
   
   if (count > 1)
   {
      temp[j++] = count + '0';
   }
  
   temp[j] = '\0';

   printf("\nCompressed string: %s\n", temp);

}