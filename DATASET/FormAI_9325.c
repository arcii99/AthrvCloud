//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_ITERATIONS 50
#define CLUSTERS 2
#define DIMENSIONS 2

/* Data point structure */
typedef struct {
    float coords[DIMENSIONS];
    int cluster;
} Point;

/* Function that initializes the data points randomly */
void initPoints(Point points[], int count) {
    int i, j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            points[i].coords[j] = (float) rand() / RAND_MAX;
        }
        points[i].cluster = -1;
    }
}

/* Function that calculates Euclidian distance between two data points */
float getDistance(Point p1, Point p2) {
    int i;
    float sum = 0;
    for (i = 0; i < DIMENSIONS; i++) {
        float diff = p1.coords[i] - p2.coords[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

/* Function that assigns each point to the nearest cluster */
void assignPoints(Point points[], int count, Point centers[], int k) {
    int i, j;
    for (i = 0; i < count; i++) {
        float minDistance = getDistance(points[i], centers[0]);
        int minIndex = 0;
        for (j = 1; j < k; j++) {
            float distance = getDistance(points[i], centers[j]);
            if (distance < minDistance) {
                minDistance = distance;
                minIndex = j;
            }
        }
        points[i].cluster = minIndex;
    }
}

/* Function that recalculates the centers of each cluster */
int recalculateCenters(Point points[], int count, Point centers[], int k) {
    int i, j;
    int changed = 0;
    for (i = 0; i < k; i++) {
        int clusterSize = 0;
        float coordsSum[DIMENSIONS] = { 0 };
        for (j = 0; j < count; j++) {
            if (points[j].cluster == i) {
                int d;
                for (d = 0; d < DIMENSIONS; d++) {
                    coordsSum[d] += points[j].coords[d];
                }
                clusterSize++;
            }
        }
        if (clusterSize > 0) {
            for (j = 0; j < DIMENSIONS; j++) {
                float newCoord = coordsSum[j] / clusterSize;
                if (newCoord != centers[i].coords[j]) {
                    centers[i].coords[j] = newCoord;
                    changed = 1;
                }
            }
        }
    }
    return changed;
}

/* Function that prints the results */
void printResults(Point points[], int count, Point centers[], int k) {
    int i, j;
    for (i = 0; i < k; i++) {
        printf("Cluster %d center:", i);
        for (j = 0; j < DIMENSIONS; j++) {
            printf("%f ", centers[i].coords[j]);
        }
        printf("\n");
    }
    for (i = 0; i < count; i++) {
        printf("%f %f %d\n", points[i].coords[0], points[i].coords[1], points[i].cluster);
    }
}

int main() {
    Point points[MAX_POINTS];
    Point centers[CLUSTERS];
    int i, j;
    
    /* Initialize data points randomly */
    initPoints(points, MAX_POINTS);
    
    /* Initialize cluster centers randomly */
    for (i = 0; i < CLUSTERS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            centers[i].coords[j] = (float) rand() / RAND_MAX;
        }
    }
    
    /* Perform clustering */
    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        assignPoints(points, MAX_POINTS, centers, CLUSTERS);
        if (!recalculateCenters(points, MAX_POINTS, centers, CLUSTERS)) {
            break;
        }
        iteration++;
    }
    
    /* Print the results */
    printResults(points, MAX_POINTS, centers, CLUSTERS);
    
    return 0;
}