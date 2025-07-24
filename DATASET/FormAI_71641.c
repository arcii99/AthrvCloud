//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CLUSTER_COUNT 3

typedef struct {
  int x;
  int y;
  int cluster_id;
} point;

point random_point();
void kmeans_clustering(point* points, int point_count, point* centroids, int cluster_count);
int update_clusters(point* points, int point_count, point* centroids, int cluster_count);
void update_centroids(point* points, int point_count, point* centroids, int cluster_count);

int main() {
  srand(time(NULL));

  const int POINT_COUNT = 100;
  point points[POINT_COUNT];
  for (int i = 0; i < POINT_COUNT; i++) {
    points[i] = random_point();
  }

  point centroids[CLUSTER_COUNT];
  for (int i = 0; i < CLUSTER_COUNT; i++) {
    centroids[i] = random_point();
  }

  kmeans_clustering(points, POINT_COUNT, centroids, CLUSTER_COUNT);
}

point random_point() {
  point p;
  p.x = rand() % 100;
  p.y = rand() % 100;
  p.cluster_id = -1;
  return p;
}

void kmeans_clustering(point* points, int point_count, point* centroids, int cluster_count) {
  int iterations = 0;
  while (update_clusters(points, point_count, centroids, cluster_count)) {
    update_centroids(points, point_count, centroids, cluster_count);
    iterations++;
  }

  printf("K Means Clustering Complete\n");
  printf("Iterations: %d\n", iterations);
}

int calculate_distance(point p, point c) {
  return ((p.x - c.x) * (p.x - c.x)) + ((p.y - c.y) * (p.y - c.y));
}

int update_clusters(point* points, int point_count, point* centroids, int cluster_count) {
  int updated = 0;

  for (int i = 0; i < point_count; i++) {
    point p = points[i];

    int min_distance = -1;
    int min_cluster_id = -1;

    for (int j = 0; j < cluster_count; j++) {
      point c = centroids[j];

      int distance = calculate_distance(p, c);

      if (min_distance == -1 || distance < min_distance) {
        min_distance = distance;
        min_cluster_id = j;
      }
    }

    if (p.cluster_id != min_cluster_id) {
      p.cluster_id = min_cluster_id;
      points[i] = p;
      updated = 1;
    }
  }

  return updated;
}

void update_centroids(point* points, int point_count, point* centroids, int cluster_count) {
  int cluster_sizes[cluster_count];
  for (int i = 0; i < cluster_count; i++) {
    cluster_sizes[i] = 0;
    centroids[i].x = 0;
    centroids[i].y = 0;
  }

  for (int i = 0; i < point_count; i++) {
    point p = points[i];
    int cluster_id = p.cluster_id;

    centroids[cluster_id].x += p.x;
    centroids[cluster_id].y += p.y;
    cluster_sizes[cluster_id]++;
  }

  for (int i = 0; i < cluster_count; i++) {
    if (cluster_sizes[i] != 0) {
      centroids[i].x /= cluster_sizes[i];
      centroids[i].y /= cluster_sizes[i];
    }
  }
}