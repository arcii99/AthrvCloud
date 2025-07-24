//FormAI DATASET v1.0 Category: Spam Detection System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char spamWords[5][10] = {"sugar", "free", "money", "guarantee", "prize"};
   char message[100];
   int i, j, spamCount = 0;

   printf("Enter your message: ");
   fgets(message, 100, stdin);

   // Remove newline character from message
   if (message[strlen(message)-1] == '\n') {
      message[strlen(message)-1] = '\0';
   }

   // Check if any spam words are present in the message
   for (i = 0; i < strlen(message); i++) {
      for (j = 0; j < 5; j++) {
         if (message[i] == spamWords[j][0]) { // If first character matches
            if (strncmp(&message[i], spamWords[j], strlen(spamWords[j])) == 0) {
               // Exact match found
               spamCount++;
            }
         }
      }
   }

   if (spamCount == 0) {
      printf("Message is not spam.\n");
   } else {
      printf("This message is spam!\n");
   }

   return 0;
}