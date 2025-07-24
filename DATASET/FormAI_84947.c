//FormAI DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   // Declare a variable to hold the user's input
   char input[100];
   // Declare a variable to hold the number of characters in the input string
   int length = 0;

   // Get the user's input
   printf("Enter a string of characters: ");
   fgets(input, 100, stdin);

   // Remove the newline character from the input string
   input[strcspn(input, "\n")] = 0;

   // Determine the length of the input string
   length = strlen(input);

   // Reverse the order of the characters in the input string
   for(int i = 0; i < length/2; i++)
   {
      char temp = input[i];
      input[i] = input[length-i-1];
      input[length-i-1] = temp;
   }

   // Print the reversed input string
   printf("Reversed string: %s\n", input);

   // Convert the input string to uppercase
   for(int i = 0; i < length; i++)
   {
      input[i] = toupper(input[i]);
   }

   // Print the uppercase input string
   printf("Uppercase string: %s\n", input);

   // Count the number of vowels in the input string
   int vowelCount = 0;
   for(int i = 0; i < length; i++)
   {
      if(input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
      {
         vowelCount++;
      }
   }

   // Print the number of vowels in the input string
   printf("Number of vowels: %d\n", vowelCount);

   // Find the longest substring of consecutively repeating characters in the input string
   char currentChar = '\0';
   int currentCount = 0;
   char longestChar = '\0';
   int longestCount = 0;
   for(int i = 0; i < length; i++)
   {
      if(input[i] == currentChar)
      {
         currentCount++;
      }
      else
      {
         if(currentCount > longestCount)
         {
            longestChar = currentChar;
            longestCount = currentCount;
         }
         currentChar = input[i];
         currentCount = 1;
      }
   }

   // Print the longest substring of consecutively repeating characters in the input string
   printf("Longest substring of consecutively repeating characters: ");
   for(int i = 0; i < longestCount; i++)
   {
      printf("%c", longestChar);
   }
   printf("\n");

   return 0;
}