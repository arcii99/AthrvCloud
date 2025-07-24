//FormAI DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
   char inputStr[100];
   char searchChar;
   int count = 0;
   
   printf("Enter a string: ");
   fgets(inputStr, 100, stdin);
   
   printf("Enter a character to count: ");
   scanf("%c", &searchChar);
   
   for(int i = 0; i < strlen(inputStr); i++) {
      if(inputStr[i] == searchChar) {
         count++;
      }
   }
   
   printf("The character %c appears %d times in the string.\n", searchChar, count);
   
   return 0;
}