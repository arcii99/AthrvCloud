//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <string.h>

int main() {
   char phrase[1000];
   int happyCount = 0, sadCount = 0;

   printf("Enter your phrase: ");
   fgets(phrase, 1000, stdin);

   int length = strlen(phrase);

   char lastChar = phrase[length - 2]; // remove the newline character

   if(lastChar == '.' || lastChar == '!' || lastChar == '?') {
      for(int i = 0; i < length; i++) {
         if(phrase[i] == ':' && phrase[i+1] == ')') {
            happyCount++;
         } else if(phrase[i] == ':' && phrase[i+1] == '(') {
            sadCount++;
         }
      }

      if(happyCount > sadCount) {
         printf("The sentiment of your phrase is positive. \n");
      } else if(happyCount < sadCount) {
         printf("The sentiment of your phrase is negative. \n");
      } else {
         printf("The sentiment of your phrase is neutral. \n");
      }
   } else {
      printf("Please enter a valid phrase with a punctuation mark at the end. \n");
   }

   return 0;
}