//FormAI DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// A struct to hold data points
typedef struct dataPoint {
  float x;
  float y;
  char label[10];
} dataPoint;

// A function to calculate the distance between two data points
float distance(dataPoint dp1, dataPoint dp2) {
  float dx = dp1.x - dp2.x;
  float dy = dp1.y - dp2.y;
  return sqrt(dx*dx + dy*dy);
}

int main() {
  // Create an array of data points
  dataPoint data[] = {
    {1, 2, "A"},
    {2, 3, "B"},
    {3, 1, "C"},
    {4, 4, "D"},
    {5, 2, "E"},
    {6, 5, "F"}
  };

  // Determine the number of data points
  int n = sizeof(data) / sizeof(data[0]);

  // Create a distance matrix
  float distances[n][n];

  // Calculate the distances and store them in the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      float dist = distance(data[i], data[j]);
      distances[i][j] = dist;
    }
  }

  // Print the distance matrix
  printf("Distance Matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%0.2f ", distances[i][j]);
    }
    printf("\n");
  }

  return 0;
}