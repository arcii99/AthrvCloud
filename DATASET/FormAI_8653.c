//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>

int main() {
  int max_num, i, j, is_prime;

  printf("Enter the maximum number to check for prime numbers: ");
  scanf("%d", &max_num);

  printf("The prime numbers between 1 and %d are: \n", max_num);

  // Check for prime numbers
  for (i = 2; i <= max_num; i++) {
    is_prime = 1;
    for (j = 2; j <= i/2; j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      printf("%d\n", i);
    }
  }

  return 0;
}