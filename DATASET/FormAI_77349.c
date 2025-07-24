//FormAI DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {

   char text[100];
   int count = 0, i;

   printf("Enter a sentence: ");
   fgets(text, sizeof(text), stdin); // user input
   text[strlen(text)-1] = '\0'; // removing newline character

   for(i=0; text[i]!='\0'; i++) {
      if(text[i]==' ' && text[i+1]!=' ') {
         count++;
      }
   }

   printf("Word Count: %d", count+1);

   return 0;
}