//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>

int main() {
  int i, j;
  long long sum = 0;
  int arr[1000];

  for(i = 0; i < 1000; i++) {
    arr[i] = i + 1;
  }

  for(i = 0; i < 1000; i++) {
    for(j = 0; j < 1000; j++) {
      sum += arr[i] * arr[j];
    }
  }

  printf("Sum: %lld\n", sum);

  return 0;
}