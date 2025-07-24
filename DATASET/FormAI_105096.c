//FormAI DATASET v1.0 Category: Data mining ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define constants for the array sizes
#define ROWS 3
#define COLS 4

int main() {
  // Declare our 2D array of data
  int data[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };
  
  // Print out the original data array for comparison
  printf("Original data array:\n");
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printf("%d ", data[i][j]);
    }
    printf("\n");
  }
  
  // Calculate the mean of each column
  double mean[COLS];
  for(int i = 0; i < COLS; i++) {
    double sum = 0;
    for(int j = 0; j < ROWS; j++) {
      sum += data[j][i];
    }
    mean[i] = sum / ROWS;
  }
  
  // Print out the mean values for each column
  printf("\nMean values for each column:\n");
  for(int i = 0; i < COLS; i++) {
    printf("%.2lf ", mean[i]);
  }
  
  // Normalize the data by subtracting the mean from each element
  printf("\n\nNormalized data array:\n");
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      data[i][j] -= mean[j];
      printf("%d ", data[i][j]);
    }
    printf("\n");
  }
  
  // Calculate the magnitude of each row
  double mag[ROWS];
  for(int i = 0; i < ROWS; i++) {
    double sum = 0;
    for(int j = 0; j < COLS; j++) {
      sum += data[i][j] * data[i][j];
    }
    mag[i] = sqrt(sum);
  }
  
  // Print out the magnitude values for each row
  printf("\nMagnitude values for each row:\n");
  for(int i = 0; i < ROWS; i++) {
    printf("%.2lf ", mag[i]);
  }
  
  return 0;
}