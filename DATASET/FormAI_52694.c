//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char text[1000];

   printf("Enter some text: ");
   fgets(text, 1000, stdin);

   int length = strlen(text);
   int num_letters = 0;
   int num_digits = 0;
   int num_spaces = 0;

   for(int i = 0; i < length; i++) {

      //count number of letters
      if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
         num_letters++;
      }

      //count number of digits
      if(text[i] >= '0' && text[i] <= '9') {
         num_digits++;
      }

      //count number of spaces
      if(text[i] == ' ') {
         num_spaces++;
      }
   }

   printf("The text contains %d letters, %d digits, and %d spaces.", num_letters, num_digits, num_spaces);
   
   return 0;
}