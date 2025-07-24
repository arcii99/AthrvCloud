//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define CLUSTERS 5
#define DIMENSIONS 2
#define DATAPOINTS 200

typedef struct {
    int identifier;
    double coordinates[DIMENSIONS];
} point;

typedef struct {
    point centroid;
    point tempCentroid;
    int numPoints;
    point *points;
} cluster;

double euclideanDist(point a, point b) {
    double distance = 0;
    int i;
    for (i = 0; i < DIMENSIONS; i++) {
        distance += pow((a.coordinates[i] - b.coordinates[i]), 2);
    }
    return sqrt(distance);
}

int findClosestCluster(point datapoint, cluster *clusters) {
    double distance;
    double minDist = euclideanDist(datapoint, clusters[0].centroid);
    int closestCluster = 0;
    int i;
    for (i = 1; i < CLUSTERS; i++) {
        distance = euclideanDist(datapoint, clusters[i].centroid);
        if (distance < minDist) {
            minDist = distance;
            closestCluster = i;
        }
    }
    return closestCluster;
}

void assignPoints(cluster *clusters, point *datapoints) {
    int i;
    int j;
    for (i = 0; i < DATAPOINTS; i++) {
        int closestCluster = findClosestCluster(datapoints[i], clusters);
        clusters[closestCluster].numPoints++;
        clusters[closestCluster].points = realloc(clusters[closestCluster].points, clusters[closestCluster].numPoints * sizeof(point));
        clusters[closestCluster].points[clusters[closestCluster].numPoints - 1] = datapoints[i];
    }
}

void updateCentroids(cluster *clusters) {
    int i;
    int j;
    double sum;
    while (true) {
        bool hasChanged = false;
        for (i = 0; i < CLUSTERS; i++) {
            for (j = 0; j < DIMENSIONS; j++) {
                sum = 0;
                int k;
                for (k = 0; k < clusters[i].numPoints; k++) {
                    sum += clusters[i].points[k].coordinates[j];
                }
                clusters[i].tempCentroid.coordinates[j] = sum / clusters[i].numPoints;
            }
            if (euclideanDist(clusters[i].centroid, clusters[i].tempCentroid) > 0.001) {
                hasChanged = true;
                clusters[i].centroid = clusters[i].tempCentroid;
            }
        }
        if (!hasChanged) {
            break;
        }
    }
}

void kMeansClustering(cluster *clusters, point *datapoints) {
    assignPoints(clusters, datapoints);
    updateCentroids(clusters);
}

int main() {
    srand(time(NULL));
    point datapoints[DATAPOINTS];
    cluster clusters[CLUSTERS];
    int i;
    int j;
    for (i = 0; i < DATAPOINTS; i++) {
        datapoints[i].identifier = i;
        for (j = 0; j < DIMENSIONS; j++) {
            datapoints[i].coordinates[j] = ((double)rand() / RAND_MAX) * 10;
        }
    }
    for (i = 0; i < CLUSTERS; i++) {
        clusters[i].centroid.identifier = i;
        for (j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid.coordinates[j] = ((double)rand() / RAND_MAX) * 10 - 5;
            clusters[i].tempCentroid.coordinates[j] = 0;
        }
        clusters[i].numPoints = 0;
        clusters[i].points = NULL;
    }
    kMeansClustering(clusters, datapoints);
    for (i = 0; i < CLUSTERS; i++) {
        printf("Cluster centroid %d: (%lf, %lf)\n", clusters[i].centroid.identifier, clusters[i].centroid.coordinates[0], clusters[i].centroid.coordinates[1]);
    }
    return 0;
}