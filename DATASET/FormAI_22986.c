//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Alan Touring
#include <stdio.h>

int main() {
  int i, n, count, is_prime;
  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &n);

  // The first two prime numbers are 2 and 3
  printf("Prime numbers:\n2\n3\n");
  count = 2; // Count starts from 2 since we already have 2 and 3

  for (i = 5; count < n; i += 2) { // Start from 5 and increment by 2 to get only odd numbers
    is_prime = 1; // Assume number is prime unless proven otherwise

    // Check if number is divisible by any odd number less than or equal to its square root
    for (int j = 3; j * j <= i; j += 2) {
      if (i % j == 0) {
        is_prime = 0; // Number is not prime
        break;
      }
    }

    // If number is prime, print it and increment count
    if (is_prime) {
      printf("%d\n", i);
      count++;
    }
  }

  return 0;
}