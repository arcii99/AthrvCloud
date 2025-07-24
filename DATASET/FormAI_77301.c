//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 2
#define NUMBER_OF_POINTS 10
#define NUMBER_OF_CLUSTERS 2
#define EPSILON 0.00001

double euclideanDistance(double x[], double y[]) {
    double sum = 0;
    for (int i = 0; i < DIMENSIONS; i++) {
        double diff = x[i] - y[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

int main() {
    double points[NUMBER_OF_POINTS][DIMENSIONS] = {
        {0.0, 0.4},
        {0.3, 0.2},
        {0.5, 0.6},
        {0.7, 0.4},
        {0.4, 0.1},
        {0.2, 0.8},
        {0.8, 0.7},
        {0.1, 0.3},
        {0.6, 0.3},
        {0.9, 0.5}
    };

    double centroids[NUMBER_OF_CLUSTERS][DIMENSIONS] = {
        {0.1, 0.2},
        {0.9, 0.7}
    };

    int cluster[NUMBER_OF_POINTS];
    double oldCentroids[NUMBER_OF_CLUSTERS][DIMENSIONS];

    while (1) {
        // Assign points to clusters
        for (int i = 0; i < NUMBER_OF_POINTS; i++) {
            double mindist = INFINITY;
            int minidx = -1;
            for (int j = 0; j < NUMBER_OF_CLUSTERS; j++) {
                double dist = euclideanDistance(points[i], centroids[j]);
                if (dist < mindist) {
                    mindist = dist;
                    minidx = j;
                }
            }
            cluster[i] = minidx;
        }

        // Save old centroids
        for (int i = 0; i < NUMBER_OF_CLUSTERS; i++) {
            for (int j = 0; j < DIMENSIONS; j++) {
                oldCentroids[i][j] = centroids[i][j];
            }
        }

        // Calculate new centroids
        for (int i = 0; i < NUMBER_OF_CLUSTERS; i++) {
            int numPoints = 0;
            double sum[DIMENSIONS] = {0};
            for (int j = 0; j < NUMBER_OF_POINTS; j++) {
                if (cluster[j] == i) {
                    numPoints++;
                    for (int k = 0; k < DIMENSIONS; k++) {
                        sum[k] += points[j][k];
                    }
                }
            }
            for (int k = 0; k < DIMENSIONS; k++) {
                if (numPoints > 0) {
                    centroids[i][k] = sum[k] / numPoints;
                }
            }
        }

        // Check if the centroids have converged
        int converged = 1;
        for (int i = 0; i < NUMBER_OF_CLUSTERS; i++) {
            if (euclideanDistance(oldCentroids[i], centroids[i]) > EPSILON) {
                converged = 0;
                break;
            }
        }
        if (converged) {
            break;
        }
    }

    // Print the clusters and their centroids
    for (int i = 0; i < NUMBER_OF_CLUSTERS; i++) {
        printf("Cluster %d: ", i);
        for (int j = 0; j < NUMBER_OF_POINTS; j++) {
            if (cluster[j] == i) {
                printf("%d ", j);
            }
        }
        printf("\nCentroid %d: ", i);
        for (int j = 0; j < DIMENSIONS; j++) {
            printf("%lf ", centroids[i][j]);
        }
        printf("\n");
    }

    return 0;
}