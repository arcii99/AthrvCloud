//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Alan Touring
#include <stdio.h>

int main() {
  float signal[10] = {1.5, 2.0, 4.0, 3.5, 2.5, 3.0, 5.0, 6.5, 8.0, 7.5};
  float filtered_signal[10];
  float b_coef[4] = {0.25, 0.5, 0.75, 0.5};
  float a_coef[4] = {1.0, -0.5, 0.25, -0.125};
  
  // apply a digital filter to the signal
  for (int n = 0; n < 10; n++) {
    filtered_signal[n] = 0;
    for (int j = 0; j < 4; j++) {
      if ((n-j) >= 0) {
        filtered_signal[n] += b_coef[j] * signal[n-j];
      }
      if ((n-j) > 0) {
        filtered_signal[n] -= a_coef[j] * filtered_signal[n-j-1];
      }
    }
  }
  
  // print the original and filtered signals
  printf("Original Signal:\n");
  for (int n = 0; n < 10; n++) {
    printf("%.2f ", signal[n]);
  }
  printf("\n\nFiltered Signal:\n");
  for (int n = 0; n < 10; n++) {
    printf("%.2f ", filtered_signal[n]);
  }
  
  return 0;
}