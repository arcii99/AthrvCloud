//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: excited
// Yay! I'm so excited because I just wrote a C program that generates prime numbers!
#include <stdio.h>

int main() {
  int i, j, isPrime;

  printf("Let's generate some prime numbers!\n");

  // First, we'll loop through all the numbers between 2 and 100
  for (i = 2; i <= 100; i++) {
    // Assume the number is prime until proven otherwise
    isPrime = 1;

    // Now we'll loop through the number itself, testing if it's divisible by any number other than 1 and itself
    for (j = 2; j < i; j++) {
      if (i % j == 0) {
        // If we find a factor, the number isn't prime, so break out of the loop
        isPrime = 0;
        break;
      }
    }

    // If the number is prime, print it out!
    if (isPrime == 1) {
      printf("%d\n", i);
    }
  }

  printf("Wow, we found all the primes between 2 and 100! I can't wait to use this program again!\n");

  return 0;
}