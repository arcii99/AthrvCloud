//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_POINTS 1000
#define MAX_DIMENSIONS 10

struct Point {
    double coords[MAX_DIMENSIONS];
};

struct Cluster {
    int size;
    struct Point centroid;
    struct Point points[MAX_POINTS];
};

double distance(struct Point p1, struct Point p2) {
    double sum = 0;
    for (int i = 0; i < MAX_DIMENSIONS; i++) {
        sum += pow(p1.coords[i] - p2.coords[i], 2);
    }
    return sqrt(sum);
}

void update_centroid(struct Cluster *cluster) {
    double sum_coords[MAX_DIMENSIONS] = {0};
    for (int i = 0; i < cluster->size; i++) {
        for (int j = 0; j < MAX_DIMENSIONS; j++) {
            sum_coords[j] += cluster->points[i].coords[j];
        }
    }
    for (int i = 0; i < MAX_DIMENSIONS; i++) {
        cluster->centroid.coords[i] = sum_coords[i] / cluster->size;
    }
}

void k_means_clustering(struct Point points[], int num_points, struct Cluster clusters[], int num_clusters) {
    // Assign each point to a random cluster
    for (int i = 0; i < num_points; i++) {
        int random_cluster = rand() % num_clusters;
        clusters[random_cluster].points[clusters[random_cluster].size++] = points[i];
    }

    // Calculate initial centroids
    for (int i = 0; i < num_clusters; i++) {
        update_centroid(&clusters[i]);
    }

    // Keep iterating until convergence
    while (1) {
        // Assign each point to the closest cluster
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            int closest_cluster_index = -1;
            for (int j = 0; j < num_clusters; j++) {
                double d = distance(points[i], clusters[j].centroid);
                if (d < min_distance) {
                    min_distance = d;
                    closest_cluster_index = j;
                }
            }
            clusters[closest_cluster_index].points[clusters[closest_cluster_index].size++] = points[i];
        }

        // Update centroids and check for convergence
        int converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            struct Point old_centroid = clusters[i].centroid;
            update_centroid(&clusters[i]);
            if (distance(clusters[i].centroid, old_centroid) > 0.0001) {
                converged = 0;
            }
            // Reset cluster points
            clusters[i].size = 0;
        }

        if (converged) {
            break;
        }
    }
}

int main() {
    // Generate random points
    srand(1);
    struct Point points[MAX_POINTS];
    int num_points = 50;
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < MAX_DIMENSIONS; j++) {
            points[i].coords[j] = (double) rand() / RAND_MAX;
        }
    }

    // Set up clusters
    int num_clusters = 3;
    struct Cluster clusters[num_clusters];
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].size = 0;
        for (int j = 0; j < MAX_DIMENSIONS; j++) {
            clusters[i].centroid.coords[j] = (double) rand() / RAND_MAX;
        }
        printf("Initial centroid of cluster %d: [ ", i);
        for (int j = 0; j < MAX_DIMENSIONS; j++) {
            printf("%f ", clusters[i].centroid.coords[j]);
        }
        printf("]\n");
    }

    // Run clustering algorithm
    k_means_clustering(points, num_points, clusters, num_clusters);

    // Print results
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("Centroid: [ ");
        for (int j = 0; j < MAX_DIMENSIONS; j++) {
            printf("%f ", clusters[i].centroid.coords[j]);
        }
        printf("]\n");
        printf("Points: [ ");
        for (int j = 0; j < clusters[i].size; j++) {
            for (int k = 0; k < MAX_DIMENSIONS; k++) {
                printf("%f ", clusters[i].points[j].coords[k]);
            }
            printf(", ");
        }
        printf("]\n");
    }

    return 0;
}