//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100
#define NUM_CLUSTERS 3
#define MAX_ITERATIONS 500

typedef struct point {
  double x, y;
  int cluster;
} point_t;

double euclidean_distance(point_t p1, point_t p2) {
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void find_closest_cluster(point_t* point, point_t* clusters) {
  double min_distance = 100000;
  for (int i = 0; i < NUM_CLUSTERS; i++) {
    double distance = euclidean_distance(*point, clusters[i]);
    if (distance < min_distance) {
      min_distance = distance;
      point->cluster = i;
    }
  }
}

void update_cluster_centers(point_t* points, point_t* clusters) {
  int counts[NUM_CLUSTERS] = {0};
  double sum_x[NUM_CLUSTERS] = {0};
  double sum_y[NUM_CLUSTERS] = {0};

  for (int i = 0; i < NUM_POINTS; i++) {
    counts[points[i].cluster]++;
    sum_x[points[i].cluster] += points[i].x;
    sum_y[points[i].cluster] += points[i].y;
  }

  for (int i = 0; i < NUM_CLUSTERS; i++) {
    clusters[i].x = sum_x[i] / counts[i];
    clusters[i].y = sum_y[i] / counts[i];
  }
}

int main(void) {
  point_t points[NUM_POINTS];
  point_t clusters[NUM_CLUSTERS];

  // Initialize points with random x and y values
  for (int i = 0; i < NUM_POINTS; i++) {
    points[i].x = (double)rand() / (double)RAND_MAX;
    points[i].y = (double)rand() / (double)RAND_MAX;
  }

  // Initialize cluster centers with random x and y values
  for (int i = 0; i < NUM_CLUSTERS; i++) {
    clusters[i].x = (double)rand() / (double)RAND_MAX;
    clusters[i].y = (double)rand() / (double)RAND_MAX;
  }

  // Run clustering algorithm
  int iterations = 0;
  while (iterations < MAX_ITERATIONS) {
    // Assign each point to the closest cluster
    for (int i = 0; i < NUM_POINTS; i++) {
      find_closest_cluster(&points[i], clusters);
    }

    // Update cluster centers
    update_cluster_centers(points, clusters);

    iterations++;
  }

  // Print results
  printf("Final clusters:\n");
  for (int i = 0; i < NUM_CLUSTERS; i++) {
    printf("Cluster %d: (%f, %f)\n", i, clusters[i].x, clusters[i].y);
  }

  return 0;
}