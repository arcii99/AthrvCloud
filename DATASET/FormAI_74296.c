//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>

int main() {
   int num, i, flag;

   printf("Surprise! Enter a number to generate all prime numbers up to: ");
   scanf("%d", &num);
   printf("Here are all the prime numbers up to %d:\n", num);

   // loop through all numbers up to inputted number
   for (i = 2; i <= num; i++) {

      // Assume the number is prime, until proven otherwise
      flag = 1;

      // Check if the number is not prime
      for (int j = 2; j <= i/2; j++) {
         if (i % j == 0) {
            flag = 0;
            break;
         }
      }

      // if the number is prime, print it out
      if (flag == 1)
         printf("%d ", i);
   }

   printf("\n");

   return 0;
}