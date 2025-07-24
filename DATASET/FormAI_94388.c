//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include <stdio.h>

int main() {
   int c;
   printf("Please enter a phrase in C Cat Language: ");
   while ((c=getchar()) != '\n') {
      switch (c) {
         case 'M': printf("Meow "); break;
         case 'P': printf("Purr "); break;
         case 'F': printf("Feed me! "); break;
         case 'H': printf("Hello human! "); break;
         case 'T': printf("Treats please! "); break;
         case 'W': printf("Why are you sleeping? "); break;
         case 'C': printf("Chase me! "); break;
         case 'L': printf("Let me out! "); break;
         case 'S': printf("Scratch my belly! "); break;
         default: printf("*Silence* "); break;
      }
   }
   return 0;
}