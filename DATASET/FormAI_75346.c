//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POPULATION_SIZE 1000
#define CLUSTER_COUNT 3
#define MAX_ITERATIONS 100
#define MUTATION_RATE 0.01

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  Point centroid;
  int point_count;
  Point *points;
} Cluster;

int rand_range(int min, int max) {
  return rand() % (max - min) + min;
}

double euclidean_distance(Point *p1, Point *p2) {
  double dx = p2->x - p1->x;
  double dy = p2->y - p1->y;

  return sqrt(dx*dx + dy*dy);
}

void assign_points_to_clusters(Point *points, Cluster *clusters, int population_size) {
  // Clear all point counts
  for(int i = 0; i < CLUSTER_COUNT; i++) {
    clusters[i].point_count = 0;
  }

  // Assign each point to the nearest cluster
  for(int i = 0; i < population_size; i++) {
    double min_distance = INFINITY;
    int closest_cluster_index = 0;

    for(int j = 0; j < CLUSTER_COUNT; j++) {
      double distance = euclidean_distance(&points[i], &clusters[j].centroid);

      if(distance < min_distance) {
        min_distance = distance;
        closest_cluster_index = j;
      }
    }

    clusters[closest_cluster_index].points[clusters[closest_cluster_index].point_count++] = points[i];
  }
}

void reposition_cluster_centroids(Cluster *clusters) {
  for(int i = 0; i < CLUSTER_COUNT; i++) {
    Point *points = clusters[i].points;

    if(clusters[i].point_count > 0) {
      double sum_x = 0.;
      double sum_y = 0.;

      for(int j = 0; j < clusters[i].point_count; j++) {
        sum_x += points[j].x;
        sum_y += points[j].y;
      }

      clusters[i].centroid.x = sum_x / clusters[i].point_count;
      clusters[i].centroid.y = sum_y / clusters[i].point_count;
    }
  }
}

void print_clusters(Cluster *clusters) {
  for(int i = 0; i < CLUSTER_COUNT; i++) {
    printf("Cluster %d:\n", i+1);

    for(int j = 0; j < clusters[i].point_count; j++) {
      printf("  (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
    }

    printf("\n");
  }
}

void mutate_cluster_centroids(Cluster *clusters) {
  for(int i = 0; i < CLUSTER_COUNT; i++) {
    if(rand() * 1./RAND_MAX < MUTATION_RATE) {
      clusters[i].centroid.x = rand_range(1, 100);
      clusters[i].centroid.y = rand_range(1, 100);
    }
  }
}

int main() {
  Point points[POPULATION_SIZE];

  // Initialize points randomly
  for(int i = 0; i < POPULATION_SIZE; i++) {
    points[i].x = rand_range(1, 100);
    points[i].y = rand_range(1, 100);
  }

  // Initialize clusters randomly
  Cluster clusters[CLUSTER_COUNT];

  for(int i = 0; i < CLUSTER_COUNT; i++) {
    clusters[i].centroid.x = rand_range(1, 100);
    clusters[i].centroid.y = rand_range(1, 100);
    clusters[i].points = (Point*)malloc(sizeof(Point*) * POPULATION_SIZE);
  }

  // Run clustering algorithm
  for(int i = 0; i < MAX_ITERATIONS; i++) {
    assign_points_to_clusters(points, clusters, POPULATION_SIZE);
    reposition_cluster_centroids(clusters);
    mutate_cluster_centroids(clusters);
  }

  print_clusters(clusters);

  // Clean up memory
  for(int i = 0; i < CLUSTER_COUNT; i++) {
    free(clusters[i].points);
  }

  return 0;
}