//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
  if (n <= 1) {
    return false;
  }

  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

void printPrimeNumbers(int n) {
  printf("Prime numbers between 1 and %d:\n", n);

  for (int i = 2; i <= n; i++) {
    if (isPrime(i)) {
      printf("%d ", i);
    }
  }

  printf("\n");
}

int main() {
  int n;

  printf("Enter a positive integer: ");
  scanf("%d", &n);

  printPrimeNumbers(n);

  return 0;
}