//FormAI DATASET v1.0 Category: Digital signal processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the moving average of an input signal
void moving_average(float input_signal[], int length, float output_signal[], int window_size) {

  int i, j;
  float sum = 0.0;

  // Loop through the input signal
  for (i = 0; i < length; i++) {

    // Reset the sum to zero
    sum = 0.0;

    // Calculate the windowed sum
    for (j = i - window_size + 1; j <= i; j++) {
      if (j >= 0) {
        sum += input_signal[j];
      }
    }

    // Store the output signal
    output_signal[i] = sum / window_size;
  }
}

int main() {

  // Create an input signal
  float input_signal[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

  // Set the window size
  int window_size = 3;

  // Calculate the length of the input signal
  int length = sizeof(input_signal) / sizeof(float);

  // Create an output signal
  float output_signal[length];

  // Calculate the moving average
  moving_average(input_signal, length, output_signal, window_size);

  // Print the input and output signals
  printf("Input signal: ");
  for (int i = 0; i < length; i++) {
    printf("%.1f ", input_signal[i]);
  }
  printf("\n");

  printf("Output signal: ");
  for (int i = 0; i < length; i++) {
    printf("%.1f ", output_signal[i]);
  }
  printf("\n");

  return 0;
}