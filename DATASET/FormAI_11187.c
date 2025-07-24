//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
   char message[1000];
   int spam_count = 0;
   int i, j, word_count = 1;

   printf("Enter the message to check for spam: ");
   fgets(message, sizeof(message), stdin);

   for (i = 0; i < strlen(message); i++) {
      if (message[i] == ' ')
         word_count++;
      if (word_count > 5) {
         spam_count++;
         break;
      }
   }

   if (spam_count > 0) {
      printf("This message is a spam.");
   } else {
      printf("This message is not a spam.");
   }

   return 0;
}