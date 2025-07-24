//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
  if (num <= 1) {
    return false;
  }

  for (int i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, count = 0;
  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &n);

  int primes[n];

  for (int i = 2; count < n; i++) {
    if (isPrime(i)) {
      primes[count++] = i;
    }
  }

  printf("The first %d prime numbers are: ", n);
  for (int i = 0; i < n; i++) {
    printf("%d ", primes[i]);
  }

  return 0;
}