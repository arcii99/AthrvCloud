//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Set number of data points and dimensions
#define N_DATA_POINTS 1000
#define N_DIMENSIONS 5

// Set number of clusters to generate
#define N_CLUSTERS 3

// Define data struct for each data point
typedef struct {
  float coords[N_DIMENSIONS];
  int cluster_label;
} data_point_t;

// Define data struct for each cluster
typedef struct {
  float centroid[N_DIMENSIONS];
  int num_points;
} cluster_t;

// Define function to calculate Euclidean distance between two points
float euclidean_distance(float *a, float *b) {
  float distance = 0.0;
  for (int i = 0; i < N_DIMENSIONS; i++) {
    distance += pow((a[i] - b[i]), 2);
  }
  return sqrt(distance);
}

int main() {
  // Generate random data points between 0 and 1 for each dimension
  data_point_t data_points[N_DATA_POINTS];
  for (int i = 0; i < N_DATA_POINTS; i++) {
    for (int j = 0; j < N_DIMENSIONS; j++) {
      data_points[i].coords[j] = (float) rand() / RAND_MAX;
    }
    data_points[i].cluster_label = -1;
  }

  // Randomly initialize N_CLUSTERS centroids
  cluster_t clusters[N_CLUSTERS];
  for (int i = 0; i < N_CLUSTERS; i++) {
    for (int j = 0; j < N_DIMENSIONS; j++) {
      clusters[i].centroid[j] = (float) rand() / RAND_MAX;
    }
    clusters[i].num_points = 0;
  }

  // Loop through data points and assign to nearest cluster
  float min_distance, distance;
  int nearest_cluster;
  for (int i = 0; i < N_DATA_POINTS; i++) {
    min_distance = INFINITY;
    for (int j = 0; j < N_CLUSTERS; j++) {
      distance = euclidean_distance(data_points[i].coords, clusters[j].centroid);
      if (distance < min_distance) {
        min_distance = distance;
        nearest_cluster = j;
      }
    }
    data_points[i].cluster_label = nearest_cluster;
    clusters[nearest_cluster].num_points++;
    for (int j = 0; j < N_DIMENSIONS; j++) {
      clusters[nearest_cluster].centroid[j] += data_points[i].coords[j];
    }
  }

  // Update centroids by taking mean of all data points assigned to cluster
  for (int i = 0; i < N_CLUSTERS; i++) {
    for (int j = 0; j < N_DIMENSIONS; j++) {
      clusters[i].centroid[j] /= clusters[i].num_points;
    }
  }

  // Print out results
  printf("Cluster labels: ");
  for (int i = 0; i < N_DATA_POINTS; i++) {
    printf("%d ", data_points[i].cluster_label);
  }
  printf("\n");

  printf("Cluster centroids:\n");
  for (int i = 0; i < N_CLUSTERS; i++) {
    printf("Cluster %d: (", i);
    for (int j = 0; j < N_DIMENSIONS; j++) {
      printf("%f", clusters[i].centroid[j]);
      if (j < N_DIMENSIONS - 1) {
        printf(", ");
      }
    }
    printf(")\n");
  }
  
  return 0;
}