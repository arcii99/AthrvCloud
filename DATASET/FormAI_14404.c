//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 4

int main() {
  // Define a matrix with random integers between 0 and 9
  int data[NUM_ROWS][NUM_COLS] = {
    {8, 0, 6, 3},
    {1, 2, 7, 4},
    {9, 5, 0, 8},
    {6, 1, 7, 2},
    {3, 9, 4, 5}
  };

  // Calculate the average of each column
  float averages[NUM_COLS] = {0};
  for (int j = 0; j < NUM_COLS; j++) {
    float sum = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
      sum += data[i][j];
    }
    averages[j] = sum / NUM_ROWS;
  }

  // Print out the original data matrix and the column averages
  printf("Original data:\n");
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%d ", data[i][j]);
    }
    printf("\n");
  }

  printf("\nColumn averages:\n");
  for (int j = 0; j < NUM_COLS; j++) {
    printf("%.2f ", averages[j]);
  }
  printf("\n");

  // Find the row with the highest sum
  int max_sum_row = 0;
  int max_sum = 0;
  for (int i = 0; i < NUM_ROWS; i++) {
    int row_sum = 0;
    for (int j = 0; j < NUM_COLS; j++) {
      row_sum += data[i][j];
    }
    if (row_sum > max_sum) {
      max_sum = row_sum;
      max_sum_row = i;
    }
  }

  printf("\nRow with highest sum:\n");
  for (int j = 0; j < NUM_COLS; j++) {
    printf("%d ", data[max_sum_row][j]);
  }
  printf("\n");

  return 0;
}