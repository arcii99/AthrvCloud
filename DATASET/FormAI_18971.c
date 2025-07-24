//FormAI DATASET v1.0 Category: Digital signal processing ; Style: interoperable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
  int i, j, N, M;
  double alpha;
  double x[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  double y[8] = {0};
  double w[8], v[8];
  double real_sum, imag_sum, real_coef, imag_coef;

  // Calculate the number of points and the angle increment
  N = 8;
  M = N/2;
  alpha = 2 * PI / N;

  // Calculate the weights
  for (i = 0; i < N; i++) {
    w[i] = 1;
    v[i] = 0;
    for (j = 0; j < M; j++) {
      w[i] *= cos(alpha * (i * j)) - sin(alpha * (i * j));
      v[i] += (sin(alpha * (i * j)) + cos(alpha * (i * j))) 
                  * (x[j] - x[2 * M + j]);
    }
  }

  // Calculate the DFT
  for (i = 0; i < N; i++) {
    real_sum = 0;
    imag_sum = 0;
    for (j = 0; j < N; j++) {
      real_coef = cos(alpha * i * j);
      imag_coef = sin(alpha * i * j);
      real_sum += w[j] * (x[j] * real_coef + y[j] * imag_coef);
      imag_sum += w[j] * (y[j] * real_coef - x[j] * imag_coef);
    }
    x[i] = real_sum + v[i];
    y[i] = imag_sum;
  }

  // Print the results
  printf("Input Signal:\n");
  for (i = 0; i < N; i++) {
    printf("%f ", x[i]);
  }
  printf("\n");

  printf("Output Signal:\n");
  for (i = 0; i < N; i++) {
    printf("%f ", sqrt(x[i] * x[i] + y[i] * y[i]));
  }
  printf("\n");

  return 0;
}