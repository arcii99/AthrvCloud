//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: innovative
#include <stdio.h>

int main() {
  int n, i, j, flag;
  printf("Enter the number of primes you wish to generate: ");
  scanf("%d", &n);

  // the first prime number is 2
  printf("2\n");

  for (i = 3; i <= n; i++) {
    flag = 1;
    for (j = 2; j < i; j++) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      printf("%d\n", i);
    }
  }
  return 0;
}