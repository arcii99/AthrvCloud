//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_POINTS 100
#define CLUSTER_THRESHOLD 2.5

typedef struct {
  float x, y;
} Point;

typedef struct {
  Point centroid;
  float radius;
  int num_points;
  Point points[MAX_POINTS];
} Cluster;

/* Function to initialize the clusters */
void init_clusters(Cluster* clusters, int num_clusters, Point* points, int num_points) {
  int i, j;
  for(i = 0; i < num_clusters; i++) {
    clusters[i].num_points = 0;
    for(j = 0; j < num_points; j++) {
      if(i == j % num_clusters) {
        clusters[i].points[clusters[i].num_points].x = points[j].x;
        clusters[i].points[clusters[i].num_points].y = points[j].y;
        clusters[i].num_points++;
      }
    }
    /* Calculating centroid of each cluster */
    clusters[i].centroid.x = 0;
    clusters[i].centroid.y = 0;
    for(j = 0; j < clusters[i].num_points; j++) {
      clusters[i].centroid.x += clusters[i].points[j].x;
      clusters[i].centroid.y += clusters[i].points[j].y;
    }
    clusters[i].centroid.x /= clusters[i].num_points;
    clusters[i].centroid.y /= clusters[i].num_points;
    /* Calculating radius of each cluster */
    float max_distance = 0;
    for(j = 0; j < clusters[i].num_points; j++) {
      float distance = sqrt(pow(clusters[i].points[j].x - clusters[i].centroid.x, 2) + pow(clusters[i].points[j].y - clusters[i].centroid.y, 2));
      if(distance > max_distance) {
        max_distance = distance;
      }
    }
    clusters[i].radius = max_distance;
  }
}

/* Function to update the clusters */
void update_clusters(Cluster* clusters, int num_clusters, Point* points, int num_points) {
  int i, j, k;
  for(i = 0; i < num_points; i++) {
    float min_distance = CLUSTER_THRESHOLD;
    int min_cluster = -1;
    for(j = 0; j < num_clusters; j++) {
      float distance = sqrt(pow(points[i].x - clusters[j].centroid.x, 2) + pow(points[i].y - clusters[j].centroid.y, 2));
      if(distance < min_distance) {
        min_distance = distance;
        min_cluster = j;
      }
    }
    if(min_cluster != -1) {
      /* Adding point to its closest cluster */
      clusters[min_cluster].points[clusters[min_cluster].num_points].x = points[i].x;
      clusters[min_cluster].points[clusters[min_cluster].num_points].y = points[i].y;
      clusters[min_cluster].num_points++;
      /* Updating centroid of the cluster */
      clusters[min_cluster].centroid.x = 0;
      clusters[min_cluster].centroid.y = 0;
      for(k = 0; k < clusters[min_cluster].num_points; k++) {
        clusters[min_cluster].centroid.x += clusters[min_cluster].points[k].x;
        clusters[min_cluster].centroid.y += clusters[min_cluster].points[k].y;
      }
      clusters[min_cluster].centroid.x /= clusters[min_cluster].num_points;
      clusters[min_cluster].centroid.y /= clusters[min_cluster].num_points;
      /* Updating radius of the cluster */
      float max_distance = 0;
      for(k = 0; k < clusters[min_cluster].num_points; k++) {
        float distance = sqrt(pow(clusters[min_cluster].points[k].x - clusters[min_cluster].centroid.x, 2) + pow(clusters[min_cluster].points[k].y - clusters[min_cluster].centroid.y, 2));
        if(distance > max_distance) {
          max_distance = distance;
        }
      }
      clusters[min_cluster].radius = max_distance;
    }
  }
}

/* Function to print the clusters */
void print_clusters(Cluster* clusters, int num_clusters) {
  printf("Clusters:\n");
  int i, j;
  for(i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i + 1);
    printf("  Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
    printf("  Radius: %f\n", clusters[i].radius);
    printf("  Points: ");
    for(j = 0; j < clusters[i].num_points; j++) {
      printf("(%f, %f) ", clusters[i].points[j].x, clusters[i].points[j].y);
    }
    printf("\n");
  }
}

int main() {
  int num_clusters, num_points, i;
  printf("Enter number of clusters: ");
  scanf("%d", &num_clusters);
  printf("Enter number of points: ");
  scanf("%d", &num_points);
  Point points[num_points];
  printf("Enter the points:\n");
  for(i = 0; i < num_points; i++) {
    scanf("%f %f", &points[i].x, &points[i].y);
  }
  Cluster clusters[num_clusters];
  init_clusters(clusters, num_clusters, points, num_points);
  while(1) {
    update_clusters(clusters, num_clusters, points, num_points);
    print_clusters(clusters, num_clusters);
    printf("\n");
    char ch;
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &ch);
    if(ch == 'n' || ch == 'N') {
      break;
    }
  }
  return 0;
}