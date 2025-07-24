//FormAI DATASET v1.0 Category: Scientific ; Style: brave
#include <stdio.h>

int main() {
   printf("Greetings, brave programmer! Today, we will be exploring the fascinating world of prime numbers\n");

   int num, i, prime = 1;

   printf("Please enter a number: ");
   scanf("%d", &num);

   for(i=2;i<num/2;i++) {
      if(num%i==0) {
         prime = 0;
         break;
      }
   }

   if(prime==1){
      printf("%d is a prime number!\n", num);
   } else {
      printf("%d is not a prime number!\n", num);
   }

   int j;
   printf("Now, let's print all the prime numbers between 2 and %d\n", num);

   for(i=2;i<=num;i++) {
      prime = 1;

      for(j=2;j<i/2;j++) {
         if(i%j==0) {
            prime = 0;
            break;
         }
      }

      if(prime==1) {
         printf("%d ", i);
      }
   }

   printf("\nAnd there you have it, a program that can determine if a number is prime and print all the primes between 2 and a given number!\n");

   return 0;
}