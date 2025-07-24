//FormAI DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include <stdio.h>

int main() {

  int input_signal[5] = {1, 2, 3, 4, 5};
  int output_signal[5];
  int filter_coefficients[3] = {1, 2, 1};

  // Convolution operation
  for(int i=0; i<5; i++) {
    output_signal[i] = 0;
    for(int j=0; j<3; j++) {
      if(i-j>=0 && i-j<5) {
        output_signal[i] += input_signal[i-j] * filter_coefficients[j];
      }
    }
  }

  // Printing the original and filtered signals
  printf("Original Signal: ");
  for(int i=0; i<5; i++) {
    printf("%d ", input_signal[i]);
  }
  
  printf("\nFiltered Signal: ");
  for(int i=0; i<5; i++) {
    printf("%d ", output_signal[i]);
  }

  return 0;
}