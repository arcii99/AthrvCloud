//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  int n, i, j, isPrime;

  printf("Enter a positive integer: ");
  scanf("%d", &n);

  printf("Prime numbers between 1 and %d are: ", n);

  // prime numbers start from 2
  for (i = 2; i <= n; ++i) {
    isPrime = 1;

    // check if the number is divisible by any number except itself and 1
    for (j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        isPrime = 0;
        break;
      }
    }

    // print prime numbers
    if (isPrime == 1) {
      printf("%d ", i);
    }
  }

  return 0;
}