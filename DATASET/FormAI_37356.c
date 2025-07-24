//FormAI DATASET v1.0 Category: Digital signal processing ; Style: lively
#include <stdio.h>
#include <math.h>

// Define the number of samples to process
#define NUM_SAMPLES 100

int main() {

  // Initialize the input and output arrays
  double input[NUM_SAMPLES], output[NUM_SAMPLES];

  // Generate a sinusoidal input signal
  for (int i = 0; i < NUM_SAMPLES; i++) {
    input[i] = sin((double)i*2.0*M_PI/(double)NUM_SAMPLES);
  }

  // Apply a moving average filter to the input signal
  for (int i = 0; i < NUM_SAMPLES; i++) {
    double sum = 0.0;
    int count = 0;
    for (int j = -4; j <= 4; j++) {
      if (i+j >= 0 && i+j < NUM_SAMPLES) {
        sum += input[i+j];
        count++;
      }
    }
    output[i] = sum/count;
  }

  // Print the output signal to the console
  printf("Input Signal\tOutput Signal\n");
  for (int i = 0; i < NUM_SAMPLES; i++) {
    printf("%f\t%f\n", input[i], output[i]);
  }

  return 0;
}