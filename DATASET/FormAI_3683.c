//FormAI DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {
   char message[1000];
   int count = 0;

   printf("Enter the message: ");
   fgets(message, 1000, stdin); // gets user message

   int len = strlen(message);

   for(int i = 0; i < len; i++) {
      if(message[i] == 'c' || message[i] == 'C') {
         if(i+1 < len && message[i+1] == ' ') { // check to avoid false positives
            count++; // increment count if 'c' or 'C' followed by space
            i++; // move index to avoid consecutive matches
         }
      }
      else if(message[i] == '/') {
         if(i+1 < len && message[i+1] == '/') { // check for double forward slashes
            printf("Found potential comment spam. Check line %d.\n", count+1);
         }
      }
   }

   printf("\nNumber of 'c' or 'C' followed by a space: %d\n", count);

   return 0;
}