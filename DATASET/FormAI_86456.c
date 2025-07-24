//FormAI DATASET v1.0 Category: Digital signal processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define M 10

int main()
{
  int i, j, k, t;
  float input[N];
  float output[M];
  float h[M] = {1, -2.3, 3.5, -4.2, 5.0, -6.1, 7.3, -8.6, 9.2, -10.0};
  float buffer[M];
  float sum;
  float variance, std_dev;

  // Generate input signal
  for (i=0; i<N; i++) {
    input[i] = sin(i*(2*M_PI)/N) + 0.5*sin(4*i*(2*M_PI)/N);
  }

  // Convolution
  for (i=0; i<=N-M; i++) {
    sum = 0;
    for (j=0; j<M; j++) {
      buffer[j] = input[i+(M-1)-j];
      sum += h[j]*buffer[j];
    }
    output[i] = sum;
  }

  // Calculate statistics of output signal
  sum = 0;
  for (i=0; i<N-M; i++) {
    sum += output[i];
  }
  float mean = sum/(N-M);

  sum = 0;
  for (i=0; i<N-M; i++) {
    sum += pow(output[i]-mean, 2);
  }
  variance = sum/(N-M-1);
  std_dev = sqrt(variance);

  // Print output signal and statistics
  printf("Output signal:\n");
  for (i=0; i<N-M; i++) {
    printf("%f ", output[i]);
  }
  printf("\n");

  printf("Statistics:\n");
  printf("Mean = %f\n", mean);
  printf("Variance = %f\n", variance);
  printf("Standard deviation = %f\n", std_dev);

  return 0;
}