//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#define MAXCLUSTERS 50
#define MAXPOINTS 10000

struct Point {
  double x;
  double y;
};

struct Cluster {
  struct Point centroid;
  struct Point points[MAXPOINTS];
  int size;
};

struct Dataset {
  struct Point points[MAXPOINTS];
  int size;
};

struct Cluster clusters[MAXCLUSTERS];
int num_clusters;

double distance(struct Point p1, struct Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void assign_points_to_clusters(struct Dataset* dataset) {
  for (int i = 0; i < dataset->size; i++) {
    double min_distance = -1;
    int closest_cluster = -1;
    for (int j = 0; j < num_clusters; j++) {
      double d = distance(dataset->points[i], clusters[j].centroid);
      if (min_distance == -1 || d < min_distance) {
        min_distance = d;
        closest_cluster = j;
      }
    }
    clusters[closest_cluster].points[clusters[closest_cluster].size] = dataset->points[i];
    clusters[closest_cluster].size++;
  }
}

void update_centroids() {
  for (int i = 0; i < num_clusters; i++) {
    double x_avg = 0;
    double y_avg = 0;
    for (int j = 0; j < clusters[i].size; j++) {
      x_avg += clusters[i].points[j].x;
      y_avg += clusters[i].points[j].y;
    }
    clusters[i].centroid.x = x_avg / clusters[i].size;
    clusters[i].centroid.y = y_avg / clusters[i].size;
  }
}

void kmeans(struct Dataset* dataset) {
  // Initialize clusters randomly
  for (int i = 0; i < num_clusters; i++) {
    clusters[i].centroid = dataset->points[rand() % dataset->size];
    clusters[i].size = 0;
  }

  for (;;) {
    // Assign points to clusters
    for (int i = 0; i < num_clusters; i++) {
      clusters[i].size = 0;
    }
    assign_points_to_clusters(dataset);

    // Update centroids
    struct Point old_centroids[num_clusters];
    for (int i = 0; i < num_clusters; i++) {
      old_centroids[i] = clusters[i].centroid;
    }
    update_centroids();

    // Check for convergence
    int converged = 1;
    for (int i = 0; i < num_clusters; i++) {
      if (distance(old_centroids[i], clusters[i].centroid) > 0.0001) {
        converged = 0;
        break;
      }
    }
    if (converged) {
      break;
    }
  }
}

int main() {
  struct Dataset dataset = {
    .points = {
      {1, 2},
      {2, 1},
      {7, 8},
      {8, 7},
      {20, 30},
      {30, 20}
    },
    .size = 6
  };
  num_clusters = 2;
  kmeans(&dataset);
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d: centroid (%f, %f)\n", i, clusters[i].centroid.x, clusters[i].centroid.y);
    printf("Points: ");
    for (int j = 0; j < clusters[i].size; j++) {
      printf("(%f, %f) ", clusters[i].points[j].x, clusters[i].points[j].y);
    }
    printf("\n");
  }
  return 0;
}