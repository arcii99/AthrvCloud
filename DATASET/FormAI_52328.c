//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 10
#define MAX_ITERATIONS 100
#define THRESHOLD 0.05

typedef struct {
  float x, y;
} Point;

typedef struct {
  Point centroid;
  Point *points;
  int count;
} Cluster;

float euclidean_distance(Point p1, Point p2) {
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void assign_points_to_clusters(Point *points, Cluster *clusters, int num_clusters, int num_points) {
  for (int i = 0; i < num_points; i++) {
    float min_distance = INFINITY;
    int closest_cluster_index = 0;

    for (int j = 0; j < num_clusters; j++) {
      float distance = euclidean_distance(points[i], clusters[j].centroid);

      if (distance < min_distance) {
        min_distance = distance;
        closest_cluster_index = j;
      }
    }

    Cluster *closest_cluster = &(clusters[closest_cluster_index]);
    closest_cluster->points = (Point *) realloc(closest_cluster->points, (closest_cluster->count + 1) * sizeof(Point));
    closest_cluster->points[closest_cluster->count] = points[i];
    closest_cluster->count++;
  }
}

void calculate_cluster_centroids(Cluster *clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    float sum_x = 0, sum_y = 0;
    int count = clusters[i].count;

    for (int j = 0; j < count; j++) {
      sum_x += clusters[i].points[j].x;
      sum_y += clusters[i].points[j].y;
    }

    clusters[i].centroid.x = sum_x / count;
    clusters[i].centroid.y = sum_y / count;
  }
}

void print_clusters(Cluster *clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster #%d:\n  Centroid: (%f, %f)\n  Points: ", i + 1, clusters[i].centroid.x, clusters[i].centroid.y);

    for (int j = 0; j < clusters[i].count; j++) {
      printf("(%f, %f) ", clusters[i].points[j].x, clusters[i].points[j].y);
    }

    printf("\n");
  }
}

int main() {
  Point points[MAX_POINTS] = {{1, 1}, {1, 2}, {2, 2}, {5, 5}, {5, 6}, {6, 6}, {10, 10}, {10, 11}, {11, 11}, {15, 15}};
  int num_points = 10;
  int num_clusters = 2;

  Cluster clusters[num_clusters];
  clusters[0].centroid = points[0];
  clusters[1].centroid = points[5];

  for (int i = 0; i < num_clusters; i++) {
    clusters[i].points = NULL;
    clusters[i].count = 0;
  }

  assign_points_to_clusters(points, clusters, num_clusters, num_points);

  for (int i = 0; i < MAX_ITERATIONS; i++) {
    calculate_cluster_centroids(clusters, num_clusters);

    Cluster updated_clusters[num_clusters];

    for (int j = 0; j < num_clusters; j++) {
      updated_clusters[j].centroid = clusters[j].centroid;
      updated_clusters[j].points = NULL;
      updated_clusters[j].count = 0;
    }

    assign_points_to_clusters(points, updated_clusters, num_clusters, num_points);

    float total_difference = 0;

    for (int j = 0; j < num_clusters; j++) {
      total_difference += euclidean_distance(clusters[j].centroid, updated_clusters[j].centroid);
    }

    if (total_difference < THRESHOLD) {
      printf("Clusters have converged after %d iterations.\n", i + 1);
      print_clusters(updated_clusters, num_clusters);
      return 0;
    }

    for (int j = 0; j < num_clusters; j++) {
      free(clusters[j].points);
    }

    for (int j = 0; j < num_clusters; j++) {
      clusters[j].centroid = updated_clusters[j].centroid;
      clusters[j].points = updated_clusters[j].points;
      clusters[j].count = updated_clusters[j].count;
    }
  }

  printf("Clusters did not converge after %d iterations.\n", MAX_ITERATIONS);
  print_clusters(clusters, num_clusters);

  for (int i = 0; i < num_clusters; i++) {
    free(clusters[i].points);
  }

  return 0;
}