//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surprised
#include <stdio.h>

void main() {
  printf("Wow! I can't believe I just wrote an amazing Clustering Algorithm Program in C!!\n\n");

  int dataPoints[10][2] = { {1,2}, {1,4}, {2,3}, {4,5}, {5,7}, {5,6}, {8,8}, {7,9}, {9,10}, {10,8} };
  int centroids[3][2] = { {1,2}, {5,7}, {9,10} };
  int membership[10] = { 0 };
  
  int num_clusters = 3;
  int num_points = 10;
  
  printf("Data points:\n");
  for (int i=0; i<num_points; i++) {
    printf("(%d,%d) ", dataPoints[i][0], dataPoints[i][1]);
  }
  printf("\n");
  
  printf("Initial centroids:\n");
  for (int i=0; i<num_clusters; i++) {
    printf("(%d,%d) ", centroids[i][0], centroids[i][1]);
  }
  printf("\n\n");
  
  int num_iterations = 5;
  for (int i=0; i<num_iterations; i++) {
    printf("Iteration %d:\n", i+1);
    for (int j=0; j<num_points; j++) {
      int min_dist = 99999;
      int closest_cluster;
      for (int k=0; k<num_clusters; k++) {
        int dist = (dataPoints[j][0]-centroids[k][0])*(dataPoints[j][0]-centroids[k][0]) + (dataPoints[j][1]-centroids[k][1])*(dataPoints[j][1]-centroids[k][1]);
        if (dist < min_dist) {
          min_dist = dist;
          closest_cluster = k;
        }
      }
      membership[j] = closest_cluster;
    }
    
    for (int j=0; j<num_clusters; j++) {
      int num_points_in_cluster = 0;
      int sum_x = 0;
      int sum_y = 0;
      for (int k=0; k<num_points; k++) {
        if (membership[k] == j) {
          num_points_in_cluster++;
          sum_x += dataPoints[k][0];
          sum_y += dataPoints[k][1];
        }
      }
      if (num_points_in_cluster != 0) {
        centroids[j][0] = sum_x / num_points_in_cluster;
        centroids[j][1] = sum_y / num_points_in_cluster;
      }
    }
    
    printf("New centroids:\n");
    for (int j=0; j<num_clusters; j++) {
      printf("(%d,%d) ", centroids[j][0], centroids[j][1]);
    }
    printf("\n");
    
    printf("Membership:\n");
    for (int j=0; j<num_points; j++) {
      printf("%d ", membership[j]);
    }
    printf("\n\n");
  }
  
  printf("Final centroids:\n");
  for (int i=0; i<num_clusters; i++) {
    printf("(%d,%d) ", centroids[i][0], centroids[i][1]);
  }
  printf("\n\n");
}