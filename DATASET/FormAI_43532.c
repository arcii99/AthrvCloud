//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define CLUSTER_SIZE 10
#define THRESHOLD 0.02

typedef struct {
  double x, y;
} point_t;

void print_clusters(point_t *points, int *clusters, int num_clusters) {
  printf("\nPoints and their clusters:\n");
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i);
    for (int j = 0; j < CLUSTER_SIZE; j++) {
      printf("(%f, %f)\n", points[i*CLUSTER_SIZE+j].x, points[i*CLUSTER_SIZE+j].y);
    }
    printf("\n");
  }
}

double distance(point_t p1, point_t p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx*dx + dy*dy);
}

void init_clusters(point_t *points, int *clusters, int num_clusters) {
  for (int i = 0; i < num_clusters*CLUSTER_SIZE; i++) {
    clusters[i] = i / CLUSTER_SIZE;
  }
}

int main() {
  point_t points[MAX_POINTS];
  int clusters[MAX_POINTS] = {0};

  srand(1);
  for (int i = 0; i < MAX_POINTS; i++) {
    points[i].x = (double)rand()/(double)RAND_MAX;
    points[i].y = (double)rand()/(double)RAND_MAX;
  }

  int num_clusters = MAX_POINTS/CLUSTER_SIZE;
  init_clusters(points, clusters, num_clusters);

  double total_dist = 0.0;
  double prev_total_dist = INFINITY;
  int iter = 0;
  while (fabs(prev_total_dist - total_dist) > THRESHOLD) {
    prev_total_dist = total_dist;
    total_dist = 0.0;
    int cluster_centers[num_clusters];
    for (int i = 0; i < num_clusters; i++) {
      cluster_centers[i] = i*CLUSTER_SIZE + rand()%CLUSTER_SIZE;
    }
    for (int i = 0; i < MAX_POINTS; i++) {
      int closest_center = -1;
      double closest_dist = INFINITY;
      for (int j = 0; j < num_clusters; j++) {
        point_t center = points[cluster_centers[j]];
        double dist = distance(center, points[i]);
        if (dist < closest_dist) {
          closest_dist = dist;
          closest_center = j;
        }
      }
      clusters[i] = closest_center;
      total_dist += closest_dist;
    }
    printf("Iteration %d: Total distance = %f\n", iter, total_dist);
    iter++;
  }
  print_clusters(points, clusters, num_clusters);

  return 0;
}