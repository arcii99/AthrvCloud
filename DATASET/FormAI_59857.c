//FormAI DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to remove all non-alphabetical characters from a string
char* removeNonAlphabetical(char* s) {
   char* p = s;
   int len = strlen(p);

   for (int i = 0; i < len; i++)
      if (!isalpha(*(p+i))) { 
         memmove(p+i, p+i+1, len-i);
         len--;
         i--;
      }
      
   return s;
}

int main() {
   char input[1000]; // assuming the input string has a maximum length of 1000 characters
   printf("Enter text to process:\n");
   fgets(input, sizeof(input), stdin);
   
   char* cleaned = removeNonAlphabetical(input); // remove non-alphabetical characters
   printf("Cleaned string: %s\n", cleaned);
   
   int count = 0;
   int len = strlen(cleaned);
   for (int i = 0; i < len; i++)
      if (tolower(*(cleaned+i)) == 'e') // count the number of 'e's in the string
         count++;
         
   printf("Number of 'e's in the string: %d\n", count);

   return 0;
}