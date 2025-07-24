//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000                // Maximum no. of data points
#define K 5                   // Numbers of clusters
#define MAX_ITER 100          // Maximum number of iterations
#define THRESHOLD 0.0001      // Threshold for stopping condition

// Distance function to calculate Euclidean distance between two points
double distance(double p1[], double p2[]) {
  double dist = 0;
  for(int i=0; i<2; i++) {
    dist += pow(p1[i] - p2[i], 2);
  }
  return sqrt(dist);
}

// Function to assign initial random centroids
void initialize(double data[][2], double centroids[][2]) {
  for(int i=0; i<K; i++) {
    int r = rand() % N;
    centroids[i][0] = data[r][0];
    centroids[i][1] = data[r][1];
  }
}

// Function to update cluster assignments
void assign_clusters(double data[][2], double centroids[][2], int clusters[]) {
  double dist[K];
  for(int i=0; i<N; i++) {
    for(int j=0; j<K; j++) {
      dist[j] = distance(data[i], centroids[j]);
    }
    clusters[i] = 0;
    double min_dist = dist[0];
    for(int j=1; j<K; j++) {
      if(dist[j] < min_dist) {
        min_dist = dist[j];
        clusters[i] = j;
      }
    }
  }
}

// Function to update centroids
void update_centroids(double data[][2], double centroids[][2], int clusters[]) {
  double sum[K][2];
  int count[K];
  for(int i=0; i<K; i++) {
    sum[i][0] = 0;
    sum[i][1] = 0;
    count[i] = 0;
  }
  for(int i=0; i<N; i++) {
    int j = clusters[i];
    sum[j][0] += data[i][0];
    sum[j][1] += data[i][1];
    count[j]++;
  }
  for(int i=0; i<K; i++) {
    if(count[i] > 0) {
      centroids[i][0] = sum[i][0] / count[i];
      centroids[i][1] = sum[i][1] / count[i];
    }
  }
}

// Main function to perform k-means clustering
int main() {
  double data[N][2];          // Input data
  double centroids[K][2];     // Current centroids
  int clusters[N];            // Current cluster assignments
  // Read input data from file or generate randomly
  // For simplicity, we will use randomly generated data in this example
  for(int i=0; i<N; i++) {
    data[i][0] = (double) rand() / RAND_MAX;
    data[i][1] = (double) rand() / RAND_MAX;
  }
  // Initialize centroids
  initialize(data, centroids);
  // Perform k-means clustering
  int iter = 0;
  double prev_distortion = 0;
  double distortion = THRESHOLD + 1;
  while(iter < MAX_ITER && fabs(distortion - prev_distortion) > THRESHOLD) {
    assign_clusters(data, centroids, clusters);
    update_centroids(data, centroids, clusters);
    prev_distortion = distortion;
    distortion = 0;
    for(int i=0; i<N; i++) {
      distortion += distance(data[i], centroids[clusters[i]]);
    }
    iter++;
  }
  // Print final centroids and cluster assignments
  printf("Final centroids:\n");
  for(int i=0; i<K; i++) {
    printf("%.4f %.4f\n", centroids[i][0], centroids[i][1]);
  }
  printf("Cluster assignments:\n");
  for(int i=0; i<N; i++) {
    printf("%d ", clusters[i]);
  }
  printf("\n");
  return 0;
}