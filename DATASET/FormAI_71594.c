//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data structure for a point in 3-dimensional space
typedef struct Point {
    double x;
    double y;
    double z;
} Point;

// Define the data structure for a cluster of points
typedef struct Cluster {
    Point centroid;
    Point *points;
    int size;
} Cluster;

// Define a function to calculate the Euclidean distance between two points
double distance(Point *p1, Point *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Define a function to initialize a cluster with a specified centroid and size
Cluster *createCluster(Point *centroid, int size) {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->centroid = *centroid;
    cluster->points = malloc(size * sizeof(Point));
    cluster->size = size;
    return cluster;
}

// Define the main function for the program
int main() {

    // Generate some random points in 3-dimensional space
    Point points[10];
    for (int i = 0; i < 10; i++) {
        points[i] = (Point){.x = rand() % 10, .y = rand() % 10, .z = rand() % 10};
    }

    // Initialize two clusters with random centroids and equal size
    Point centroid1 = points[rand() % 10];
    Point centroid2 = points[rand() % 10];
    Cluster *cluster1 = createCluster(&centroid1, 5);
    Cluster *cluster2 = createCluster(&centroid2, 5);

    // Randomly assign points to the two clusters
    for (int i = 0; i < 10; i++) {
        if (rand() % 2 == 0) {
            cluster1->points[cluster1->size++] = points[i];
        } else {
            cluster2->points[cluster2->size++] = points[i];
        }
    }

    // Iteratively update the centroids and reassign points until convergence
    int iteration = 0;
    double threshold = 0.01;
    double change = INFINITY;
    while (change > threshold) {

        // Calculate the new centroids for each cluster
        Point newCentroid1 = {0, 0, 0};
        Point newCentroid2 = {0, 0, 0};
        for (int i = 0; i < cluster1->size; i++) {
            newCentroid1.x += cluster1->points[i].x;
            newCentroid1.y += cluster1->points[i].y;
            newCentroid1.z += cluster1->points[i].z;
        }
        newCentroid1.x /= cluster1->size;
        newCentroid1.y /= cluster1->size;
        newCentroid1.z /= cluster1->size;
        for (int i = 0; i < cluster2->size; i++) {
            newCentroid2.x += cluster2->points[i].x;
            newCentroid2.y += cluster2->points[i].y;
            newCentroid2.z += cluster2->points[i].z;
        }
        newCentroid2.x /= cluster2->size;
        newCentroid2.y /= cluster2->size;
        newCentroid2.z /= cluster2->size;

        // Calculate the change in centroids and reset the cluster sizes
        change = distance(&centroid1, &newCentroid1) + distance(&centroid2, &newCentroid2);
        centroid1 = newCentroid1;
        centroid2 = newCentroid2;
        cluster1->size = 0;
        cluster2->size = 0;

        // Reassign points to the two clusters based on proximity to centroids
        for (int i = 0; i < 10; i++) {
            double distance1 = distance(&points[i], &centroid1);
            double distance2 = distance(&points[i], &centroid2);
            if (distance1 < distance2) {
                cluster1->points[cluster1->size++] = points[i];
            } else {
                cluster2->points[cluster2->size++] = points[i];
            }
        }

        // Print the current iteration and cluster assignments
        printf("Iteration %d\n", iteration++);
        printf("Cluster 1: ");
        for (int i = 0; i < cluster1->size; i++) {
            printf("(%g, %g, %g) ", cluster1->points[i].x, cluster1->points[i].y, cluster1->points[i].z);
        }
        printf("\n");
        printf("Cluster 2: ");
        for (int i = 0; i < cluster2->size; i++) {
            printf("(%g, %g, %g) ", cluster2->points[i].x, cluster2->points[i].y, cluster2->points[i].z);
        }
        printf("\n");

    }

    // Free the memory allocated for the clusters and exit
    free(cluster1->points);
    free(cluster1);
    free(cluster2->points);
    free(cluster2);
    return 0;

}