//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>

// Function to compute the checksum
int computeChecksum(int arr[], int n) {
  int sum = 0;
  
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  
  // Compute one's complement of sum
  sum = ~sum;
  
  return sum;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  // Show the input array
  printf("Input array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  // Compute checksum
  int checksum = computeChecksum(arr, n);
  
  // Show the computed checksum
  printf("Checksum: %d\n", checksum);
  
  return 0;
}