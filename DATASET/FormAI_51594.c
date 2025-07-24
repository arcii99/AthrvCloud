//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
/*
Author: Dennis Ritchie
Title: Digital Signal Processing Example in C
Description: This program performs FIR filtering on an input signal
*/

#include <stdio.h>
#include <stdlib.h>

#define FILTER_LENGTH 50

int main() {

  float input_signal[1000]; // Input signal array
  float output_signal[1000]; // Output signal array
  float filter_coeffs[FILTER_LENGTH]; // FIR filter coefficients array
  int signal_length = 1000; // Length of input signal
  int i, j; // Loop variables

  // Initialize input signal array with random values between -1 and 1
  for (i = 0; i < signal_length; i++) {
    input_signal[i] = ((float)rand()/(float)RAND_MAX)*2.0 - 1.0;
  }

  // Initialize FIR filter coefficients with random values between -0.1 and 0.1
  for (i = 0; i < FILTER_LENGTH; i++) {
    filter_coeffs[i] = ((float)rand()/(float)RAND_MAX)*0.2 - 0.1;
  }

  // Perform FIR filtering on input signal
  for (i = 0; i < signal_length-FILTER_LENGTH; i++) {
    output_signal[i] = 0.0;
    for (j = 0; j < FILTER_LENGTH; j++) {
      output_signal[i] += input_signal[i+j] * filter_coeffs[j];
    }
  }

  // Print out filtered signal
  for (i = 0; i < signal_length-FILTER_LENGTH; i++) {
    printf("%f\n", output_signal[i]);
  }

  return 0;
}