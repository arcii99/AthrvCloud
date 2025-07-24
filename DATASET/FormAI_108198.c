//FormAI DATASET v1.0 Category: Digital signal processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000 // Length of input signal
#define M 10 // Filter order (number of taps)

int main()
{
  float h[M], x[N], y[N];
  int n, i;

  // Generate input signal
  for (n = 0; n < N; n++) {
    x[n] = sin(2 * M_PI * 5000 * n / 44100) + sin(2 * M_PI * 10000 * n / 44100);
  }

  // Generate filter taps
  for (i = 0; i < M; i++) {
    h[i] = sin(2 * M_PI * 2000 * i / 44100) / (M_PI * i);
  }

  // Zero pad input signal
  for (n = N; n < N + M - 1; n++) {
    x[n] = 0;
  }

  // Apply filter
  for (n = 0; n < N; n++) {
    y[n] = 0;
    for (i = 0; i < M; i++) {
      y[n] += h[i] * x[n - i + M - 1];
    }
  }

  // Print output signal
  for (n = 0; n < N; n++) {
    printf("%f\n", y[n]);
  }

  return 0;
}