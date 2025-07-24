//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: happy
#include <stdio.h>
#include <stdbool.h>

int main() {
   int counter = 1;
   int number = 3;
   printf("1 - Who is ready for some prime numbers?!!\n");
   printf("2 - Let's get started!!\n");
   printf("3 - I am feeling lucky, are you?\n");
   printf("4 - An adventure awaits us in the land of primes!\n\n");
   printf("***** PRIME NUMBER GENERATOR *****\n");
   printf("*** Hit Ctrl+C anytime to quit the program ***\n\n");

   while(true) {
      int divisor = 2;
      bool isPrime = true;
      while(divisor * divisor <= number) {
         if(number % divisor == 0)
            isPrime = false;
            break;
         divisor++;
      }
      if(isPrime) {
         printf("%d - *Drumroll Please*.....%d is a PRIME number!!\n", counter, number);
         counter++;
      }
      number++;
   }

   return 0;
}