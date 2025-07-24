//FormAI DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100

void reverseString(char*);

int main()
{
   char userString[MAX_STR_LEN];

   printf("Please enter a string to reverse: ");
   fgets(userString, MAX_STR_LEN, stdin);

   // remove newline character from user input
   userString[strcspn(userString, "\n")] = '\0';

   printf("You entered: %s\n", userString);

   reverseString(userString);

   printf("Reversed string: %s\n", userString);

   return 0;
}

void reverseString(char* str)
{
   int length, c;
   char* front, * back, temp;

   length = strlen(str);
   front = str;
   back = str;

   // move back pointer to end of string
   for (c = 0; c < length - 1; c++)
   {
      back++;
   }

   // swap front and back pointers until they meet in the middle
   for (c = 0; c < length / 2; c++)
   {
      temp = *back;
      *back = *front;
      *front = temp;

      // move pointers inward
      front++;
      back--;
   }
}