//FormAI DATASET v1.0 Category: Spam Detection System ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() {
   char message[100];
   int spam_count = 0, i;

   printf("Enter your message: ");
   fgets(message, 100, stdin);

   char* spam_words[] = {"free", "offer", "money", "win", "prize", "limited time", "act now"};

   for(i = 0; i < sizeof(spam_words)/sizeof(char*); i++) {
      if(strstr(message, spam_words[i]) != NULL) {
         spam_count++;
      }
   }

   if(spam_count > 0) {
      printf("\nThis message is likely spam!");
   }
   else {
      printf("\nThis message is not spam.");
   }

   return 0;
}