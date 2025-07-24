//FormAI DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>

// Defining the signal length and coefficients
#define SIGNAL_LENGTH 8
float coefficients[SIGNAL_LENGTH] = {0.1, -0.2, 0.5, -0.6, 0.7, -0.8, 0.9, -1.0};

// Initializing the signal array
float signal[SIGNAL_LENGTH] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};

void main() {
  printf("Starting digital signal processing...\n");
  printf("Signal before processing:\n");

  // Printing the signal array before processing
  for(int i=0; i<SIGNAL_LENGTH; i++) {
    printf("%.1f ", signal[i]);
  }

  // Applying the filter to the signal
  printf("\nApplying filter with coefficients: ");
  for(int i=0; i<SIGNAL_LENGTH; i++) {
    printf("%.1f ", coefficients[i]);
  }
  printf("\n");

  // Initializing the filtered signal array
  float filtered_signal[SIGNAL_LENGTH];

  // Applying the filter
  for(int i=0; i<SIGNAL_LENGTH; i++) {
    filtered_signal[i] = 0;
    for(int j=0; j<SIGNAL_LENGTH; j++) {
      if(i-j >= 0) {
        filtered_signal[i] += signal[j] * coefficients[i-j];
      }
    }
  }

  printf("Signal after processing:\n");

  // Printing the filtered signal array
  for(int i=0; i<SIGNAL_LENGTH; i++) {
    printf("%.1f ", filtered_signal[i]);
  }

  printf("\nDigital signal processing complete!\n");
}