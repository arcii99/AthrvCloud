//FormAI DATASET v1.0 Category: Digital signal processing ; Style: immersive
#include <stdio.h>

int main() {
  printf("Welcome to the Digital Signal Processing example!\n");
  printf("This program will take four input values and apply a Digital Signal Processing algorithm to them.\n");
  
  float input[4]; // This array will hold the input values
  float output[4]; // This array will hold the output values
  
  // Ask the user to enter four input values
  for (int i = 0; i < 4; i++) {
    printf("Enter input value %d: ", i+1);
    scanf("%f", &input[i]);
    // Make sure the value is within range (-10 to 10)
    if (input[i] > 10) {
      input[i] = 10;
    } else if (input[i] < -10) {
      input[i] = -10;
    }
  }
  
  // Apply the DSP algorithm to each input value
  for (int i = 0; i < 4; i++) {
    output[i] = (input[i] + (0.5 * input[(i+1)%4]) + (0.25 * input[(i+2)%4]) + (0.125 * input[(i+3)%4])) / 2;
  }
  
  // Print the output values
  printf("The output values are:\n");
  for (int i = 0; i < 4; i++) {
    printf("%f ", output[i]);
  }
  printf("\n");

  return 0;
}