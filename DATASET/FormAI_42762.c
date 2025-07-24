//FormAI DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
   char string[100];
   int i, count = 0;
   
   printf("Enter a string: ");
   gets(string);
   
   for(i=0; string[i]!='\0'; i++) {
      if(string[i] == ' ') {
         count++;
      }   
   }

   printf("\nTotal number of words in the string: %d", count+1);
   
   return 0;
}