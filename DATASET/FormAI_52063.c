//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 10
#define CLUSTER_THRESHOLD 2.5

struct Point {
    double x;
    double y;
};

void printClusters(struct Point points[], int clusterAssignments[]) {
    int num_clusters = 0;
    for(int i = 0; i < NUM_POINTS; i++) {
        if(clusterAssignments[i] > num_clusters)
            num_clusters = clusterAssignments[i];
    }
    int cluster_indexes[num_clusters];
    for(int i = 0; i <= num_clusters; i++) {
        cluster_indexes[i] = 0;
        printf("Cluster %d:\n", i+1);
        for(int j = 0; j < NUM_POINTS; j++) {
            if(clusterAssignments[j] == i+1) {
                printf("(%lf, %lf)\n", points[j].x, points[j].y);
                cluster_indexes[i]++;
            }
        }
    }
}

double euclideanDistance(struct Point p1, struct Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

int main() {
    struct Point points[NUM_POINTS] = {{3.2, 4.5}, {2.6, 7.8}, {1.0, 3.8}, {8.9, 6.2}, {1.4, 6.1}, {9.5, 8.6}, {1.5, 4.1}, {4.5, 5.6}, {5.7, 8.6}, {5.2, 4.3} };
    double distances[NUM_POINTS][NUM_POINTS];
    int clusterAssignments[NUM_POINTS];
    for(int i = 0; i < NUM_POINTS; i++)
        clusterAssignments[i] = -1;
    int curr_cluster = 0;
    for(int i = 0; i < NUM_POINTS; i++) {
        if(clusterAssignments[i] == -1) {
            clusterAssignments[i] = ++curr_cluster;
            for(int j = i + 1; j < NUM_POINTS; j++) {
                distances[i][j] = euclideanDistance(points[i], points[j]);
                if(distances[i][j] <= CLUSTER_THRESHOLD)
                    clusterAssignments[j] = curr_cluster;
            }
        }
    }
    printClusters(points, clusterAssignments);
    return 0;
}