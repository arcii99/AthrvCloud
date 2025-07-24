//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// define the number of data points and clusters
#define N 50
#define K 3

// define the maximum number of iterations
#define MAX_ITERATIONS 1000

// define the minimum change threshold
#define MIN_CHANGE_THRESHOLD 0.0001

// define a struct for the data point
struct DataPoint {
    double x;
    double y;
};

// define a struct for the cluster
struct Cluster {
    struct DataPoint centroid;
    int count;
    struct DataPoint dataPoints[N]; 
};

// function to calculate the euclidean distance between two points
double calculateDistance(struct DataPoint p1, struct DataPoint p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// function to assign data points to the nearest cluster
void assignClusters(struct DataPoint data[N], struct Cluster clusters[K]) {
    double distance;
    int i, j;
    for (i = 0; i < N; i++) {
        int clusterIndex = 0;
        for (j = 0; j < K; j++) {
            if (j == 0 || distance < calculateDistance(data[i], clusters[j].centroid)) {
                distance = calculateDistance(data[i], clusters[j].centroid);
                clusterIndex = j;
            }
        }
        clusters[clusterIndex].dataPoints[clusters[clusterIndex].count++] = data[i];
    }
}

// function to update the centroids of the clusters
bool updateCentroids(struct Cluster clusters[K]) {
    bool hasChanged = false;
    int i, j;
    for (i = 0; i < K; i++) {
        double sumX = 0, sumY = 0;
        for (j = 0; j < clusters[i].count; j++) {
            sumX += clusters[i].dataPoints[j].x;
            sumY += clusters[i].dataPoints[j].y;
        }
        struct DataPoint newCentroid = {sumX / clusters[i].count, sumY / clusters[i].count};
        if (calculateDistance(clusters[i].centroid, newCentroid) > MIN_CHANGE_THRESHOLD) {
            clusters[i].centroid = newCentroid;
            hasChanged = true;
        }
    }
    return hasChanged;
}

// function to print the clusters
void printClusters(struct Cluster clusters[K]) {
    int i, j;
    for (i = 0; i < K; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid: (%.2lf, %.2lf)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Data Points: {");
        for (j = 0; j < clusters[i].count; j++) {
            printf("(%.2lf, %.2lf)", clusters[i].dataPoints[j].x, clusters[i].dataPoints[j].y);
            if (j < clusters[i].count - 1) printf(", ");
        }
        printf("}\n\n");
    }
}

int main() {
    // initialize the data points
    struct DataPoint data[N] = {{3.00, 2.00}, {4.00, 3.00}, {4.00, 5.00}, {3.00, 6.00},
                                {6.00, 5.00}, {7.00, 7.00}, {8.00, 5.00}, {7.00, 3.00},
                                {10.00, 10.00}, {9.00, 9.00}, {11.00, 9.00}, {12.00, 8.00},
                                {9.00, 7.00}, {10.00, 8.00}, {11.00, 7.00}, {12.00, 9.00},
                                {25.00, 30.00}, {27.00, 29.00}, {28.00, 28.00}, {26.00, 27.00},
                                {30.00, 29.00}, {30.00, 27.00}, {30.00, 25.00}, {28.00, 24.00},
                                {27.00, 22.00}, {28.00, 21.00}, {30.00, 20.00}, {32.00, 22.00},
                                {32.00, 24.00}, {32.00, 26.00}, {34.00, 26.00}, {34.00, 28.00},
                                {34.00, 30.00}, {26.00, 36.00}, {26.00, 38.00}, {28.00, 38.00},
                                {30.00, 37.00}, {32.00, 38.00}, {34.00, 38.00}, {34.00, 36.00},
                                {36.00, 36.00}, {36.00, 38.00}, {38.00, 38.00}, {38.00, 36.00},
                                {30.00, 35.00}, {32.00, 34.00}, {34.00, 34.00}, {36.00, 34.00}};

    // initialize the clusters with random centroids
    struct Cluster clusters[K];
    int i, j;
    for (i = 0; i < K; i++) {
        int randomIndex = rand() % N;
        clusters[i].centroid = data[randomIndex];
        clusters[i].count = 0;
    }

    // run the k-means clustering algorithm
    int iterations = 0;
    while (iterations < MAX_ITERATIONS) {
        for (i = 0; i < K; i++) {
            clusters[i].count = 0;
        }
        assignClusters(data, clusters);
        if (!updateCentroids(clusters)) break;
        iterations++;
    }

    // print the final clusters
    printClusters(clusters);

    return 0;
}