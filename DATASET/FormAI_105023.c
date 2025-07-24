//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int number) {
  // check if number is divisible by any integer from 2 to the square root of the number
  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int count = 0;
  int limit = 100; // limit of how many prime numbers to generate
  int current = 2; // start checking from 2

  printf("The first %d prime numbers are:\n", limit);

  while (count < limit) {
    if (is_prime(current)) {
      printf("%d ", current);
      count++;
    }
    current++;
  }

  return 0;
}