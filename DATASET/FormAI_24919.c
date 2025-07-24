//FormAI DATASET v1.0 Category: Digital signal processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Fs 8000 // Sample rate

int main() {
  int N = 128; // Number of samples
  double f0 = 500.0/Fs; // Normalized frequency
  double theta = 0; // Phase offset
  double x[N]; // Input signal
  double y[N]; // Output signal
  double w = 2*M_PI*f0; // Angular frequency
  int n;

  // Generate input signal
  for (n = 0; n < N; n++) {
    x[n] = sin(w*n + theta);
  }
  
  // Apply FIR filter
  double b[3] = {1.0, 0.5, 0.25}; // Filter coefficients
  for (n = 0; n < N; n++) {
    if (n >= 2) {
      y[n] = b[0]*x[n] + b[1]*x[n-1] + b[2]*x[n-2];
    }
  }
  
  // Compute spectrum of input and output signals
  double X[N], Y[N];
  double df = Fs/N; // Frequency step
  for (n = 0; n < N; n++) {
    X[n] = 20*log10(fabs(x[n]));
    Y[n] = 20*log10(fabs(y[n]));
  }

  // Display results
  printf("Input signal:\n");
  for (n = 0; n < N; n++) {
    printf("%d: %f\n", n, x[n]);
  }
  
  printf("Output signal:\n");
  for (n = 0; n < N; n++) {
    printf("%d: %f\n", n, y[n]);
  }
  
  printf("Input spectrum:\n");
  for (n = 0; n < N/2; n++) {
    printf("%f Hz: %f dB\n", n*df, X[n]);
  }
  
  printf("Output spectrum:\n");
  for (n = 0; n < N/2; n++) {
    printf("%f Hz: %f dB\n", n*df, Y[n]);
  }

  return 0;
}