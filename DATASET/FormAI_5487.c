//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

   char string[1000], search[100];
   int count = 0, i;

   printf("Enter a string:\n");
   gets(string);

   printf("Enter a word to search:\n");
   gets(search);

   for(i=0;i<=strlen(string)-strlen(search);i++) {
      if(strncmp(string+i, search, strlen(search)) == 0)
         count++;
   }
 
   printf("'%s' occurs %d times in the string '%s'.", search, count, string);
  
   return 0;
}