//FormAI DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>

int main() {
   char string[1000];
   int count = 0, i;

   printf("Enter a sentence or paragraph:\n");
   scanf("%[^\n]s", string);

   for (i = 0;string[i] != '\0';i++) {
       if (string[i] == ' ') {
           count++;    
       }
   }
   count++;
   
   printf("The word count of your input is: %d\n", count);

   return 0;
}