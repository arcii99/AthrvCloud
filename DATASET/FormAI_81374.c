//FormAI DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>

int main() {
   int num, i, j, k;
   
   printf("Enter a number: ");
   scanf("%d", &num);
   
   printf("The multiplication table of %d is:\n", num);
   
   // Using nested for loops to create the multiplication table
   for (i = 1; i <= num; i++) {
      for (j = 1; j <= 10; j++) {
         k = i * j;
         printf("%d x %d = %d\n",i, j, k);
      }  
      printf("\n"); // Add a new line after each iteration
   }

   return 0;
}