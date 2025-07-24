//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // number of clusters
#define N 10 // number of data points
#define MAX_ITERS 100 // maximum number of iterations

typedef struct {
  double x; // x-coordinate
  double y; // y-coordinate
  int cluster; // cluster number (0 to K-1)
} Point;

double distance(Point p1, Point p2) {
  // calculates the Euclidean distance between two points
  return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

int main() {
  // initialize data points randomly within a 10x10 grid
  Point data[N];
  for (int i = 0; i < N; i++) {
    data[i].x = (double) rand()/RAND_MAX * 10.0;
    data[i].y = (double) rand()/RAND_MAX * 10.0;
    data[i].cluster = -1; // not assigned to any cluster yet
  }

  // initialize centroids randomly within the same grid
  Point centroids[K];
  for (int i = 0; i < K; i++) {
    centroids[i].x = (double) rand()/RAND_MAX * 10.0;
    centroids[i].y = (double) rand()/RAND_MAX * 10.0;
    centroids[i].cluster = i;
  }

  // run k-means clustering algorithm
  int num_iters = 0;
  while (num_iters < MAX_ITERS) {
    // assign data points to nearest cluster centroid
    for (int i = 0; i < N; i++) {
      double min_distance = INFINITY;
      for (int j = 0; j < K; j++) {
        double d = distance(data[i], centroids[j]);
        if (d < min_distance) {
          min_distance = d;
          data[i].cluster = j;
        }
      }
    }

    // recalculate cluster centroids
    int count[K] = {0}; // number of data points in each cluster
    for (int i = 0; i < K; i++) {
      centroids[i].x = 0.0;
      centroids[i].y = 0.0;
    }
    for (int i = 0; i < N; i++) {
      int c = data[i].cluster;
      centroids[c].x += data[i].x;
      centroids[c].y += data[i].y;
      count[c]++;
    }
    for (int i = 0; i < K; i++) {
      if (count[i] > 0) {
        centroids[i].x /= count[i];
        centroids[i].y /= count[i];
      }
    }

    // check if cluster assignments have converged
    int converged = 1;
    for (int i = 0; i < N; i++) {
      if (data[i].cluster != data[i-1].cluster) {
        converged = 0;
        break;
      }
    }
    if (converged) break;

    num_iters++;
  }

  // print final cluster assignments
  printf("Final cluster assignments:\n");
  for (int i = 0; i < N; i++) {
    printf("(%f, %f) belongs to cluster %d\n", data[i].x, data[i].y, data[i].cluster);
  }

  return 0;
}