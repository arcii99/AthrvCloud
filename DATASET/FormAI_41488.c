//FormAI DATASET v1.0 Category: Digital signal processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 48000 // Sample rate is 48 kHz
#define FREQUENCY 1000 // Signal frequency is 1 kHz
#define AMPLITUDE 0.5 // Signal amplitude is 0.5
#define BUFF_SIZE 1024 // The buffer size is 1024

int main() {
  // Define a buffer to hold the signal
  float buffer[BUFF_SIZE];
  float time = 0;
  float dt = 1.0 / SAMPLE_RATE;
  
  // Generate the signal
  for (int i = 0; i < BUFF_SIZE; i++) {
    buffer[i] = AMPLITUDE * sin(2 * M_PI * FREQUENCY * time);
    time += dt;
  }
  
  // Apply a low-pass filter to the signal
  float alpha = 0.1;
  float y_prev = 0;
  float y_curr;
  
  for (int i = 0; i < BUFF_SIZE; i++) {
    y_curr = alpha * buffer[i] + (1 - alpha) * y_prev;
    y_prev = y_curr;
    buffer[i] = y_curr;
  }
  
  // Print the output
  for (int i = 0; i < BUFF_SIZE; i++) {
    printf("%f ", buffer[i]);
  }
  
  return 0;
}