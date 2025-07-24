//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Linus Torvalds
#include <stdio.h>

int main() {
  int signal[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  
  // Calculate the running sum
  for(int i = 1; i < 10; i++) {
    signal[i] += signal[i-1];
  }
  
  // Print the original signal and running sum
  printf("Original Signal: ");
  for(int i = 0; i < 10; i++) {
    printf("%d ", signal[i]-signal[i-1]);
  }
  
  printf("\nRunning Sum: ");
  for(int i = 0; i < 10; i++) {
    printf("%d ", signal[i]);
  }
  
  return 0;
}