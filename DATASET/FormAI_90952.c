//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 2 // number of clusters
#define N 10 // number of data points
#define MAX_ITER 100 // maximum number of iterations

// structure for storing data points
struct point {
  double x;
  double y;
};

// function to calculate distance between two points
double distance(struct point p, struct point q) {
  double dx = p.x - q.x;
  double dy = p.y - q.y;
  return sqrt(dx*dx + dy*dy);
}

int main() {
  // initialize data points
  struct point data[N] = {{1, 1}, {1.5, 2}, {3, 4}, {5, 7}, {3.5, 5}, {4.5, 5}, {3.5, 4.5}, {5, 5}, {4, 4}, {5, 5.5}};

  // randomly initialize centroids
  struct point centroids[K] = {{2, 2}, {4, 4}};

  // variables for storing cluster assignments and iteration count
  int cluster[N];
  int iter = 0;

  // repeat until convergence or maximum number of iterations
  while (iter < MAX_ITER) {
    // assign each data point to closest centroid
    for (int i = 0; i < N; i++) {
      double min_dist = INFINITY;
      int min_idx = 0;
      for (int j = 0; j < K; j++) {
        double dist = distance(data[i], centroids[j]);
        if (dist < min_dist) {
          min_dist = dist;
          min_idx = j;
        }
      }
      cluster[i] = min_idx;
    }

    // update centroids to be the mean of their assigned data points
    for (int j = 0; j < K; j++) {
      double sum_x = 0, sum_y = 0;
      int count = 0;
      for (int i = 0; i < N; i++) {
        if (cluster[i] == j) {
          sum_x += data[i].x;
          sum_y += data[i].y;
          count++;
        }
      }
      centroids[j].x = sum_x / count;
      centroids[j].y = sum_y / count;
    }

    // increment iteration count
    iter++;
  }

  // print final cluster assignments and centroids
  printf("Final cluster assignments:\n");
  for (int i = 0; i < N; i++) {
    printf("Data point %d: Cluster %d\n", i, cluster[i]);
  }

  printf("Final centroids:\n");
  for (int j = 0; j < K; j++) {
    printf("Centroid %d: (%f, %f)\n", j, centroids[j].x, centroids[j].y);
  }

  return 0;
}