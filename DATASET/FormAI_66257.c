//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100
#define NUM_CLUSTERS 3

void initialize_points(double points[]);
void initialize_centroids(double centroids[]);
int find_nearest_cluster(double point, double centroids[], int num_clusters);
void recompute_centroids(double points[], double centroids[], int cluster_counts[]);
void print_results(double points[], double centroids[], int cluster_assignments[]);

int main() {
    double points[NUM_POINTS];
    double centroids[NUM_CLUSTERS];
    int cluster_assignments[NUM_POINTS];
    int cluster_counts[NUM_CLUSTERS] = {0};

    // initialize points and centroids
    initialize_points(points);
    initialize_centroids(centroids);
    
    // perform clustering iterations
    int updated_cluster = 1;
    while (updated_cluster == 1) {
        updated_cluster = 0;
        for (int i = 0; i < NUM_POINTS; i++) {
            int cluster_assignment = find_nearest_cluster(points[i], centroids, NUM_CLUSTERS);
            if (cluster_assignment != cluster_assignments[i]) {
                cluster_assignments[i] = cluster_assignment;
                updated_cluster = 1;
            }
            cluster_counts[cluster_assignment]++;
        }
        recompute_centroids(points, centroids, cluster_counts);
    }

    // print final results
    print_results(points, centroids, cluster_assignments);

    return 0;
}

void initialize_points(double points[]) {
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i] = ((double) rand() / (double) RAND_MAX) * 100.0;
    }
}

void initialize_centroids(double centroids[]) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        centroids[i] = ((double) rand() / (double) RAND_MAX) * 100.0;
    }
}

int find_nearest_cluster(double point, double centroids[], int num_clusters) {
    double min_distance = INFINITY;
    int closest_cluster = -1;
    for (int i = 0; i < num_clusters; i++) {
        double distance = fabs(point - centroids[i]);
        if (distance < min_distance) {
            min_distance = distance;
            closest_cluster = i;
        }
    }
    return closest_cluster;
}

void recompute_centroids(double points[], double centroids[], int cluster_counts[]) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        double sum = 0.0;
        for (int j = 0; j < NUM_POINTS; j++) {
            if (find_nearest_cluster(points[j], centroids, NUM_CLUSTERS) == i) {
                sum += points[j];
            }
        }
        if (cluster_counts[i] > 0) {
            centroids[i] = sum / (double) cluster_counts[i];
        }
    }
}

void print_results(double points[], double centroids[], int cluster_assignments[]) {
    // print points with their corresponding cluster
    printf("Cluster assignments:\n");
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("Point %d assigned to cluster %d\n", i, cluster_assignments[i]);
    }
    printf("\n");

    // print final centroids
    printf("Final Centroids:\n");
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d centroid: %.2f\n", i, centroids[i]);
    }
}