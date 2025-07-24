//FormAI DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
   char text[1000];
   int spam_count = 0;
   
   printf("Enter the text: ");
   fgets(text, 1000, stdin);
   
   char *spam_words[] = {"viagra", "lottery", "prince", "nigeria", "inheritance", "bank account"};
   int num_spam_words = 6;
   
   for (int i = 0; i < num_spam_words; i++) {
      if (strstr(text, spam_words[i])) {
         spam_count++;
      }
   }
      
   if (spam_count > 0) {
      printf("This text contains %d spam words and it is likely to be spam.", spam_count);
   } else {
      printf("This text does not contain any spam words.");
   }
   
   return 0;
}