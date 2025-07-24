//FormAI DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
   char str[100];
   int count = 0;

   printf("Enter the string: ");
   fgets(str, 100, stdin);

   // Loop to count words in string
   for (int i = 0; i < strlen(str); i++)
   {
       if (isspace(str[i])) // If character is a space
       {
           count++;
           while (isspace(str[i])) // Ignore any additional white spaces
           {
               i++;
           }
       }
   }

   if (strlen(str) > 0) // If string is not empty
   {
       count++; // Add 1 to the word count for the last word
   }

   printf("The string has %d words.\n", count);
   
   return 0;
}