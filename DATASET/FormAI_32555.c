//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTERS 10
#define MAX_DATA_POINTS 500

double data[MAX_DATA_POINTS][2];
int dataCount;
int clusterCount;

typedef struct {
    double values[2];
    double centroid[2];
    int count;
} Cluster;

Cluster clusters[MAX_CLUSTERS];

void initClusters() {
    for (int i = 0; i < clusterCount; i++) {
        clusters[i].values[0] = data[i][0];
        clusters[i].values[1] = data[i][1];
        clusters[i].centroid[0] = data[i][0];
        clusters[i].centroid[1] = data[i][1];
        clusters[i].count = 1;
    }
}

double getDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void updateCentroids() {
    for (int i = 0; i < clusterCount; i++) {
        if (clusters[i].count == 0) continue;
        double sumX = 0, sumY = 0;
        for (int j = 0; j < dataCount; j++) {
            if (clusters[i].values[0] == data[j][0] && clusters[i].values[1] == data[j][1]) continue;
            double dist = getDistance(clusters[i].values[0], clusters[i].values[1], data[j][0], data[j][1]);
            if (dist > 1) continue;  // Ignore points outside a circle of radius 1 around the current centroid
            sumX += data[j][0];
            sumY += data[j][1];
        }
        clusters[i].centroid[0] = sumX / clusters[i].count;
        clusters[i].centroid[1] = sumY / clusters[i].count;
    }
}

void assignClusters() {
    for (int i = 0; i < dataCount; i++) {
        double minDistance = INFINITY;
        int minIndex = -1;
        for (int j = 0; j < clusterCount; j++) {
            double dist = getDistance(clusters[j].centroid[0], clusters[j].centroid[1], data[i][0], data[i][1]);
            if (dist < minDistance) {
                minDistance = dist;
                minIndex = j;
            }
        }
        clusters[minIndex].count++;
        clusters[minIndex].values[0] += data[i][0];
        clusters[minIndex].values[1] += data[i][1];
    }
}

void printClusters() {
    for (int i = 0; i < clusterCount; i++) {
        printf("Cluster %d:\n", i);
        printf("\tCentroid: (%f, %f)\n", clusters[i].centroid[0], clusters[i].centroid[1]);
        printf("\tNumber of points: %d\n", clusters[i].count);
    }
}

int main() {
    char input[100];
    printf("Enter the number of data points: ");
    fgets(input, 100, stdin);
    dataCount = atoi(input);
    if (dataCount > MAX_DATA_POINTS || dataCount <= 0) {
        printf("Invalid number of data points. Exiting...\n");
        return 1;
    }
    printf("Enter the coordinates of the data points:\n");
    for (int i = 0; i < dataCount; i++) {
        printf("Data point %d: ", i + 1);
        fgets(input, 100, stdin);
        int parseCount = sscanf(input, "%lf %lf", &data[i][0], &data[i][1]);
        if (parseCount != 2) {
            printf("Invalid input. Exiting...\n");
            return 1;
        }
    }
    printf("Enter the number of clusters: ");
    fgets(input, 100, stdin);
    clusterCount = atoi(input);
    if (clusterCount > MAX_CLUSTERS || clusterCount <= 0) {
        printf("Invalid number of clusters. Exiting...\n");
        return 1;
    }
    initClusters();
    int iterations = 0;
    while (1) {
        iterations++;
        assignClusters();
        Cluster tempClusters[MAX_CLUSTERS];
        for (int i = 0; i < clusterCount; i++) tempClusters[i] = clusters[i];
        updateCentroids();
        int differences = 0;
        for (int i = 0; i < clusterCount; i++) {
            if (fabs(tempClusters[i].centroid[0] - clusters[i].centroid[0]) > 0.1 || fabs(tempClusters[i].centroid[1] - clusters[i].centroid[1]) > 0.1) {
                differences++;
                break;
            }
        }
        if (differences == 0) break;
    }
    printf("Iterations: %d\n", iterations);
    printClusters();
    return 0;
}