//FormAI DATASET v1.0 Category: Digital signal processing ; Style: recursive
#include <stdio.h>

int recursive_dsp(int arr[], int length) {
  // Base case
  if (length == 0) {
    return 0;
  }
  
  // Recursive case
  int last_val = arr[length-1];
  
  // Filter coefficients
  float a = 0.8;
  float b = 0.2;
  
  // Recursive formula
  int filtered_val = b*last_val + a*recursive_dsp(arr, length-1);
  
  return filtered_val;
}

int main() {
  int input_signal[6] = {10, 14, 20, 25, 30, 35};
  int filtered_signal[6];
  
  for (int i = 0; i < 6; i++) {
    filtered_signal[i] = recursive_dsp(input_signal, i+1);
    printf("Input signal: %d, Filtered signal: %d\n", input_signal[i], filtered_signal[i]);
  }
  
  return 0;
}