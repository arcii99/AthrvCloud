//FormAI DATASET v1.0 Category: Digital signal processing ; Style: excited
#include <stdio.h>

/* Excited DSP Example Program */

int main() {
  printf("Welcome to the Exciting DSP program!\nGet ready for some serious digital signal processing!\n");

  // Initialize input signal array
  float input_signal[5] = {1.5, 2.0, 0.5, 1.0, 3.5};

  // Print out input signal
  printf("Input signal:\n");
  for(int i = 0; i < 5; i++) {
    printf("%f ", input_signal[i]);
  }
  printf("\n");

  // Apply filter
  printf("Filtering signal...\n");

  // Initialize filter coefficients
  float filter_coeffs[3] = {0.5, 0.7, 0.2};

  // Initialize output signal array
  float output_signal[3] = {0.0, 0.0, 0.0};

  // Perform convolution
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(i - j >= 0 && i - j < 5) {
        output_signal[i] += input_signal[i - j] * filter_coeffs[j];
      }
    }
  }

  // Print out filtered signal
  printf("Filtered signal:\n");
  for(int i = 0; i < 3; i++) {
    printf("%f ", output_signal[i]);
  }
  printf("\n");

  printf("Wow, that was some exciting digital signal processing!\nThanks for using this program!\n");

  return 0;
}