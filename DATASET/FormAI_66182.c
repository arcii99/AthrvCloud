//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 3

int main() {
  int dataset[NUM_ROWS][NUM_COLS] = {{1, 2, 6},
                                      {3, 4, 9},
                                      {5, 6, 7},
                                      {1, 2, 3},
                                      {4, 5, 6}};
  
  int min_value = dataset[0][0];
  int max_value = dataset[0][0];
  int sum = 0;
  float avg = 0.0;
  
  // find minimum, maximum, and calculate sum
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      if (dataset[i][j] < min_value) {
        min_value = dataset[i][j];
      }
      if (dataset[i][j] > max_value) {
        max_value = dataset[i][j];
      }
      sum += dataset[i][j];
    }
  }
  
  // calculate average
  avg = (float)sum / (NUM_ROWS * NUM_COLS);
  
  // print results
  printf("Minimum Value: %d\n", min_value);
  printf("Maximum Value: %d\n", max_value);
  printf("Sum: %d\n", sum);
  printf("Average Value: %f\n", avg);
  
  return 0;
}