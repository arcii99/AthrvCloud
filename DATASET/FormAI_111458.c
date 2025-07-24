//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 2
#define EPSILON 0.01

// Define the data structure for the data points
typedef struct Point {
    double coord[DIMENSIONS];
} Point;

// Define the data structure for a cluster
typedef struct Cluster {
    Point centroid;
    Point *points;
    int size;
} Cluster;

// Function to calculate the Euclidean distance between two points
double distance(Point a, Point b) {
    double sum = 0;
    int i;
    for (i = 0; i < DIMENSIONS; i++) {
        sum += pow((a.coord[i] - b.coord[i]), 2);
    }
    return sqrt(sum);
}

// Function to calculate the distance between a point and a cluster's centroid
double clusterDistance(Cluster c, Point p) {
    return distance(c.centroid, p);
}

// Function to calculate the mean coordinates of a cluster's points
Point clusterMean(Cluster c) {
    Point mean;
    int i, j;
    for (i = 0; i < DIMENSIONS; i++) {
        mean.coord[i] = 0;
        for (j = 0; j < c.size; j++) {
            mean.coord[i] += c.points[j].coord[i];
        }
        mean.coord[i] /= c.size;
    }
    return mean;
}

// Function to initialize a cluster with a random point as its centroid
Cluster initializeCluster(Point *points, int n) {
    Cluster c;
    int i;
    c.centroid = points[rand() % n];
    c.size = 0;
    c.points = NULL;
    return c;
}

// Function to assign each point to its nearest cluster
void assignPointsToClusters(Point *points, int n, Cluster *clusters, int k) {
    int i, j, minIndex;
    double minDist, dist;
    for (i = 0; i < n; i++) {
        minIndex = 0;
        minDist = clusterDistance(clusters[0], points[i]);
        for (j = 1; j < k; j++) {
            dist = clusterDistance(clusters[j], points[i]);
            if (dist < minDist) {
                minDist = dist;
                minIndex = j;
            }
        }
        clusters[minIndex].size++;
        clusters[minIndex].points = realloc(clusters[minIndex].points, sizeof(Point) * clusters[minIndex].size);
        clusters[minIndex].points[clusters[minIndex].size - 1] = points[i];
    }
}

// Function to update the centroids of each cluster
void updateCentroids(Cluster *clusters, int k) {
    int i;
    for (i = 0; i < k; i++) {
        clusters[i].centroid = clusterMean(clusters[i]);
        free(clusters[i].points);
        clusters[i].points = NULL;
        clusters[i].size = 0;
    }
}

// Function to check if two sets of centroids are equal
int areCentroidsEqual(Cluster *clusters, Cluster *oldClusters, int k) {
    int i, j;
    for (i = 0; i < k; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            if (fabs(clusters[i].centroid.coord[j] - oldClusters[i].centroid.coord[j]) > EPSILON) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to print the points in each cluster
void printClusters(Cluster *clusters, int k) {
    int i, j;
    for (i = 0; i < k; i++) {
        printf("Cluster %d (%d points):\n", i + 1, clusters[i].size);
        for (j = 0; j < clusters[i].size; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].coord[0], clusters[i].points[j].coord[1]);
        }
    }
}

int main() {
    // Initialize the data points
    Point points[] = {
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 5},
        {6, 6},
        {7, 7},
        {8, 8},
        {9, 9},
        {10, 10}
    };
    int n = sizeof(points) / sizeof(Point);

    // Initialize the clusters
    int k = 3;
    Cluster clusters[k];
    int i, j;
    for (i = 0; i < k; i++) {
        clusters[i] = initializeCluster(points, n);
    }

    // Loop until the centroids stop changing
    Cluster oldClusters[k];
    int iterations = 0;
    while (!areCentroidsEqual(clusters, oldClusters, k)) {
        printf("Iteration %d:\n", iterations + 1);
        iterations++;
        for (i = 0; i < k; i++) {
            oldClusters[i] = clusters[i];
        }
        assignPointsToClusters(points, n, clusters, k);
        updateCentroids(clusters, k);
        printClusters(clusters, k);
        printf("\n");
    }

    return 0;
}