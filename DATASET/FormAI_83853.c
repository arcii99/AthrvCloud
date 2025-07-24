//FormAI DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>

int main() {
  printf("Wow, I just wrote a C Digital Signal Processing program!\n");
  
  float input_samples[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
  float output_samples[10] = {0};
  
  printf("The input samples are:\n");
  for(int i=0; i<10; i++) {
    printf("%f\n", input_samples[i]);
  }
  
  for(int i=1; i<9; i++) {
    output_samples[i] = (0.125 * input_samples[i-1]) + (0.75 * input_samples[i]) + (0.125 * input_samples[i+1]);
  }
  
  printf("The output samples are:\n");
  for(int i=0; i<10; i++) {
    printf("%f\n", output_samples[i]);
  }
  
  printf("Amazing, I just implemented a simple low-pass filter using DSP techniques.\n");
  
  return 0;
}