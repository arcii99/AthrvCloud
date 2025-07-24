//FormAI DATASET v1.0 Category: Word Count Tool ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

   char str[100];
   int count = 0;

   printf("Welcome to C Word Count Tool\n");
   printf("Please enter a sentence or a paragraph: \n");

   fgets(str, 100, stdin);

   // Loop through string
   for(int i=0; i<strlen(str); i++){

      // If space or end of line is detected
      if(str[i] == ' ' || str[i] == '\n' || str[i] == '\0'){
         count++; // Increase word count
      }
   }

   // Display word count
   printf("Your sentence/paragraph contained %d words.\n", count);

   return 0;
}