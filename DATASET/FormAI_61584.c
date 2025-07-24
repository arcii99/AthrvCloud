//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>

int main() {
  printf("This is the Prime Number Generator program!\n");
  printf("Please enter the maximum number that you want to generate prime numbers up to: ");
  int max;
  scanf("%d", &max);
  printf("Generating prime numbers up to %d...\n", max);

  int primes[max+1];
  primes[0] = 0;
  primes[1] = 0;
  for (int i = 2; i < max+1; i++) {
    primes[i] = 1;
  }

  for (int i = 2; i < max+1; i++) {
    if (primes[i] == 1) {
      printf("%d ", i);
      for (int j = i; j < max+1; j += i) {
        primes[j] = 0;
      }
    }
  }
  printf("\n");
  printf("Done generating prime numbers up to %d.\n", max);
  return 0;
}