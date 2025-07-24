//FormAI DATASET v1.0 Category: Data mining ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int data[10] = {23, 54, 12, 87, 36, 76, 11, 90, 67, 45};
  int min = data[0], max = data[0];
  float avg = 0, sum = 0;

  // Find min, max and sum of data
  for(int i = 0; i < 10; i++) {
    if(data[i] < min) {
      min = data[i];
    }
    if(data[i] > max) {
      max = data[i];
    }
    sum += data[i];
  }

  // Calculate average of data
  avg = sum / 10;

  // Print data info
  printf("Data mining results:\n");
  printf("Min: %d\n", min);
  printf("Max: %d\n", max);
  printf("Sum: %.2f\n", sum);
  printf("Average: %.2f\n", avg);

  return 0;
}