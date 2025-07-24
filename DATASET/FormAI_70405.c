//FormAI DATASET v1.0 Category: Digital signal processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

int main()
{
  float s[N], y[N];
  float mean = 0.0, var = 0.0, std_dev = 0.0;
  int i;
  
  // Generate Input Signal
  for(i = 0; i < N; i++)
  {
    s[i] = sin(2 * M_PI * i * 0.1) + (rand() / RAND_MAX);
  }
  
  // Calculate Mean
  for(i = 0; i < N; i++)
  {
    mean += s[i];
  }
  mean /= N;
  
  // Calculate Variance
  for(i = 0; i < N; i++)
  {
    var += pow(s[i] - mean, 2);
  }
  var /= N - 1;
  
  // Calculate Standard Deviation
  std_dev = sqrt(var);
  
  // Normalize Signal
  for(i = 0; i < N; i++)
  {
    y[i] = (s[i] - mean) / std_dev;
  }
  
  // Print Input and Output Signals
  printf("Input Signal:\n");
  for(i = 0; i < N; i++)
  {
    printf("%f ", s[i]);
  }
  printf("\n\nOutput Signal:\n");
  for(i = 0; i < N; i++)
  {
    printf("%f ", y[i]);
  }
  printf("\n\n");
  
  return 0;
}