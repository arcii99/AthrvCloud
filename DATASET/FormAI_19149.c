//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surprised
#include <stdio.h>

int main() {
  int arr[1000000];
  int sum = 0;

  for (int i = 0; i < 1000000; i++) {
    arr[i] = i;
  }

  for (int i = 0; i < 1000000; i++) {
    sum += arr[i];
    if (i % 100000 == 0) {
      printf("Sum calculated for %d elements\n", i);
    }
  }

  printf("Sum of first million integers: %d\n", sum);

  return 0;
}