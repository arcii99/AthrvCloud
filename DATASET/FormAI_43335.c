//FormAI DATASET v1.0 Category: Digital signal processing ; Style: immersive
#include <stdio.h>

int main() {
  int signal[10] = {1, 3, 5, 4, 6, 2, 7, 9, 8, 10};
  int filtered_signal[8];

  // Applying a moving average filter
  for (int i = 0; i < 8; i++) {
    filtered_signal[i] = (signal[i] + signal[i+1] + signal[i+2])/3;
  }

  // Printing the original signal and the filtered signal
  printf("Original signal: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", signal[i]);
  }

  printf("\nFiltered signal: ");
  for (int i = 0; i < 8; i++) {
    printf("%d ", filtered_signal[i]);
  }

  return 0;
}