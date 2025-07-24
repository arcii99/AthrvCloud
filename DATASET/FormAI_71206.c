//FormAI DATASET v1.0 Category: Data mining ; Style: complete
#include <stdio.h>

int main() {
  int N = 10;
  int data[N]; // array to store the data
  int max = 0; // variable to store maximum value
  int min = 0; // variable to store minimum value
  float avg = 0; // variable to store average value

  // Read data from the user
  printf("Enter %d integers:\n", N);
  for(int i=0; i<N; i++) {
    scanf("%d", &data[i]);

    // Update the maximum value
    if(data[i] > max) {
      max = data[i];
    }

    // Update the minimum value
    if(i == 0 || data[i] < min) {
      min = data[i];
    }

    // Calculate running average
    avg += (data[i] - avg) / (i+1);
  }

  // Print maximum, minimum and average values
  printf("\nMaximum value: %d\n", max);
  printf("Minimum value: %d\n", min);
  printf("Average value: %.2f\n", avg);

  return 0;
}