//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <string.h>

int main() {
   char input[100];
   int i, len;
   printf("Enter a sentence in the C Alien language: ");
   fgets(input, 100, stdin);   // Get input from user
   len = strlen(input);
   for(i = 0; i < len; i++) {
       switch(input[i]) {
           case 'C':
               printf("K");
               break;
           case 'c':
               printf("k");
               break;
           case 'Z':
               printf("S");
               break;
           case 'z':
               printf("s");
               break;
           case 'F':
               printf("PH");
               break;
           case 'f':
               printf("ph");
               break;
           case 'H':
               printf("'");
               break;
           case 'h':
               printf("'");
               break;
           case 'R':
               printf("RR");
               break;
           case 'r':
               printf("rr");
               break;
           case 'L':
               printf("LL");
               break;
           case 'l':
               printf("ll");
               break;
           default:
               printf("%c", input[i]);
       }
   }
   return 0;
}