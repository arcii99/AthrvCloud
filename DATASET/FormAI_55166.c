//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>

int main() {
  int i, j, n, prime, count = 0;
  printf("Enter the number up to which you want to find prime numbers: ");
  scanf("%d", &n);

  for (i = 2; i <= n; i++) {
    prime = 1;
    for (j = 2; j <= i / 2; j++) {
      if ((i % j) == 0) {
        prime = 0;
        break;
      }
    }
    if (prime == 1) {
      printf("%d ", i);
      count++;
      if (count % 10 == 0) {
        printf("\n");
      }
    }
  }
  printf("\n");
  return 0;
}