//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* alienToEng(char* alienStr) {
   int i, j = 0, len = strlen(alienStr);
   char* engStr = (char*)malloc(sizeof(char) * len);

   for (i = 0; i < len; i++) {
      switch (alienStr[i]) {
         case '+':
            engStr[j] = 'a';
            break;
         case '*':
            engStr[j] = 'e';
            break;
         case '@':
            engStr[j] = 'i';
            break;
         case '#':
            engStr[j] = 'o';
            break;
         case '$':
            engStr[j] = 'u';
            break;
         default:
            engStr[j] = alienStr[i];
      }
      j++;
   }
   engStr[j] = '\0';
   return engStr;
}

int main() {
   char alienStr[100];
   printf("Enter a string in Alien language: ");
   scanf("%s", alienStr);
   char* engStr = alienToEng(alienStr);
   printf("Translated to English: %s\n", engStr);
   free(engStr);
   return 0;
}