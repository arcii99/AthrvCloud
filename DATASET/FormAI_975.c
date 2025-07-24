//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Donald Knuth
#include <stdio.h>

int main() {
   int catInput;
   printf("Enter a cat sound (1 for meow, 2 for purr, 3 for hiss): ");
   scanf("%d", &catInput);

   switch(catInput) {
      case 1 :
         printf("meow meow meow");
         break;
      case 2 :
         printf("purrrrrrr");
         break;
      case 3 :
         printf("hssssss");
         break;
      default :
         printf("Invalid input");
   }

   return 0;
}