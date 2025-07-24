//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Romeo and Juliet
// Romeo and Juliet C Prime Number Generator

#include <stdio.h>
#include <math.h>

int main() {
  int i, j, n;

  // Introduction
  printf("My dear Romeo, let us generate some prime numbers together.\n");
  printf("How many primes would you like to find, my sweet Juliet?\n");
  scanf("%d", &n);
  printf("Ah, %d is such a beautiful number indeed!\n", n);

  // Initializing Variables and Setting Counter
  int count = 0;
  int number = 1;

  // Looping through Numbers and Checking for Prime
  while (count < n) {
    int isPrime = 1; // Assume Number is a Prime
    number++;

    // Checking if Number is Prime
    for (i = 2; i <= sqrt(number); i++) {
      if (number % i == 0) {
        isPrime = 0; // Not a Prime
        break;
      }
    }

    // Displaying Prime Number
    if (isPrime == 1) {
      count++;
      printf("%d is a prime number, my darling Romeo!\n", number);
    }
  }

  // Final Farewell
  printf("Oh sweet Romeo, we have found %d prime numbers together.\n", n);
  printf("Let us celebrate our love for each other and for mathemagics!\n");
  printf("Farewell until we meet again, my love!\n");

  return 0;
}