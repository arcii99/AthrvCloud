//FormAI DATASET v1.0 Category: Digital signal processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int signal[10] = {2,4,5,1,3,2,5,7,9,6};
  int processed_signal[10];
  int i;

  // Apply apocalyptic filter
  for(i=0; i<10; i++) {
    processed_signal[i] = signal[i] + (rand() % 10) - 5; // Add apocalyptic noise
    if(processed_signal[i] < 0) { // Avoid negative numbers
      processed_signal[i] = 0;
    }
    printf("Signal processed: %d\n", processed_signal[i]);
  }

  return 0;
}