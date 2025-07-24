//FormAI DATASET v1.0 Category: Digital signal processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int i, j, N = 200;
  double x[N], y[N], z[N], f[N], dt, T;

  // Generate a random signal
  for (i = 0; i < N; i++) {
    x[i] = rand() / (double) RAND_MAX;
  }

  // Use the FFT to analyze the signal
  dt = 0.01;
  T = dt * N;
  for (i = 0; i < N/2; i++) {
    f[i] = i / T;
    y[i] = 0.0;
    z[i] = 0.0;
    for (j = 0; j < N; j++) {
      y[i] += x[j] * cos(2 * M_PI * i * j / N);
      z[i] += x[j] * sin(2 * M_PI * i * j / N);
    }
  }

  // Apply a surreal filter to the signal
  for (i = 0; i < N/2; i++) {
    if (f[i] >= 0.5) {
      y[i] = -y[i];
      z[i] = -z[i];
    }
  }

  // Use the IFFT to generate the filtered signal
  for (i = 0; i < N; i++) {
    x[i] = 0.0;
    for (j = 0; j < N/2; j++) {
      x[i] += y[j] * cos(2 * M_PI * j * i / N) - z[j] * sin(2 * M_PI * j * i / N);
    }
    x[i] /= N;
  }

  // Print out the filtered signal
  for (i = 0; i < N; i++) {
    printf("%f\n", x[i]);
  }

  return 0;
}