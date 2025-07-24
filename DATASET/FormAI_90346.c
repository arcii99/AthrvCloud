//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>

int main() {
   int num, i, j, flag;

   printf("Enter the number of prime numbers to be generated: ");
   scanf("%d", &num);

   if (num < 1) {
      printf("Invalid input!");
      return 0;
   }

   printf("The first %d prime numbers are: ", num);

   for (i = 2; i <= num; ) {
      flag = 0;

      for (j = 2; j <= i / 2; j++) {
         if (i % j == 0) {
            flag = 1;
            break;
         }
      }

      if (flag == 0) {
         printf("%d ", i);
         i++;
      }
      else {
         i++;
      }
   }

   return 0;
}