//FormAI DATASET v1.0 Category: Data mining ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 3

void printArray(double arr[][COLS], int rows){
  printf("Array:\n");
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < COLS; j++){
      printf("%.2lf ", arr[i][j]);
    }
    printf("\n");
  }
}

int main(){
  double data[ROWS][COLS] = {
    {1.2, 3.5, 4.0},
    {2.1, 2.7, 3.3},
    {5.3, 4.9, 6.2},
    {3.8, 1.5, 2.4},
    {2.2, 4.1, 5.8}
  };
  
  printArray(data, ROWS);

  // Calculate the mean of each column
  double means[COLS] = {0.0};
  for(int j = 0; j < COLS; j++){
    for(int i = 0; i < ROWS; i++){
      means[j] += data[i][j];
    }
    means[j] /= ROWS;
  }
  printf("Column means:\n");
  for(int j = 0; j < COLS; j++){
    printf("Column %d: %.2lf\n", j, means[j]);
  }
  
  // Calculate the standard deviation of each column
  double stdev[COLS] = {0.0};
  for(int j = 0; j < COLS; j++){
    for(int i = 0; i < ROWS; i++){
      stdev[j] += (data[i][j] - means[j]) * (data[i][j] - means[j]);
    }
    stdev[j] = sqrt(stdev[j] / ROWS);
  }
  printf("Column standard deviations:\n");
  for(int j = 0; j < COLS; j++){
    printf("Column %d: %.2lf\n", j, stdev[j]);
  }
  
  // Find the maximum value in each row
  double max[ROWS] = {0.0};
  for(int i = 0; i < ROWS; i++){
    max[i] = data[i][0];
    for(int j = 1; j < COLS; j++){
      if(data[i][j] > max[i]){
        max[i] = data[i][j];
      }
    }
  }
  printf("Maximum values in each row:\n");
  for(int i = 0; i < ROWS; i++){
    printf("Row %d: %.2lf\n", i, max[i]);
  }
  
  return 0;
}