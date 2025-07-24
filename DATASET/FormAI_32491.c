//FormAI DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input data
  int data[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int data_length = sizeof(data) / sizeof(data[0]);

  // Calculate median
  int median_index = data_length / 2;
  int median;
  
  if (data_length % 2 == 0) {
    // If data length is even
    median = (data[median_index - 1] + data[median_index]) / 2;
  } else {
    // If data length is odd
    median = data[median_index];
  }

  // Output result
  printf("Data: ");
  for (int i = 0; i < data_length; i++) {
    printf("%d ", data[i]);
  }
  printf("\nMedian: %d", median);

  return 0;
}