//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100 // total number of data points
#define NUM_CLUSTERS 5 // total number of clusters

struct point {
  double x;
  double y;
} data[NUM_POINTS];

// Initialize the data points
void init_points() {
  for (int i = 0; i < NUM_POINTS; i++) {
    data[i].x = (double) rand() / (RAND_MAX);
    data[i].y = (double) rand() / (RAND_MAX);
  }
}

// Calculate the distance between two points
double dist(struct point p1, struct point p2) {
  return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

// Perform K-means clustering
void k_means() {
  struct point centroids[NUM_CLUSTERS];
  int cluster_labels[NUM_POINTS];

  // Initialize the centroids to random points
  for (int i = 0; i < NUM_CLUSTERS; i++) {
    centroids[i].x = (double) rand() / (RAND_MAX);
    centroids[i].y = (double) rand() / (RAND_MAX);
  }

  // Repeat until convergence
  while (1) {
    // Assign each data point to closest cluster
    int changed = 0;
    for (int i = 0; i < NUM_POINTS; i++) {
      double min_dist = INFINITY;
      int label;
      for (int j = 0; j < NUM_CLUSTERS; j++) {
        double d = dist(data[i], centroids[j]);
        if (d < min_dist) {
          min_dist = d;
          label = j;
        }
      }
      if (label != cluster_labels[i]) {
        cluster_labels[i] = label;
        changed = 1;
      }
    }
    if (!changed) break;

    // Update the centroid of each cluster
    for (int i = 0; i < NUM_CLUSTERS; i++) {
      double sum_x = 0, sum_y = 0;
      int count = 0;
      for (int j = 0; j < NUM_POINTS; j++) {
        if (cluster_labels[j] == i) {
          sum_x += data[j].x;
          sum_y += data[j].y;
          count++;
        }
      }
      centroids[i].x = sum_x / count;
      centroids[i].y = sum_y / count;
    }
  }
}

int main() {
  srand(0);
  init_points();
  k_means();
  return 0;
}