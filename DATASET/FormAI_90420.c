//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIMENSIONS 2
#define NUM_POINTS 100
#define CLUSTER_SIZE 20
#define COORDINATE_RANGE 100

double euclidean_distance(double* point_one, double* point_two) {
    double dist = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        dist += pow(point_two[i] - point_one[i], 2);
    }
    return sqrt(dist);
}

int main() {
    srand(time(NULL));
    double data[NUM_POINTS][DIMENSIONS];
    // initialize data randomly
    for (int i = 0; i < NUM_POINTS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            data[i][j] = rand() % COORDINATE_RANGE;
        }
    }
    int num_clusters = NUM_POINTS / CLUSTER_SIZE;
    double centroids[num_clusters][DIMENSIONS];
    // randomly select initial centroids
    for (int i = 0; i < num_clusters; i++) {
        int cluster_start = i * CLUSTER_SIZE;
        for (int j = 0; j < DIMENSIONS; j++) {
            double sum = 0.0;
            for (int k = cluster_start; k < cluster_start + CLUSTER_SIZE; k++) {
                sum += data[k][j];
            }
            centroids[i][j] = sum / CLUSTER_SIZE;
        }
    }
    // create array to store cluster for each point
    int cluster_assignments[NUM_POINTS];
    // iterate until cluster assignments converge
    int num_iterations = 0;
    double distance_threshold = 0.1;
    while (1) {
        // assign points to clusters
        for (int i = 0; i < NUM_POINTS; i++) {
            double min_distance = INFINITY;
            int min_cluster = -1;
            for (int j = 0; j < num_clusters; j++) {
                double distance = euclidean_distance(data[i], centroids[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_cluster = j;
                }
            }
            cluster_assignments[i] = min_cluster;
        }
        // calculate new centroids
        int num_points_assigned[num_clusters];
        for (int i = 0; i < num_clusters; i++) {
            for (int j = 0; j < DIMENSIONS; j++) {
                centroids[i][j] = 0.0;
            }
            num_points_assigned[i] = 0;
        }
        for (int i = 0; i < NUM_POINTS; i++) {
            int assigned_cluster = cluster_assignments[i];
            for (int j = 0; j < DIMENSIONS; j++) {
                centroids[assigned_cluster][j] += data[i][j];
            }
            num_points_assigned[assigned_cluster]++;
        }
        int any_changes = 0;
        for (int i = 0; i < num_clusters; i++) {
            if (num_points_assigned[i] > 0) {
                for (int j = 0; j < DIMENSIONS; j++) {
                    centroids[i][j] /= num_points_assigned[i];
                }
                double distance_to_old_centroid = euclidean_distance(data[i * CLUSTER_SIZE], centroids[i]);
                if (distance_to_old_centroid > distance_threshold) {
                    any_changes = 1;
                }
            }
        }
        if (!any_changes) {
            break;
        }
        num_iterations++;
    }
    printf("Number of iterations: %d\n", num_iterations);
    // print cluster assignments
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("Point %d assigned to cluster %d\n", i, cluster_assignments[i]);
    }
    return 0;
}