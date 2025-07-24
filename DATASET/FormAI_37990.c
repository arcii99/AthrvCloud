//FormAI DATASET v1.0 Category: Pattern printing ; Style: funny
#include <stdio.h>

int main() {
   char c = 'C';
   int i, j;
   
   for(i = 1; i <= 7; i++) {
      for(j = 1; j <= 7; j++) {
         if(i == 1 || i == 7) {  // First and last row
            printf("*");
         }
         else if((j == 1 || j == 7) && (i != 1 && i != 7)) {  // First and last column
            printf("*");
         }
         else if(i == 2 && j == 6) {  // C's top line
            printf("%c%c%c", c, c, c);
         }
         else if(i == 6 && j == 2) {  // C's bottom line
            printf("%c%c%c", c, c, c);
         }
         else {
            printf(" ");  // Everything else is a space
         }
      }
      printf("\n");  // Move to next line
   }
   
   return 0;
}