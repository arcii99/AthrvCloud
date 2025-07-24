//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLUSTER_COUNT 3
#define MAX_POINTS 100

struct Point {
    int x;
    int y;
    int cluster;
};

struct Cluster {
    int x;
    int y;
};

int getDistance(struct Point p1, struct Point p2) {
    int distance = abs(p1.x - p2.x) + abs(p1.y - p2.y);
    return distance;
}

void assignCluster(struct Point points[], struct Cluster clusters[]) {
    for (int i = 0; i < MAX_POINTS; i++) {
        int min = __INT_MAX__;
        int clusterIndex = 0;
        for (int j = 0; j < CLUSTER_COUNT; j++) {
            int distance = getDistance(points[i], (struct Point){clusters[j].x, clusters[j].y});
            if (distance < min) {
                min = distance;
                clusterIndex = j;
            }
        }
        points[i].cluster = clusterIndex;
    }
}

void recalculateCentroids(struct Point points[], struct Cluster clusters[]) {
    int pointsCount[CLUSTER_COUNT] = {0};
    int xSum[CLUSTER_COUNT] = {0};
    int ySum[CLUSTER_COUNT] = {0};
    for (int i = 0; i < MAX_POINTS; i++) {
        int clusterIndex = points[i].cluster;
        pointsCount[clusterIndex]++;
        xSum[clusterIndex] += points[i].x;
        ySum[clusterIndex] += points[i].y;
    }
    for (int i = 0; i < CLUSTER_COUNT; i++) {
        if (pointsCount[i] > 0) {
            clusters[i].x = xSum[i] / pointsCount[i];
            clusters[i].y = ySum[i] / pointsCount[i];
        }
    }
}

void printPoints(struct Point points[]) {
    for (int i = 0; i < MAX_POINTS; i++) {
        printf("(%d, %d) belongs to cluster %d\n", points[i].x, points[i].y, points[i].cluster);
    }
}

int main() {
    // Create random points
    srand(time(NULL));
    struct Point points[MAX_POINTS];
    for (int i = 0; i < MAX_POINTS; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
        points[i].cluster = 0;
    }

    // Initialize clusters at random points
    struct Cluster clusters[CLUSTER_COUNT];
    for (int i = 0; i < CLUSTER_COUNT; i++) {
        int randomIndex = rand() % MAX_POINTS;
        clusters[i].x = points[randomIndex].x;
        clusters[i].y = points[randomIndex].y;
    }

    // K-means clustering
    int iteration = 0;
    while (iteration < 10) {
        assignCluster(points, clusters);
        recalculateCentroids(points, clusters);
        iteration++;
    }

    // Print results
    printPoints(points);

    return 0;
}