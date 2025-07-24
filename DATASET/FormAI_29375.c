//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>

int is_prime(int num) {
  if (num == 1) {
    return 0;
  }
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int max_num;
  printf("Please enter a maximum number to check for primes: ");
  scanf("%d", &max_num);

  for (int i = 2; i <= max_num; i++) {
    if (is_prime(i)) {
      printf("%d is a prime number!\n", i);
    }
  }

  printf("Thanks for using the prime number generator!\n");

  return 0;
}