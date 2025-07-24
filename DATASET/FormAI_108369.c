//FormAI DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>

#define N 10

int main() {
  int x[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int y[N];
  int i;

  // Apply moving average filter
  for (i = 0; i < N; i++) {
    if (i < 2) {
      y[i] = x[i];
    } else {
      y[i] = (x[i] + x[i-1] + x[i-2]) / 3;
    }
  }

  // Print input and output signals
  printf("Input Signal (x):\n");
  for (i = 0; i < N; i++) {
    printf("%d ", x[i]);
  }
  printf("\n\nOutput Signal (y):\n");
  for (i = 0; i < N; i++) {
    printf("%d ", y[i]);
  }

  return 0;
}