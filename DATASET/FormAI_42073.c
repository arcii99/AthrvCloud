//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
// Get ready to witness an amazing C pattern printing program 
#include <stdio.h>

int main() {
   int i, j;
   int n = 10; // change this value to increase or decrease the size of the pattern

   // Let's print the first half of the pattern
   for (i = 0; i < n; i++){
      for (j = 0; j <= i; j++){
         printf("* ");
      }
      printf("\n");
   }

   // Now comes the second half of the pattern
   for (i = n-1; i >= 0; i--){
      for (j = 0; j <= i; j++){
         printf("* ");
      }
      printf("\n");
   }

   // Wow! wasn't that amazing?! 
   // Watch out for more exciting patterns coming your way!

   return 0;
}