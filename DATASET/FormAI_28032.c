//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>

int main() {
   int num, i, flag;

   printf("Enter a positive integer: ");
   scanf("%d", &num);

   if (num < 2) {
       printf("There are no prime numbers less than 2\n");
       return 0;
   }

   printf("The prime numbers less than %d are:\n", num);

   // loop through all numbers less than num
   for (i = 2; i < num; i++) {

      // assume the number is prime until proven otherwise
      flag = 1;

      // check if the number is divisible by any number less than itself
      for (int j = 2; j < i; j++) {
         if (i % j == 0) {
            flag = 0;
            break;
         }
      }

      // if the number is prime, print it
      if (flag == 1) {
         printf("%d ", i);
      }
   }
   printf("\n");
   return 0;
}