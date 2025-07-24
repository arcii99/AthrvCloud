//FormAI DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>

int main() {
  int num, denom;

  printf("Enter the numerator: ");
  if (scanf("%d", &num) != 1) {
    fputs("Error: Invalid input!\n", stderr);
    return 1;
  }

  printf("Enter the denominator: ");
  if (scanf("%d", &denom) != 1) {
    fputs("Error: Invalid input!\n", stderr);
    return 1;
  }

  if (denom == 0) {
    fputs("Error: Division by zero!\n", stderr);
    return 1;
  }

  double result = num / (double)denom;

  printf("%d / %d = %f\n", num, denom, result);

  return 0;
}