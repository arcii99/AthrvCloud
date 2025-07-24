//FormAI DATASET v1.0 Category: Spam Detection System ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
   char emailContent[500];
   int spamCount = 0;

   // Prompt user to input email content and store in emailContent variable
   printf("Please enter the email content:\n");
   fgets(emailContent, 500, stdin);

   // Check for spam words/phrases in email content
   if (strstr(emailContent, "You won a free vacation")) {
      spamCount++;
   }
   if (strstr(emailContent, "Buy now and get 50% off")) {
      spamCount++;
   }
   if (strstr(emailContent, "Click here to claim your prize")) {
      spamCount++;
   }

   // Determine if email is spam or not based on spamCount
   if (spamCount >= 2) {
      printf("This email is spam\n");
   } else {
      printf("This email is not spam\n");
   }

   return 0;
}