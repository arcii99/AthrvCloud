//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 10000
#define THRESHOLD 1000

/* Structure of a point in 3D space */
typedef struct Point {
    double x, y, z;
} Point;

/* Computes the Euclidean distance between two points in 3D space */
double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

/* Clustering algorithm implementation */
void cluster(Point points[], int numPoints) {
    /* Initialize cluster count and visited flag for each point */
    int numClusters = 0;
    int visited[numPoints];
    for (int i = 0; i < numPoints; i++) {
        visited[i] = 0;
    }

    /* For each point, if it has not been visited, add it to a new cluster */
    for (int i = 0; i < numPoints; i++) {
        if (!visited[i]) {
            numClusters++;
            visited[i] = 1;

            /* Add all nearby unvisited points to the cluster */
            for (int j = 0; j < numPoints; j++) {
                if (!visited[j] && distance(points[i], points[j]) < THRESHOLD) {
                    visited[j] = 1;
                }
            }
        }
    }

    /* Print the number of clusters found */
    printf("Number of clusters found: %d\n", numClusters);
}

/* Main function */
int main() {
    /* Generate random points in 3D space */
    Point points[MAX_POINTS];
    int numPoints = 0;
    srand(0);
    for (int i = 0; i < MAX_POINTS; i++) {
        points[i].x = (double) rand();
        points[i].y = (double) rand();
        points[i].z = (double) rand();
        numPoints++;
    }

    /* Run the clustering algorithm */
    cluster(points, numPoints);

    return 0;
}