//FormAI DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
   char input[1000], spam[1000];
   int i, j, len, spamlen, count=0;
   
   printf("Enter your input: ");
   fgets(input, 1000, stdin);
   
   printf("Enter spam keyword: ");
   fgets(spam, 1000, stdin);

   len = strlen(input);
   spamlen = strlen(spam);
   
   for (i = 0; i < len; i++) {
      if (input[i] == spam[0]) {
         for (j = 1; j < spamlen; j++){
            if (input[i+j] == spam[j])
                  count++; 
         }
         
         if (count == spamlen-1) {
            printf("SPAM DETECTED!");
            break;
         }
      }
   }
   
   if (count != spamlen-1)
      printf("No spam detected");
   
   return 0;
}