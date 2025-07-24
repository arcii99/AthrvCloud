//FormAI DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define DIM 2
#define K 2

float data[][DIM] = {{1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}, {10.0, 10.0}, {11.0, 11.0}, {12.0, 12.0}};

int cluster_of_instance(float instance[], float centroids[][DIM]) {
  float dist[K];
  for (int i = 0; i < K; i++) {
    float sum = 0.0;
    for (int j = 0; j < DIM; j++) {
      sum += (instance[j] - centroids[i][j]) * (instance[j] - centroids[i][j]);
    }
    dist[i] = sqrt(sum);
  }
  int min_dist_idx = 0;
  float min_dist = dist[0];
  for (int i = 1; i < K; i++) {
    if (dist[i] < min_dist) {
      min_dist = dist[i];
      min_dist_idx = i;
    }
  }
  return min_dist_idx;
}

void compute_centroids(float centroids[][DIM], int clusters[]) {
  int count[K] = { 0 };
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < DIM; j++) {
      centroids[i][j] = 0.0;
    }
  }
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    int c = clusters[i];
    for (int j = 0; j < DIM; j++) {
      centroids[c][j] += data[i][j];
    }
    count[c]++;
  }
  for (int i = 0; i < K; i++) {
    if (count[i] != 0) {
      for (int j = 0; j < DIM; j++) {
        centroids[i][j] /= count[i];
      }
    }
  }
}

int main() {
  float centroids[K][DIM];
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < DIM; j++) {
      centroids[i][j] = data[i][j];
    }
  }
  int clusters[sizeof(data) / sizeof(data[0])] = { 0 };
  bool should_stop = false;
  int iter = 0;
  while (!should_stop) {
    iter++;
    int new_clusters[sizeof(data) / sizeof(data[0])];
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
      new_clusters[i] = cluster_of_instance(data[i], centroids);
    }
    should_stop = true;
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
      if (new_clusters[i] != clusters[i]) {
        should_stop = false;
        for (int j = 0; j < sizeof(data[0]) / sizeof(float); j++) {
          clusters[i] = new_clusters[i];
        }
      }
    }
    compute_centroids(centroids, clusters);
  }
  printf("After %d iterations, the clusters are:\n", iter);
  for (int i = 0; i < K; i++) {
    printf("Cluster %d:\n", i);
    for (int j = 0; j < sizeof(data) / sizeof(data[0]); j++) {
      if (clusters[j] == i) {
        printf("(%f, %f)\n", data[j][0], data[j][1]);
      }
    }
  }
  return 0;
}