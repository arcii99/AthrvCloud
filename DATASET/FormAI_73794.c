//FormAI DATASET v1.0 Category: Digital signal processing ; Style: curious
#include <stdio.h>

int main() {
  int num_samples, i;
  float input_signal[100], output_signal[100];
  
  printf("Enter the number of samples in the input signal: ");
  scanf("%d", &num_samples);
  
  printf("Enter the input signal:\n");
  for (i = 0; i < num_samples; i++) {
    scanf("%f", &input_signal[i]);
  }
  
  printf("\nOriginal Signal:\n");
  for (i = 0; i < num_samples; i++) {
    printf("%.2f ", input_signal[i]);
  }
  
  // Digital signal processing algorithm
  for (i = 0; i < num_samples; i++) {
    // Apply some processing to each sample
    output_signal[i] = input_signal[i] * 2;
  }
  
  printf("\nProcessed Signal:\n");
  for (i = 0; i < num_samples; i++) {
    printf("%.2f ", output_signal[i]);
  }
  
  return 0;
}