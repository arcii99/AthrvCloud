//FormAI DATASET v1.0 Category: Digital signal processing ; Style: medieval
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  // creating an array of input signals
  int input[8] = {10, 20, 30, 40, 50, 60, 70, 80};
  // creating an array to store output signals
  int output[8];
  
  // applying a medieval low-pass filter to the input signals
  int i;
  for (i = 0; i < 8; i++) {
    if (input[i] > 50) {
      output[i] = (input[i] + input[i-1] + input[i-2]) / 3;
    }
    else if (input[i] > 30) {
      output[i] = (input[i] + input[i-1]) / 2;
    }
    else {
      output[i] = input[i];
    }
  }
  
  // printing the output signals
  printf("Input signals: ");
  for (i = 0; i < 8; i++) {
    printf("%d ", input[i]);
  }
  printf("\n");
  
  printf("Output signals: ");
  for (i = 0; i < 8; i++) {
    printf("%d ", output[i]);
  }
  printf("\n");

  return 0;
}