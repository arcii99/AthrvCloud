//FormAI DATASET v1.0 Category: Digital signal processing ; Style: sophisticated
#include <stdio.h>
#include <math.h>

#define N 128
#define M_PI 3.14159265358979323846

int main(void) {
  double input[N], output[N];
  double frequency = 40.0;
  double amplitude = 1.0;

  // generate input signal
  for (int n = 0; n < N; n++) {
    input[n] = amplitude * sin(2.0 * M_PI * frequency * n / N);
  }

  // apply window to input signal
  for (int n = 0; n < N; n++) {
    double window = 0.54 - 0.46 * cos(2.0 * M_PI * n / (N - 1));
    input[n] *= window;
  }

  // compute DFT of input signal
  for (int k = 0; k < N; k++) {
    double real = 0.0, imag = 0.0;
    for (int n = 0; n < N; n++) {
      double phase = 2.0 * M_PI * k * n / N;
      real += input[n] * cos(phase);
      imag -= input[n] * sin(phase);
    }
    output[k] = sqrt(real*real + imag*imag);
  }

  // print output
  for (int k = 0; k < N; k++) {
    printf("%d %f\n", k, output[k]);
  }

  return 0;
}