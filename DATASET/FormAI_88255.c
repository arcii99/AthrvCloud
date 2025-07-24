//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define CLUSTERS 2
#define MAX_ITERATIONS 10

// Define Point struct
typedef struct Point {
    double x;
    double y;
    int cluster;
} Point;

// Calculate Euclidean distance between two points
double getDistance(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

// Initialize points array with random point values and cluster assignments
void initPoints(Point points[], int n) {
    for(int i=0; i<n; i++) {
        points[i].x = (double)rand()/(double)(RAND_MAX/100);
        points[i].y = (double)rand()/(double)(RAND_MAX/100);
        points[i].cluster = -1;
    }
}

// Calculate the centroid of each cluster
void calculateCentroids(Point centroids[], Point points[], int n) {
    int numPoints[CLUSTERS] = {0};

    for(int i=0; i<n; i++) {
        int cluster = points[i].cluster;
        centroids[cluster].x += points[i].x;
        centroids[cluster].y += points[i].y;
        numPoints[cluster]++;
    }

    for(int i=0; i<CLUSTERS; i++) {
        centroids[i].x /= (double)numPoints[i];
        centroids[i].y /= (double)numPoints[i];
    }
}

// Assign each point to the closest centroid
void assignClusters(Point centroids[], Point points[], int n) {
    double minDistance, distance;
    int closestCluster;

    for(int i=0; i<n; i++) {
        minDistance = getDistance(points[i], centroids[0]);
        closestCluster = 0;

        for(int j=1; j<CLUSTERS; j++) {
            distance = getDistance(points[i], centroids[j]);
            if(distance < minDistance) {
                minDistance = distance;
                closestCluster = j;
            }
        }

        points[i].cluster = closestCluster;
    }
}

int main(void) {
    int n = MAX_POINTS;

    Point points[n], centroids[CLUSTERS];
    initPoints(points, n);

    // Choose initial centroids at random
    for(int i=0; i<CLUSTERS; i++) {
        centroids[i].x = (double)rand()/(double)(RAND_MAX/100);
        centroids[i].y = (double)rand()/(double)(RAND_MAX/100);
        centroids[i].cluster = i;
    }

    // Run clustering algorithm for a specified number of iterations or until convergence
    int iterations = 0;
    while(iterations < MAX_ITERATIONS) {
        assignClusters(centroids, points, n);
        calculateCentroids(centroids, points, n);
        iterations++;
    }

    // Print final points and their assigned clusters
    printf("%10s %10s %10s\n", "X", "Y", "Cluster");
    for(int i=0; i<n; i++) {
        printf("%10lf %10lf %10d\n", points[i].x, points[i].y, points[i].cluster);
    }

    return 0;
}