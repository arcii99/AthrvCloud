//FormAI DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>

#define SAMPLE_RATE 8000
#define BUFFER_SIZE 1024

void lowPassFilter(double* buffer, int len, int cutoffFreq) {
  double alpha = 2 * 3.14159265358979323846 * cutoffFreq / SAMPLE_RATE;
  double prev = buffer[0];
  for (int i = 1; i < len; i++) {
    double curr = buffer[i];
    buffer[i] = alpha * curr + (1 - alpha) * prev;
    prev = buffer[i];
  }
}

int main() {
  int cutoffFreq = 1000;
  double buffer[BUFFER_SIZE];
  
  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = 2.0 * i / BUFFER_SIZE - 1.0;
  }
  
  lowPassFilter(buffer, BUFFER_SIZE, cutoffFreq);
  
  for (int i = 0; i < BUFFER_SIZE; i++) {
    printf("%f ", buffer[i]);
  }
  
  return 0;
}