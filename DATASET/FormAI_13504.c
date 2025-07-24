//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>

int main(void) {
  // Initialize array of data
  int data[] = {3, 6, 4, 1, 9, 5, 10, 2};
  
  // Calculate the average
  int sum = 0;
  float avg;
  for(int i = 0; i < 8; i++) {
    sum += data[i];
  }
  avg = sum / 8.0;
  
  // Find the maximum value in the data array
  int max = data[0];
  for(int i = 1; i < 8; i++) {
    if(data[i] > max) {
      max = data[i];
    }
  }
  
  // Find the minimum value in the data array
  int min = data[0];
  for(int i = 1; i < 8; i++) {
    if(data[i] < min) {
      min = data[i];
    }
  }
  
  // Print out the results
  printf("Data: ");
  for(int i = 0; i < 8; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
  printf("Average: %.2f\n", avg);
  printf("Max: %d\n", max);
  printf("Min: %d\n", min);
  
  return 0;
}