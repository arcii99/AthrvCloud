//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char inputStr[1000];
   int vowelsCount = 0;

   printf("Welcome to the Text Processing Program! Enter your text below:\n");

   fgets(inputStr, 1000, stdin);

   printf("\nYour input text is: \n");
   printf("%s", inputStr);

   printf("\nLet me check how many vowels are in your text...\n");

   for (int i = 0; i < strlen(inputStr); i++) {
       char currentChar = tolower(inputStr[i]);
       if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u') {
           vowelsCount++;
       }
   }

   printf("\nFound that your text contains %d vowels! Funny fact, that's the same amount of fingers you have on your hands. Unless you lost a finger. Did you? No? Okay, awesome!\n\n", vowelsCount);

   printf("Let me show you how your text looks like without any vowels. Brace yourself!");

   for (int i = 0; i < strlen(inputStr); i++) {
       char currentChar = inputStr[i];
       if (tolower(currentChar) == 'a' || tolower(currentChar) == 'e'
        || tolower(currentChar) == 'i' || tolower(currentChar) == 'o'
        || tolower(currentChar) == 'u') {
           printf("%c", currentChar);
       } else {
           printf("%c", '_');
       }
   }

   printf("\n\nIt looks like your text without vowels is quite the mess! You might want to rewrite it. Just saying...\n");

   return 0;
}