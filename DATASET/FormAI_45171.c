//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: lively
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void primeNumbers(int n) {
  int count = 0;
  for (int i = 2; count < n; i++) {
    if (isPrime(i)) {
      printf("%d\n", i);
      count++;
    }
  }
}

int main() {
  int n;
  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &n);
  printf("The first %d prime numbers are:\n", n);
  primeNumbers(n);
  return 0;
}