//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: romantic
#include <stdio.h>

int main() {

   int num, prime, i, flag;

   printf("My love, let me generate some prime numbers for you. Please enter the number of primes you want me to generate:\n");
   scanf("%d", &num);

   printf("\n" );
   printf("Here are your prime numbers, my dear:\n");

   for (prime = 2; prime <= num; ) {

      flag = 0;

      for (i = 2; i <= prime / 2; ++i) {
         if (prime % i == 0) {
            flag = 1;
            break;
         }
      }

      if (flag == 0) {
         printf("\n%d", prime);
         ++prime;
      }
      else { 
         ++prime;
      }
   }
   
   printf("\n\nI hope these numbers can make you smile and remind you of how much I love you.");
   return 0;
}