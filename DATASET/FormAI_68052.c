//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// number of points
#define N 100

// define Point struct which holds the x and y coordinates of a point
typedef struct {
    double x;
    double y;
} Point;

// define Cluster struct which holds the centroid and points associated with a cluster
typedef struct {
    Point centroid;
    Point *points;
    int numPoints;
} Cluster;

// function to calculate Euclidean distance between two points
double distance(Point p1, Point p2) {
    double distance = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
    return distance;
}

// function to initialize clusters by assigning random centroids from the set of points
void initializeClusters(Point *points, Cluster *clusters, int numClusters) {
    int i, j, randomIndex;
    for (i = 0; i < numClusters; i++) {
        // select a random point as centroid
        randomIndex = rand() % N;
        clusters[i].centroid = points[randomIndex];
        clusters[i].points = malloc(N * sizeof(Point));
        clusters[i].numPoints = 0;
    }
}

// function to assign each point to its nearest cluster
void assignPointsToClusters(Point *points, Cluster *clusters, int numClusters) {
    int i, j;
    double minDistance, currentDistance;
    int closestCluster;
    for (i = 0; i < N; i++) {
        minDistance = INT_MAX;
        for (j = 0; j < numClusters; j++) {
            currentDistance = distance(points[i], clusters[j].centroid);
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
                closestCluster = j;
            }
        }
        // add the point to the closest cluster
        clusters[closestCluster].points[clusters[closestCluster].numPoints] = points[i];
        clusters[closestCluster].numPoints++;
    }
}

// function to calculate the new centroid of a cluster
Point calculateCentroid(Cluster cluster) {
    Point newCentroid;
    double sumX = 0.0;
    double sumY = 0.0;
    int i;
    for (i = 0; i < cluster.numPoints; i++) {
        sumX += cluster.points[i].x;
        sumY += cluster.points[i].y;
    }
    newCentroid.x = sumX / (double) cluster.numPoints;
    newCentroid.y = sumY / (double) cluster.numPoints;
    return newCentroid;
}

// function to update the centroids of each cluster
void updateCentroids(Cluster *clusters, int numClusters) {
    int i;
    for (i = 0; i < numClusters; i++) {
        clusters[i].centroid = calculateCentroid(clusters[i]);
        free(clusters[i].points);
        clusters[i].points = malloc(N * sizeof(Point));
        clusters[i].numPoints = 0;
    }
}

// function to check if the centroids of each cluster have converged
int centroidsConverged(Cluster *oldClusters, Cluster *newClusters, int numClusters) {
    int i;
    for (i = 0; i < numClusters; i++) {
        if (distance(oldClusters[i].centroid, newClusters[i].centroid) > 0.001) {
            // if any centroid has moved more than 0.001 distance units, return false
            return 0;
        }
    }
    return 1;
}

int main() {
    // generate random data points
    int i;
    Point points[N];
    for (i = 0; i < N; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    // initialize clusters
    int numClusters = 5; // we will cluster the points into 5 groups
    Cluster clusters[numClusters];
    initializeClusters(points, clusters, numClusters);

    // perform k-means clustering
    Cluster oldClusters[numClusters];
    int iterations = 0;
    while (1) {
        iterations++;
        // make a copy of the current clusters to check for convergence later
        for (i = 0; i < numClusters; i++) {
            oldClusters[i] = clusters[i];
        }
        // assign each point to its nearest cluster
        assignPointsToClusters(points, clusters, numClusters);
        // update centroids of each cluster
        updateCentroids(clusters, numClusters);
        // check if centroids have converged
        if (centroidsConverged(oldClusters, clusters, numClusters)) {
            break;
        }
    }

    // print out the final clusters
    for (i = 0; i < numClusters; i++) {
        printf("Cluster %d: (%.2lf, %.2lf)\n", i+1, clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points in Cluster %d:\n", i+1);
        int j;
        for (j = 0; j < clusters[i].numPoints; j++) {
            printf("(%.2lf, %.2lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
    printf("K-means clustering converged after %d iterations.\n", iterations);

    return 0;
}