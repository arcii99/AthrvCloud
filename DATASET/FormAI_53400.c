//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>

int recursiveSum(int n);

int main() {
  int n = 5;
  int sum = recursiveSum(n);
  printf("The sum of the first %d integers is %d", n, sum);
  return 0;
}

int recursiveSum(int n) {
  if (n == 0) {
    return 0;
  } else {
    int sum = n + recursiveSum(n-1);
    printf("Calculating the sum of the first %d integers: %d\n", n, sum);
    return sum;
  }
}