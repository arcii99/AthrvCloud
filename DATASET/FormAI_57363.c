//FormAI DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 3
#define NUM_DATA_POINTS 16
#define NUM_CLUSTERS 3
#define MAX_ITERATIONS 10

// Define a struct to represent a data point
typedef struct {
    double coordinates[DIMENSIONS];
} DataPoint;

// Define a struct to represent a cluster
typedef struct {
    DataPoint centroid;
    int num_points;
    DataPoint *points;
} Cluster;

// Define a function to calculate the Euclidean distance between two data points
double euclidean_distance(DataPoint *p1, DataPoint *p2) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        double diff = p1->coordinates[i] - p2->coordinates[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

// Define a function to randomly initialize the clusters
void initialize_clusters(DataPoint *data, Cluster *clusters) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].centroid = data[rand() % NUM_DATA_POINTS];
        clusters[i].num_points = 0;
        clusters[i].points = (DataPoint *) malloc(NUM_DATA_POINTS * sizeof(DataPoint));
    }
}

// Define a function to assign each data point to the nearest cluster
void assign_to_clusters(DataPoint *data, Cluster *clusters) {
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        int min_index = 0;
        double min_distance = euclidean_distance(&data[i], &clusters[min_index].centroid);
        for (int j = 1; j < NUM_CLUSTERS; j++) {
            double distance = euclidean_distance(&data[i], &clusters[j].centroid);
            if (distance < min_distance) {
                min_index = j;
                min_distance = distance;
            }
        }
        clusters[min_index].points[clusters[min_index].num_points++] = data[i];
    }
}

// Define a function to update the centroids of the clusters
int update_cluster_centroids(Cluster *clusters) {
    int some_changed = 0;
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        if (clusters[i].num_points == 0) continue;
        DataPoint sum = {0};
        for (int j = 0; j < clusters[i].num_points; j++) {
            for (int k = 0; k < DIMENSIONS; k++) {
                sum.coordinates[k] += clusters[i].points[j].coordinates[k];
            }
        }
        DataPoint new_centroid;
        for (int k = 0; k < DIMENSIONS; k++) {
            new_centroid.coordinates[k] = sum.coordinates[k] / clusters[i].num_points;
        }
        if (euclidean_distance(&new_centroid, &clusters[i].centroid) > 1e-6) {
            some_changed = 1;
            clusters[i].centroid = new_centroid;
        }
    }
    return some_changed;
}

// Define a function to print the clusters
void print_clusters(Cluster *clusters) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster #%d:\n", i);
        printf("\tCentroid: (%f, %f, %f)\n", clusters[i].centroid.coordinates[0],
                clusters[i].centroid.coordinates[1], clusters[i].centroid.coordinates[2]);
        printf("\tPoints: { ");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f, %f) ", clusters[i].points[j].coordinates[0],
                    clusters[i].points[j].coordinates[1], clusters[i].points[j].coordinates[2]);
        }
        printf("}\n");
    }
}

// Define the main function
int main() {
    DataPoint data[NUM_DATA_POINTS] = {
        {1.0, 1.0, 1.0},
        {1.5, 2.0, 2.0},
        {3.0, 4.0, 4.0},
        {5.0, 7.0, 7.0},
        {3.5, 5.0, 5.0},
        {4.5, 5.0, 5.0},
        {3.5, 4.5, 4.5},
        {4.5, 4.5, 4.5},
        {5.0, 4.5, 4.5},
        {4.0, 4.0, 4.0},
        {2.0, 3.0, 3.0},
        {3.0, 3.0, 3.0},
        {3.5, 2.5, 2.5},
        {2.5, 2.0, 2.0},
        {3.0, 2.0, 2.0},
        {2.0, 1.0, 1.0}
    };
    Cluster clusters[NUM_CLUSTERS];
    initialize_clusters(data, clusters);
    int iterations = 0;
    while (update_cluster_centroids(clusters) && iterations < MAX_ITERATIONS) {
        for (int i = 0; i < NUM_CLUSTERS; i++) {
            clusters[i].num_points = 0;
        }
        assign_to_clusters(data, clusters);
        iterations++;
    }
    printf("Final clusters after %d iterations:\n", iterations);
    print_clusters(clusters);
    return 0;
}