//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define CLUSTERS 5
#define DIMENSIONS 10
#define ITERATIONS 20

float dist(float *a, float *b, int dim) {
  float res = 0.0;
  for (int i = 0; i < dim; i++)
    res += pow(a[i] - b[i], 2);
  return sqrt(res);
}

int main() {
  srand(time(NULL));

  float data[CLUSTERS * DIMENSIONS], centroids[CLUSTERS * DIMENSIONS];
  for (int i = 0; i < CLUSTERS * DIMENSIONS; i++)
    data[i] = (float) rand() / RAND_MAX;

  printf("Welcome to the surreal C clustering algorithm implementation!\n\n");

  printf("Our data is composed of %d randomly generated points in a %d-dimensional space.\n", CLUSTERS, DIMENSIONS);
  printf("These points are represented by the following matrix:\n\n");
  for (int i = 0; i < CLUSTERS; i++) {
    for (int j = 0; j < DIMENSIONS; j++)
      printf("%.2f ", data[i * DIMENSIONS + j]);
    printf("\n");
  }
  printf("\n");

  printf("We will now randomly select %d centroids from the data points to start the clustering process.\n", CLUSTERS);
  int used[CLUSTERS] = {0};
  for (int i = 0; i < CLUSTERS; i++) {
    int index;
    do {
      index = rand() % CLUSTERS;
    } while (used[index]);
    used[index] = 1;
    for (int j = 0; j < DIMENSIONS; j++)
      centroids[i * DIMENSIONS + j] = data[index * DIMENSIONS + j];
  }
  printf("Our initial centroids are the following:\n\n");
  for (int i = 0; i < CLUSTERS; i++) {
    for (int j = 0; j < DIMENSIONS; j++)
      printf("%.2f ", centroids[i * DIMENSIONS + j]);
    printf("\n");
  }
  printf("\n");

  printf("We will now start the clustering process.\n");
  for (int iter = 0; iter < ITERATIONS; iter++) {
    float sum_distances = 0.0;
    for (int i = 0; i < CLUSTERS; i++) {
      float min_distance = INFINITY;
      int min_index = -1;
      for (int j = 0; j < CLUSTERS; j++) {
        float distance = dist(&data[j * DIMENSIONS], &centroids[i * DIMENSIONS], DIMENSIONS);
        if (distance < min_distance) {
          min_distance = distance;
          min_index = j;
        }
      }
      sum_distances += min_distance;
      for (int j = 0; j < DIMENSIONS; j++)
        centroids[i * DIMENSIONS + j] = data[min_index * DIMENSIONS + j];
    }
    printf("Iteration %d. Average distance to centroids: %.2f.\n", iter + 1, sum_distances / CLUSTERS);
  }
  printf("\n");

  printf("We have completed the clustering process.\n");
  printf("Our final centroids are the following:\n\n");
  for (int i = 0; i < CLUSTERS; i++) {
    for (int j = 0; j < DIMENSIONS; j++)
      printf("%.2f ", centroids[i * DIMENSIONS + j]);
    printf("\n");
  }
  printf("\n");

  printf("Thank you for participating in this surreal journey of clustering!\n");

  return 0;
}