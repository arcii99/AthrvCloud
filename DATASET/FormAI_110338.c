//FormAI DATASET v1.0 Category: Digital signal processing ; Style: curious
#include <stdio.h>

int main() {
  printf("Welcome to DSP example program!\n");

  // create array of samples
  float input[5] = {3.5, 2.1, -1.2, 0.8, -3.0};

  printf("Input samples:\n");
  for(int i=0; i<5; i++) {
    printf("%f\n", input[i]);
  }

  // apply scaling
  printf("Applying scaling of 2...\n");
  for(int i=0; i<5; i++) {
    input[i] = input[i] * 2;
  }

  printf("Scaled input samples:\n");
  for(int i=0; i<5; i++) {
    printf("%f\n", input[i]);
  }

  // apply low-pass filter
  printf("Applying low-pass filter with cutoff frequency of 1 Hz...\n");
  float output[5];
  float alpha = 0.1;
  output[0] = input[0];
  for(int i=1; i<5; i++) {
    output[i] = output[i-1] + alpha * (input[i] - output[i-1]);
  }

  printf("Filtered output samples:\n");
  for(int i=0; i<5; i++) {
    printf("%f\n", output[i]);
  }

  printf("Thank you for using this DSP example program!\n");
  
  return 0;
}