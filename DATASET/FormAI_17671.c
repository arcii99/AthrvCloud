//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ken Thompson
#include <stdio.h>

int main() {
  int count = 0, n = 2;

  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &count);

  while (count > 0) {
    int is_prime = 1;
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      printf("%d ", n);
      count--;
    }
    n++;
  }

  return 0;
}