//FormAI DATASET v1.0 Category: Digital signal processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 32           // Number of samples
#define Fs 8000.0      // Sampling frequency (Hz)
#define Fc 1000.0      // Carrier frequency (Hz)

int main()
{
  double x[N];             // Input data
  double y[N];             // Output data
  double t[N];             // Time values
  double c[N];             // Carrier signal

  int n;
  double dt = 1.0 / Fs;     // Time between samples

  // Generate input signal: 1 kHz sine wave modulated by 100 Hz sine wave
  for (n = 0; n < N; n++) {
    t[n] = n * dt;          // Time at sample n
    x[n] = sin(2.0 * M_PI * 100.0 * t[n]) + sin(2.0 * M_PI * (1000.0 + 50.0 * n) * t[n]);
  }

  // Generate carrier signal: 1 kHz sine wave
  for (n = 0; n < N; n++) {
    c[n] = sin(2.0 * M_PI * Fc * t[n]);
  }

  // Multiply input signal by carrier signal to perform modulation
  for (n = 0; n < N; n++) {
    y[n] = x[n] * c[n];
  }

  // Print input and output signals to file for visualization
  FILE *fp = fopen("dsp_example.txt", "w");
  for (n = 0; n < N; n++) {
    fprintf(fp, "%f %f %f\n", t[n], x[n], y[n]);
  }
  fclose(fp);

  return 0;
}