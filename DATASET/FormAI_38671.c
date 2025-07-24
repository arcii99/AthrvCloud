//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Alan Touring
#include <stdio.h>

int main() {
   int num, i, j, flag;

   printf("Enter a positive integer: ");
   scanf("%d", &num);

   if (num >= 2) {
      printf("Prime numbers between 1 and %d are: ", num);

      for (i = 2; i <= num; i++) {
         flag = 1;

         for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
               flag = 0;
               break;
            }
         }

         if (flag == 1) {
            printf("%d ", i);
         }
      }

      printf("\n");
   } else {
      printf("Please enter a positive integer greater than or equal to 2.");
   }

   return 0;
}