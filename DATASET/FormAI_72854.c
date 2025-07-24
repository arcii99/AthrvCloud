//FormAI DATASET v1.0 Category: Digital signal processing ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793 // Define pi for use in calculations

int main()
{
  int n, k;

  // Define input signal x[n]
  float x[] = {0.707, 1.0, 0.707, 0.0, -0.707, -1.0, -0.707, 0.0};

  // Define output signal, y[k]
  float y[8];

  // Calculate the DFT using the equation:
  // y[k] = 1/N * sum_{n=0}^{N-1} x[n] * e^{-j(2*pi/N)kn}
  for (k = 0; k < 8; k++) {
    y[k] = 0;
    for (n = 0; n < 8; n++) {
      y[k] += x[n] * cos(-2 * PI * k * n / 8) - sin(-2 * PI * k * n / 8);
    }
    y[k] /= 8; // Normalize y[k]
  }

  // Print the output signal, y[k]
  printf("Output Signal: ");
  for (k = 0; k < 8; k++) {
    printf("%.3f ", y[k]);
  }

  return 0;
}