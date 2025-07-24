//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>

// Function to check if a number is prime
int isPrime(int n) {
  if (n <= 1)
    return 0;

  // Check for factors
  for (int i = 2; i <= n/2; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int limit;
  printf("Enter the limit: ");
  scanf("%d", &limit);

  // Determine the type of prime numbers to be generated
  int type;
  printf("What type of prime numbers do you want to generate?\n");
  printf("1. All prime numbers\n");
  printf("2. Only twin prime numbers\n");
  printf("3. Only prime numbers that are sums of two primes\n");
  printf("Enter your choice: ");
  scanf("%d", &type);

  if (type < 1 || type > 3) {
    printf("Invalid choice.\n");
    return 1;
  }

  switch (type) {
    case 1:
      printf("All prime numbers up to %d are:\n", limit);
      for (int i = 2; i <= limit; i++) {
        if (isPrime(i))
          printf("%d ", i);
      }
      break;

    case 2:
      printf("All twin prime numbers up to %d are:\n", limit);
      for (int i = 2; i <= limit - 2; i++) {
        if (isPrime(i) && isPrime(i + 2))
          printf("(%d,%d) ", i, i+2);
      }
      break;

    case 3:
      printf("All prime numbers that are sums of two primes up to %d are:\n", limit);
      for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
          int found = 0;
          for (int j = 2; j <= i/2; j++) {
            if (isPrime(j) && isPrime(i-j)) {
              printf("%d ", i);
              found = 1;
              break;
            }
          }
          if (found)
            printf("\n");
        }
      }
      break;
  }

  return 0;
}