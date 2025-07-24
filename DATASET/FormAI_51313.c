//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: happy
#include <stdio.h>

int main() {
  int i, j, n, isPrime;

  printf("Let's generate some prime numbers! How many do you want to generate? ");
  scanf("%d", &n);

  printf("\nHere are the first %d prime numbers:\n", n);

  /* 2 is the first prime number, so print it and then start checking from 3 */
  printf("2 ");

  for (i = 3; n > 1; i+=2) {  // increment i by 2 each time to skip even numbers
    isPrime = 1;  // assume the number is prime until proven otherwise

    for (j = 3; j*j <= i; j+=2) {  // increment j by 2 each time to skip even numbers
      if (i % j == 0) {
        isPrime = 0;  // found a factor, so the number is not prime
        break;  // no need to check further
      }
    }

    if (isPrime) {
      printf("%d ", i);
      n--;  // decrement the number of primes to generate
    }
  }

  printf("\nDone! Have a happy prime number day!\n");

  return 0;
}