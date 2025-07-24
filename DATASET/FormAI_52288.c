//FormAI DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char input[1000];
   char encoded[1000];
   int count = 1;
   int i;
   char current;

   printf("Enter your input string: ");
   fgets(input, 1000, stdin);

   current = input[0];

   for (i = 1; i < strlen(input); i++) {
      if (input[i] == current) {
         count++;
      } else {
         if (count == 1) {
            sprintf(encoded, "%s%c", encoded, current);
         } else {
            sprintf(encoded, "%s%c%d", encoded, current, count);
         }
         current = input[i];
         count = 1;
      }
   }

   // add last character to encoded string
   if (count == 1) {
      sprintf(encoded, "%s%c", encoded, current);
   } else {
      sprintf(encoded, "%s%c%d", encoded, current, count);
   }

   printf("\nInput string: %s", input);
   printf("Encoded string: %s\n", encoded);

   return 0;
}