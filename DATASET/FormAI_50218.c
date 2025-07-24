//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Point {
  double x;
  double y;
} Point;

typedef struct Cluster {
  Point centroid;
  int size;
  Point *points;
} Cluster;

double euclidean_distance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

Point find_avg_point(Cluster cluster) {
  double total_x = 0, total_y = 0;
  for (int i = 0; i < cluster.size; i++) {
    total_x += cluster.points[i].x;
    total_y += cluster.points[i].y;
  }
  Point avg_point = {total_x / cluster.size, total_y / cluster.size};
  return avg_point;
}

void k_means(Cluster *clusters, int num_clusters, Point *points, int num_points) {
  // Initialize centroids
  for (int i = 0; i < num_clusters; i++) {
    clusters[i].centroid = points[i];
  }

  // Assign points to clusters
  for (int i = 0; i < num_points; i++) {
    double min_distance = INFINITY;
    int cluster_index = 0;
    for (int j = 0; j < num_clusters; j++) {
      double distance = euclidean_distance(points[i], clusters[j].centroid);
      if (distance < min_distance) {
        min_distance = distance;
        cluster_index = j;
      }
    }
    clusters[cluster_index].size++;
    clusters[cluster_index].points = realloc(
        clusters[cluster_index].points, clusters[cluster_index].size * sizeof(Point));
    clusters[cluster_index].points[clusters[cluster_index].size - 1] = points[i];
  }

  // Update centroids
  for (int i = 0; i < num_clusters; i++) {
    clusters[i].centroid = find_avg_point(clusters[i]);
  }
}

int main() {
  Point points[10] = {{2, 10}, {2, 5}, {8, 4}, {5, 8}, {7, 5}, {6, 4}, {1, 2}, {4, 9}, {7, 1}, {6, 3}};
  Cluster clusters[2] = {{.centroid = {2, 10}}, {.centroid = {5, 8}}};
  k_means(clusters, 2, points, 10);

  for (int i = 0; i < 2; i++) {
    printf("Cluster %d:\n", i + 1);
    printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
    printf("Points: ");
    for (int j = 0; j < clusters[i].size; j++) {
      printf("(%f, %f) ", clusters[i].points[j].x, clusters[i].points[j].y);
    }
    printf("\n");
  }

  return 0;
}