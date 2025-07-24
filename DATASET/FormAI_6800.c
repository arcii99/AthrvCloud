//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define CLUSTERS 5 // number of clusters
#define DIMENSIONS 2 // number of dimensions

struct Point {
    int id;
    float coordinates[DIMENSIONS];
    int cluster;
};

// Calculate Euclidean distance between two points
float getDistance(struct Point a, struct Point b) {
    float distance = 0.0;
    for (int i = 0; i < DIMENSIONS; i++)
        distance += pow(a.coordinates[i] - b.coordinates[i], 2);
    return sqrt(distance);
}

// Initialize k centroids randomly
void initCentroids(struct Point centroids[], struct Point points[], int n) {
    srand(time(NULL));
    int indices[CLUSTERS];
    for (int i = 0; i < CLUSTERS; i++) {
        int index = rand() % n;
        while (1) {
            int j;
            for (j = 0; j < i; j++) {
                if (index == indices[j]) {
                    index = rand() % n;
                    break;
                }
            }
            if (j == i)
                break;
        }
        centroids[i] = points[index];
    }
}

// Assign points to their nearest centroid
void assignClusters(struct Point centroids[], struct Point points[], int n) {
    for (int i = 0; i < n; i++) {
        float minDistance = INFINITY;
        for (int j = 0; j < CLUSTERS; j++) {
            float distance = getDistance(points[i], centroids[j]);
            if (distance < minDistance) {
                minDistance = distance;
                points[i].cluster = j;
            }
        }
    }
}

// Update centroids to the mean of their assigned points
void updateCentroids(struct Point centroids[], struct Point points[], int n) {
    int counts[CLUSTERS] = {0};
    for (int i = 0; i < CLUSTERS; i++)
        memset(centroids[i].coordinates, 0, DIMENSIONS * sizeof(float));
    for (int i = 0; i < n; i++) {
        int cluster = points[i].cluster;
        counts[cluster]++;
        for (int j = 0; j < DIMENSIONS; j++)
            centroids[cluster].coordinates[j] += points[i].coordinates[j];
    }
    for (int i = 0; i < CLUSTERS; i++) {
        if (counts[i] > 0) {
            for (int j = 0; j < DIMENSIONS; j++)
                centroids[i].coordinates[j] /= counts[i];
        }
    }
}

int main() {
    // Generate random points
    int n = 100;
    struct Point points[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        points[i].id = i + 1;
        for (int j = 0; j < DIMENSIONS; j++)
            points[i].coordinates[j] = (float)rand() / RAND_MAX;
        points[i].cluster = -1;
    }

    // Initialize centroids randomly
    struct Point centroids[CLUSTERS];
    initCentroids(centroids, points, n);

    // Run clustering algorithm
    int iterations = 10;
    for (int i = 0; i < iterations; i++) {
        assignClusters(centroids, points, n);
        updateCentroids(centroids, points, n);
    }

    // Print results
    for (int i = 0; i < n; i++)
        printf("Point %d: Cluster %d\n", points[i].id, points[i].cluster);

    return 0;
}