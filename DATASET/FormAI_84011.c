//FormAI DATASET v1.0 Category: Data mining ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 5
#define MAX_COLS 3

int main() {
  int data[MAX_ROWS][MAX_COLS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12},
    {13, 14, 15}
  };

  int min_values[MAX_COLS];
  int max_values[MAX_COLS];

  // initialize the min and max values
  for (int i = 0; i < MAX_COLS; i++) {
    min_values[i] = data[0][i];
    max_values[i] = data[0][i];
  }

  // iterate through the data and update the min and max values
  for (int i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j < MAX_COLS; j++) {
      if (data[i][j] < min_values[j]) {
        min_values[j] = data[i][j];
      }
      if (data[i][j] > max_values[j]) {
        max_values[j] = data[i][j];
      }
    }
  }

  // output the results
  printf("Min values:\n");
  for (int i = 0; i < MAX_COLS; i++) {
    printf("%d ", min_values[i]);
  }
  printf("\nMax values:\n");
  for (int i = 0; i < MAX_COLS; i++) {
    printf("%d ", max_values[i]);
  }

  return 0;
}