//FormAI DATASET v1.0 Category: Data mining ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  printf("Welcome to the Data Mining Program!\n");

  // Create data set
  int data[10][2] = {{1, 5},
                     {2, 9},
                     {3, 14},
                     {4, 20},
                     {5, 26},
                     {6, 33},
                     {7, 40},
                     {8, 47},
                     {9, 55},
                     {10, 63}};

  // Calculate mean of X and Y data
  float sum_x = 0;
  float sum_y = 0;
  for (int i = 0; i < 10; i++) {
    sum_x += data[i][0];
    sum_y += data[i][1];
  }
  float mean_x = sum_x / 10;
  float mean_y = sum_y / 10;
    
  // Calculate slope and y-intercept of linear regression line
  float numerator_sum = 0;
  float denominator_sum = 0;
  for (int i = 0; i < 10; i++) {
    numerator_sum += (data[i][0] - mean_x) * (data[i][1] - mean_y);
    denominator_sum += pow((data[i][0] - mean_x), 2);
  }
  float slope = numerator_sum / denominator_sum;
  float y_intercept = mean_y - slope * mean_x;

  // Display results
  printf("The linear regression line of the data set is: y = %.2fx + %.2f\n", slope, y_intercept);

  return 0;
}