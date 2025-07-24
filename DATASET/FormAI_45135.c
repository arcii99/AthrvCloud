//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define CLUSTER_RADIUS 5

typedef struct Point {
  int x;
  int y;
} Point;

int clustering_algorithm(Point points[], int num_points) {

  // Create a list to store the clusters
  int clusters[MAX_POINTS];

  // Initialize all clusters as unassigned (-1)
  for(int i=0; i<num_points; i++) {
    clusters[i] = -1;
  }

  int cluster_count = 1;
  
  // Start clustering
  for(int i=0; i<num_points; i++) {
    if(clusters[i] == -1) { // If point i is unassigned

      clusters[i] = cluster_count; // Assign it to a new cluster
      
      // Check all other unassigned points
      for(int j=i+1; j<num_points; j++) {
        if(clusters[j] == -1) {
          double distance = sqrt(pow((points[i].x - points[j].x), 2) + pow((points[i].y - points[j].y), 2));
          if(distance < CLUSTER_RADIUS) { // If the point is within the cluster radius
            clusters[j] = cluster_count; // Assign it to the same cluster as i
          }
        }
      }

      cluster_count++; // Move to the next cluster
    }
  }

  return cluster_count - 1; // Return the number of clusters found
}

int main() {

  // Randomly generate some points
  Point points[MAX_POINTS];
  int num_points = 0;

  for(int i=0; i<MAX_POINTS; i++) {
    points[i].x = rand() % 100;
    points[i].y = rand() % 100;

    if(rand() % 2 == 0) { // Randomly skip some points to decrease density
      num_points++;
    }
  }

  int cluster_count = clustering_algorithm(points, num_points);

  printf("Number of clusters found: %d", cluster_count);

  return 0;
}