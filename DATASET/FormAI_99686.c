//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {

   char text[1000], temp;
   int i, j, len;

   printf("Enter text to be processed: ");
   fgets(text, 1000, stdin);

   len = strlen(text);

   for(i = 0; i < len-1; i++) {
      for(j = i+1; j < len; j++) {
         if(text[i] > text[j]) {
            temp = text[i];
            text[i] = text[j];
            text[j] = temp;
         }
      }
   }

   printf("\nGratefully processed text: ");

   for(i = 0; i < len-1; i++){
      if(text[i] != ' ' && text[i+1] == ' ') {
         putchar(text[i]);
         putchar(text[i+1]);
         i++;
      }
      else if(text[i] != ' ') {
         putchar(text[i]);
      }
   }

   return 0;
}