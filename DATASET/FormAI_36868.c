//FormAI DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_SAMPLES 1024

int main() {
  int i;
  float signal[N_SAMPLES];
  float output[N_SAMPLES];
  float a = 0.125;
  float b = 1 - a;

  // generate a test signal (sin wave)
  for (i = 0; i < N_SAMPLES; i++) {
    signal[i] = sin(2 * M_PI * i / N_SAMPLES);
  }

  // apply a simple low pass filter (moving average)
  for (i = 0; i < N_SAMPLES; i++) {
    if (i <= 1) {
      output[i] = signal[i];
    } else {
      output[i] = a * signal[i] + b * (output[i - 1] + output[i - 2]);
    }
  }

  // print out the original signal and filtered signal
  for (i = 0; i < N_SAMPLES; i++) {
    printf("%f %f\n", signal[i], output[i]);
  }

  return 0;
}