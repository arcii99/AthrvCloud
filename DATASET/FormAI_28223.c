//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define DIMENSION 5
#define K 3

// structure to represent a data point
typedef struct {
  double values[DIMENSION];
  int cluster_id;
} data_point;

// function to generate random data points
void generate_data_points(data_point *data_points, int num_points) {
  srand(time(NULL));
  for (int i = 0; i < num_points; i++) {
    for (int j = 0; j < DIMENSION; j++) {
      data_points[i].values[j] = ((double)rand() / RAND_MAX) * 10.0;
    }
    data_points[i].cluster_id = -1;
  }
}

// function to calculate Euclidean distance between two data points
double euclidean_distance(data_point data_point1, data_point data_point2) {
  double sum = 0.0;
  for (int i = 0; i < DIMENSION; i++) {
    sum += pow(data_point1.values[i] - data_point2.values[i], 2.0);
  }
  return sqrt(sum);
}

// function to initialize k centroids randomly
void initialize_centroids(data_point *data_points, int num_points, data_point *centroids) {
  int indexes[K];
  for (int i = 0; i < K; i++) {
    bool flag = false;
    do {
      indexes[i] = rand() % num_points;
      flag = false;
      for (int j = 0; j < i; j++) {
        if (indexes[j] == indexes[i]) {
          flag = true;
          break;
        }
      }
    } while (flag);
    centroids[i] = data_points[indexes[i]];
    centroids[i].cluster_id = i;
  }
}

// function to assign data points to closest centroid
void assign_to_cluster(data_point *data_points, int num_points, data_point *centroids) {
  for (int i = 0; i < num_points; i++) {
    double min_distance = INFINITY;
    for (int j = 0; j < K; j++) {
      double distance = euclidean_distance(data_points[i], centroids[j]);
      if (distance < min_distance) {
        min_distance = distance;
        data_points[i].cluster_id = j;
      }
    }
  }
}

// function to calculate new centroid positions
void calculate_new_centroids(data_point *data_points, int num_points, data_point *centroids) {
  int cluster_counts[K] = {0};
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < DIMENSION; j++) {
      centroids[i].values[j] = 0.0;
    }
  }
  for (int i = 0; i < num_points; i++) {
    cluster_counts[data_points[i].cluster_id]++;
    for (int j = 0; j < DIMENSION; j++) {
      centroids[data_points[i].cluster_id].values[j] += data_points[i].values[j];
    }
  }
  for (int i = 0; i < K; i++) {
    if (cluster_counts[i] > 0) {
      for (int j = 0; j < DIMENSION; j++) {
        centroids[i].values[j] /= cluster_counts[i];
      }
    }
  }
}

int main() {
  int num_points = 1000;
  data_point *data_points = (data_point*)malloc(num_points * sizeof(data_point));
  generate_data_points(data_points, num_points);

  data_point centroids[K];
  initialize_centroids(data_points, num_points, centroids);

  int num_iterations = 10;
  for (int i = 0; i < num_iterations; i++) {
    assign_to_cluster(data_points, num_points, centroids);
    calculate_new_centroids(data_points, num_points, centroids);
  }

  for (int i = 0; i < K; i++) {
    printf("Cluster %d:\n", i);
    for (int j = 0; j < num_points; j++) {
      if (data_points[j].cluster_id == i) {
        printf("(%f, %f, %f, %f, %f)\n", data_points[j].values[0], data_points[j].values[1], data_points[j].values[2], data_points[j].values[3], data_points[j].values[4]);
      }
    }
  }

  free(data_points);
  return 0;
}