//FormAI DATASET v1.0 Category: Word Count Tool ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
   char input[100];
   int count = 0, inWord = 0;
   
   printf("Enter a string: ");
   fgets(input, sizeof(input), stdin);
   
   for(int i = 0; i < strlen(input); i++) {
      if(input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
         inWord = 0;
      }
      else if(!inWord) {
         count++;
         inWord = 1;
      }
   }
   
   printf("The string contains %d words.", count);
   
   return 0;
}