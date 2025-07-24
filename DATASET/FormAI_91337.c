//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Ada Lovelace
// PROGRAM TO PERFORM SUMMATION OF N NUMBERS.
// WRITTEN BY ADA LOVELACE STYLE

#include <stdio.h>

int main() {

  int n, sum = 0, i;

  printf("Enter the number of values to be added : ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    sum = sum + i;
  }

  printf("The sum of first %d natural numbers is: %d\n", n, sum);
  return 0;
}