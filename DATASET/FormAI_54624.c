//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include <stdio.h>

int main() {
  int n, i, flag = 0;

  printf("Enter an integer: ");
  scanf("%d", &n);

  // Handling the prime number generator
  if (n == 0 || n == 1) {
    printf("%d is not a prime number.\n", n);
  } else {
    for (i = 2; i <= n / 2; ++i) {
      if (n % i == 0) {
        flag = 1;
        break;
      }
    }

    if (flag == 0)
      printf("%d is a prime number.\n", n);
    else
      printf("%d is not a prime number.\n", n);
  }

  return 0;
}