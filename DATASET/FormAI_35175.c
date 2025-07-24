//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
/* 
   This is a unique implementation of the C Clustering Algorithm.
   It finds clusters of points in a 2D space based on their proximity.
   The algorithm stores the clusters in an array of linked lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100
#define EPSILON 5 /* Maximum distance between points in a cluster */
#define MIN_POINTS_IN_CLUSTER 3 /* Minimum number of points to form a cluster */

/* A point in 2D space */
typedef struct Point {
  double x;
  double y;
  struct Point *next; /* Pointer to next point in a cluster */
} Point;

/* A cluster of points */
typedef struct Cluster {
  Point *head; /* Pointer to the head of the linked list */
  int size; /* Number of points in the cluster */
} Cluster;

/* Calculates the Euclidean distance between two points */
double distance(Point *p1, Point *p2) {
  double dx = p1->x - p2->x;
  double dy = p1->y - p2->y;
  return sqrt(dx*dx + dy*dy);
}

int main() {
  /* Generate random points */
  Point points[NUM_POINTS];
  for (int i = 0; i < NUM_POINTS; i++) {
    points[i].x = rand() % 100;
    points[i].y = rand() % 100;
    points[i].next = NULL;
  }

  /* Initialize clusters */
  Cluster clusters[NUM_POINTS];
  for (int i = 0; i < NUM_POINTS; i++) {
    clusters[i].head = &points[i];
    clusters[i].size = 1;
  }

  /* Perform clustering */
  for (int i = 0; i < NUM_POINTS; i++) {
    for (int j = i+1; j < NUM_POINTS; j++) {
      double d = distance(&points[i], &points[j]);
      if (d < EPSILON) {
        /* Merge clusters if points are close enough */
        if (clusters[i].size + clusters[j].size >= MIN_POINTS_IN_CLUSTER) {
          /* Add all points from cluster j to cluster i */
          Point *p = clusters[j].head;
          while (p != NULL) {
            Point *tmp = p->next;
            p->next = clusters[i].head;
            clusters[i].head = p;
            p = tmp;
          }
          clusters[i].size += clusters[j].size;
          /* Empty cluster j */
          clusters[j].head = NULL;
          clusters[j].size = 0;
        }
      }
    }
  }

  /* Print clusters */
  int num_clusters = 0;
  for (int i = 0; i < NUM_POINTS; i++) {
    if (clusters[i].size >= MIN_POINTS_IN_CLUSTER) {
      printf("Cluster %d:\n", num_clusters++);
      Point *p = clusters[i].head;
      while (p != NULL) {
        printf("  (%.1f, %.1f)\n", p->x, p->y);
        p = p->next;
      }
    }
  }

  return 0;
}