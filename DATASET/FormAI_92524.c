//FormAI DATASET v1.0 Category: Pattern printing ; Style: creative
#include <stdio.h>

int main() {
   int rows = 6;
   int i, j;
   int space = rows-1;
   
   for (i = 1; i <= rows; ++i) {
      for (j = 1; j <= space; ++j) {
         printf(" ");
      }
      
      space--;
      
      for (j = 1; j <= 2*i-1; ++j) {
         printf("*");
      }
      
      printf("\n");
   }
   
   space = 1;
   
   for (i = 1; i <= rows-1; ++i) {
      for (j = 1; j <= space; ++j) {
         printf(" ");
      }
      
      space++;
      
      for (j = 1; j <= 2*(rows-i)-1; ++j) {
         printf("*");
      }
      
      printf("\n");
   }
   
   return 0;
}