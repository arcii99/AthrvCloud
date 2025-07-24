//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 100
#define NUM_CLUSTERS 3

struct Point {
    double x;
    double y;
};

// Generate random data points
void generateData(struct Point* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i].x = (double) rand() / RAND_MAX * 100;
        data[i].y = (double) rand() / RAND_MAX * 100;
    }
}

// Distance between two points
double distance(struct Point p1, struct Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Assign data points to clusters based on distance to centroids
void assignToClusters(struct Point* data, int size, struct Point* centroids, int num_clusters, int* assignments) {
    for (int i = 0; i < size; i++) {
        double min_dist = INFINITY;
        int min_centroid = 0;
        for (int j = 0; j < num_clusters; j++) {
            double dist = distance(data[i], centroids[j]);
            if (dist < min_dist) {
                min_dist = dist;
                min_centroid = j;
            }
        }
        assignments[i] = min_centroid;
    }
}

// Update centroids based on mean of assigned data points
void updateCentroids(struct Point* data, int size, int* assignments, struct Point* centroids, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        double sum_x = 0;
        double sum_y = 0;
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (assignments[j] == i) {
                sum_x += data[j].x;
                sum_y += data[j].y;
                count++;
            }
        }
        if (count > 0) {
            centroids[i].x = sum_x / count;
            centroids[i].y = sum_y / count;
        }
    }
}

// Output clusters to console
void outputClusters(struct Point* data, int size, int* assignments, struct Point* centroids, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d - Centroid (%.2f, %.2f): ", i, centroids[i].x, centroids[i].y);
        for (int j = 0; j < size; j++) {
            if (assignments[j] == i) {
                printf("(%.2f, %.2f) ", data[j].x, data[j].y);
            }
        }
        printf("\n");
    }
}

int main() {
    struct Point data[DATA_SIZE];
    generateData(data, DATA_SIZE);

    struct Point centroids[NUM_CLUSTERS];
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        centroids[i] = data[rand() % DATA_SIZE];
    }

    int assignments[DATA_SIZE];
    assignToClusters(data, DATA_SIZE, centroids, NUM_CLUSTERS, assignments);

    for (int i = 0; i < 10; i++) {
        updateCentroids(data, DATA_SIZE, assignments, centroids, NUM_CLUSTERS);
        assignToClusters(data, DATA_SIZE, centroids, NUM_CLUSTERS, assignments);
    }

    outputClusters(data, DATA_SIZE, assignments, centroids, NUM_CLUSTERS);

    return 0;
}