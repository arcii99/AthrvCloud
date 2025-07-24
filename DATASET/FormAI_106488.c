//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>

int main() {
  printf("Surprise! Here's a prime number generator!\n");
  printf("Enter the range of numbers you want to generate prime numbers for:\n");

  int lower_bound, upper_bound;
  scanf("%d %d", &lower_bound, &upper_bound);

  for (int i = lower_bound; i <= upper_bound; i++) {
    int j;

    for (j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        break;
      }
    }

    if (j > i / 2) {
      printf("%d ", i);
    }
  }

  printf("\nYou're welcome for the prime numbers!");
  return 0;
}