//FormAI DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define Fs 100  //Sampling frequency
#define Fc 25  //Cut-off frequency

int main() 
{
  float x[N] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};  //Input signal
  float y[N];  //Output signal
  float w[N];  //Window function
  float h[N];  //Filter coefficients
  float pi = 3.14159;

  for (int i = 0; i < N; i++)
  {
    w[i] = 0.54 - 0.46 * cos(2 * pi * i / (N - 1));  //Hamming window function
    h[i] = (sin(2 * pi * Fc * (i - (N - 1) / 2) / Fs) / (i - (N - 1) / 2)) * w[i];  //Filter coefficients using sinc function and window function
  }

  for (int i = 0; i < N; i++)
  {
    y[i] = 0;
    for (int j = 0; j < N; j++)
    {
      if (i - j >= 0)
      {
        y[i] += h[j] * x[i - j];  //Convolution of input signal and filter coefficients
      }
    }
  }

  printf("Input signal: ");
  for (int i = 0; i < N; i++)
  {
    printf("%.2f ", x[i]);
  }

  printf("\nOutput signal: ");
  for (int i = 0; i < N; i++)
  {
    printf("%.2f ", y[i]);
  }

  return 0;
}