//FormAI DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

double sinc(double x) {
  if (x == 0) return 1.0;
  return sin(PI * x) / (PI * x);
}

double bessel(double x) {
  double j0, j1, y0, y1, jn, yn;
  j0 = j1 = y0 = y1 = 1.0;
  for (int n = 1; n < 10; n++) {
    jn = (2.0*n - 1.0) * j1 / x - j0;
    yn = (2.0*n - 1.0) * y1 / x - y0;
    j0 = j1;
    j1 = jn;
    y0 = y1;
    y1 = yn;
  }
  return j1;
}

int main() {
  double fm = 44100.0; // Sampling frequency
  double fc = 1000.0; // Cutoff frequency
  double Q = 1.0 / sqrt(2.0); // Quality factor
  double h[101]; // Impulse response
  for (int i = -50; i <= 50; i++) {
    double x = i / fm;
    if (i == 0) {
      h[i+50] = 2.0 * fc / fm;
    } else {
      h[i+50] = (2.0 * fc / fm) * sinc(2.0 * PI * fc * x) *
                bessel(2.0 * PI * Q * sqrt(fabs(x)));
    }
  }
  double x[10001]; // Input signal
  for (int i = 0; i < 10001; i++) {
    x[i] = sin(2.0 * PI * 1000.0 * i / fm);
  }
  double y[10001]; // Output signal
  for (int i = 0; i < 10001; i++) {
    y[i] = 0;
    for (int j = -50; j <= 50; j++) {
      if (i+j >= 0 && i+j < 10001) {
        y[i] += h[j+50] * x[i+j];
      }
    }
  }
  return 0;
}