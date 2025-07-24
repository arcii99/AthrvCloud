//FormAI DATASET v1.0 Category: Digital signal processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

int main() {
  double frequency = 440.0; // Hz
  double amplitude = 0.5;
  double duration = 1.0; // seconds

  // Signal generation
  int n_samples = duration * SAMPLE_RATE;
  double* signal = (double*)malloc(n_samples * sizeof(double));
  for (int i = 0; i < n_samples; i++) {
    double time = (double)i / SAMPLE_RATE;
    signal[i] = amplitude * sin(2 * PI * frequency * time);
  }

  // Signal processing
  for (int i = 0; i < n_samples; i++) {
    signal[i] *= exp(-0.001 * i);
  }

  // Signal output
  printf("const float SIGNAL[] = {\n");
  for (int i = 0; i < n_samples; i++) {
    if (i % 8 == 0) printf(" ");
    printf("%ff, ", signal[i]);
    if (i % 8 == 7) printf("\n");
  }
  if ((n_samples - 1) % 8 != 7) printf("\n");
  printf("};\n");

  free(signal);
  return 0;
}