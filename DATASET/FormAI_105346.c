//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char text[1000], search[100];
   int count = 0, i;

   printf("Enter a text string : ");
   fgets(text, 1000, stdin);

   printf("Enter the word to count in the string : ");
   fgets(search, 100, stdin);

   for(i=0; i<strlen(text); i++) {
      if(text[i] == search[0]) {
         if(strncmp(&text[i], search, strlen(search)-1) == 0)
            count++;
      }
   }

   printf("Total occurrences of '%s' in the text string is : %d\n", search, count);

   return 0;
}