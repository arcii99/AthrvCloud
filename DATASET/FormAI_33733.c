//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_DIMENSIONS 10

typedef struct  Point {
  float coordinates[MAX_DIMENSIONS];
} Point;

typedef struct Cluster {
  Point center;
  Point* points;
  int num_points;
} Cluster;

void initialize_points(Point points[], int num_points, int num_dimensions) {
  srand(time(NULL));
  for(int i = 0; i < num_points; ++i) {
    for(int j = 0; j < num_dimensions; ++j) {
      points[i].coordinates[j] = (float)(rand() % 100);
    }
  }
}

float euclidean_distance(Point point1, Point point2, int num_dimensions) {
  float sum = 0;
  for(int i = 0; i < num_dimensions; ++i) {
    float diff = point1.coordinates[i] - point2.coordinates[i];
    sum += diff * diff;
  }
  return sqrt(sum);
}

void initialize_clusters(Cluster clusters[], int num_clusters, Point points[], int num_points, int num_dimensions) {
  srand(time(NULL));
  for(int i = 0; i < num_clusters; ++i) {
    int index = rand() % num_points;
    clusters[i].center = points[index];
    clusters[i].points = malloc(num_points * sizeof(Point));
    clusters[i].num_points = 0;
  }
}

void assign_points_to_clusters(Cluster clusters[], int num_clusters, Point points[], int num_points, int num_dimensions) {
  for(int i = 0; i < num_points; ++i) {
    Point point = points[i];
    int closest_cluster_index = -1;
    float shortest_distance = INFINITY;
    for(int j = 0; j < num_clusters; ++j) {
      Cluster cluster = clusters[j];
      float distance = euclidean_distance(point, cluster.center, num_dimensions);
      if(distance < shortest_distance) {
        shortest_distance = distance;
        closest_cluster_index = j;
      }
    }
    clusters[closest_cluster_index].points[clusters[closest_cluster_index].num_points++] = point;
  }
}

void calculate_new_cluster_centers(Cluster clusters[], int num_clusters, int num_dimensions) {
  for(int i = 0; i < num_clusters; ++i) {
    Cluster cluster = clusters[i];
    Point* points = cluster.points;
    int num_points = cluster.num_points;
    if(num_points > 0) {
      for(int j = 0; j < num_dimensions; ++j) {
        float sum = 0;
        for(int k = 0; k < num_points; ++k) {
          sum += points[k].coordinates[j];
        }
        float average = sum / num_points;
        cluster.center.coordinates[j] = average;
      }
    }
  }
}

void print_clusters(Cluster clusters[], int num_clusters, int num_dimensions) {
  for(int i = 0; i < num_clusters; ++i) {
    Cluster cluster = clusters[i];
    printf("Cluster %d:\n", i + 1);
    printf("Center: (");
    for(int j = 0; j < num_dimensions; ++j) {
      printf("%.2f", cluster.center.coordinates[j]);
      if(j < num_dimensions - 1) {
        printf(", ");
      }
    }
    printf(")\nPoints: ");
    for(int j = 0; j < cluster.num_points; ++j) {
      printf("(");
      for(int k = 0; k < num_dimensions; ++k) {
        printf("%.2f", cluster.points[j].coordinates[k]);
        if(k < num_dimensions - 1) {
          printf(", ");
        }
      }
      printf(")");
      if(j < cluster.num_points - 1) {
        printf(", ");
      }
    }
    printf("\n\n");
  }
}

int main() {
  int num_clusters = 3;
  int num_points = 20;
  int num_dimensions = 5;
  Point points[MAX_POINTS];
  Cluster clusters[num_clusters];
  
  initialize_points(points, num_points, num_dimensions);
  initialize_clusters(clusters, num_clusters, points, num_points, num_dimensions);
  
  for(int i = 0; i < 10; ++i) {
    assign_points_to_clusters(clusters, num_clusters, points, num_points, num_dimensions);
    calculate_new_cluster_centers(clusters, num_clusters, num_dimensions);
  }
  
  print_clusters(clusters, num_clusters, num_dimensions);
  
  for(int i = 0; i < num_clusters; ++i) {
    free(clusters[i].points);
  }
  
  return 0;
}