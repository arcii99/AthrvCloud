//FormAI DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to print the input signal
void printSignal(float* signal, int length) {
  int i;
  printf("Input Signal: [ ");
  for (i = 0; i < length; i++) {
    printf("%f ", signal[i]);
  }
  printf("]\n");
}

// Function to print the output signal
void printOutput(float* output, int length) {
  int i;
  printf("Output Signal: [ ");
  for (i = 0; i < length; i++) {
    printf("%f ", output[i]);
  }
  printf("]\n");
}

int main() {
  // Define the input signal
  float inputSignal[1000];
  int i;
  for (i = 0; i < 1000; i++) {
    inputSignal[i] = sin(i*0.01) + sin(i*0.02) + sin(i*0.03);
  }

  // Print the input signal
  printSignal(inputSignal, 1000);

  // Allocate memory for the output signal
  float* outputSignal = (float*) malloc(1000*sizeof(float));

  // Apply the low-pass filter
  for (i = 0; i < 1000; i++) {
    if (i == 0) {
      outputSignal[i] = inputSignal[0];
    } else {
      outputSignal[i] = 0.25*outputSignal[i-1] + 0.75*inputSignal[i];
    }
  }

  // Print the output signal
  printOutput(outputSignal, 1000);

  // Free the memory
  free(outputSignal);

  return 0;
}