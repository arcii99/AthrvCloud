//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Alan Touring
#include <stdio.h>

int is_prime(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

void generate_primes(int n) {

  printf("Generating the first %d prime numbers\n", n);

  int count = 0;
  int i = 2;

  while (count < n) {
    if (is_prime(i)) {
      printf("%d ", i);
      count++;
    }
    i++;
  }
  printf("\n");
}

int main() {
  generate_primes(50);
  return 0;
}