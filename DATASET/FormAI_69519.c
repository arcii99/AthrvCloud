//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: romantic
#include <stdio.h>

int isPrime(int n) {
  if (n < 2) {
    return 0;
  }

  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int n;
  printf("My love, please enter a number: ");
  scanf("%d", &n);

  printf("My darling, here are the prime numbers less than or equal to %d:\n", n);
  for (int i = 2; i <= n; i++) {
    if (isPrime(i)) {
      printf("%d, ", i);
    }
  }

  printf("\nMY LOVE, THANK YOU FOR USING OUR PRIME NUMBER GENERATOR <3\n");

  return 0;
}