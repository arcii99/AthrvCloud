//FormAI DATASET v1.0 Category: Syntax parsing ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i, sum = 0;

  printf("Enter an integer: ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Error: Invalid input.");
    return 0;
  }

  for (i = 1; i <= n; i++) {
    sum += i;
  }

  printf("The sum of the first %d integers is %d.", n, sum);

  return 0;
}