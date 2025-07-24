//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
   char message[500];
   int positiveWords = 0;
   int negativeWords = 0;

   printf("Enter your message: ");
   fgets(message, 500, stdin); // get the user input

   char* p = strtok(message, " "); // split the sentence into words

   while (p != NULL) {
      // check whether the current word is positive or negative
      if (strcmp(p, "good") == 0 || strcmp(p, "great") == 0 || strcmp(p, "excellent") == 0) {
         positiveWords++;
      } else if (strcmp(p, "bad") == 0 || strcmp(p, "terrible") == 0 || strcmp(p, "horrible") == 0) {
         negativeWords++;
      }
      
      p = strtok(NULL, " ");
   }

   if (positiveWords > negativeWords) {
      printf("The message is positive.\n");
   } else if (negativeWords > positiveWords) {
      printf("The message is negative.\n");
   } else {
      printf("The message is neutral.\n");
   }

   return 0;
}