//FormAI DATASET v1.0 Category: Data mining ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTERS 10
#define MAX_SAMPLES 1000

typedef struct {
    double x, y, z;
} point_t;

typedef struct {
    point_t centroid;
    point_t samples[MAX_SAMPLES];
    int num_samples;
} cluster_t;

int main(int argc, char **argv) {
    int k = 3; // number of clusters
    int num_points = 1000;
    point_t points[num_points];
    cluster_t clusters[MAX_CLUSTERS];

    // Init points randomly
    for (int i = 0; i < num_points; i++) {
        points[i].x = (double)rand() / RAND_MAX;
        points[i].y = (double)rand() / RAND_MAX;
        points[i].z = (double)rand() / RAND_MAX;
    }

    // Init clusters centroids randomly
    for (int i = 0; i < k; i++) {
        clusters[i].centroid.x = (double)rand() / RAND_MAX;
        clusters[i].centroid.y = (double)rand() / RAND_MAX;
        clusters[i].centroid.z = (double)rand() / RAND_MAX;
    }

    // k-means clustering algorithm
    for (int iter = 0; iter < 100; iter++) {
        // Assign points to nearest cluster
        for (int i = 0; i < num_points; i++) {
            double min_dist = INFINITY;
            int min_cluster = -1;
            for (int j = 0; j < k; j++) {
                double dx = points[i].x - clusters[j].centroid.x;
                double dy = points[i].y - clusters[j].centroid.y;
                double dz = points[i].z - clusters[j].centroid.z;
                double dist = sqrt(dx*dx + dy*dy + dz*dz);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_cluster = j;
                }
            }
            clusters[min_cluster].samples[clusters[min_cluster].num_samples++] = points[i];
        }

        // Recalculate centroids
        for (int i = 0; i < k; i++) {
            double sum_x = 0.0, sum_y = 0.0, sum_z = 0.0;
            for (int j = 0; j < clusters[i].num_samples; j++) {
                sum_x += clusters[i].samples[j].x;
                sum_y += clusters[i].samples[j].y;
                sum_z += clusters[i].samples[j].z;
            }
            clusters[i].centroid.x = sum_x / clusters[i].num_samples;
            clusters[i].centroid.y = sum_y / clusters[i].num_samples;
            clusters[i].centroid.z = sum_z / clusters[i].num_samples;
            clusters[i].num_samples = 0;
        }
    }

    // Print results
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: \n", i);
        printf("\tCentroid: (%f, %f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y, clusters[i].centroid.z);
        printf("\tSamples:\n");
        for (int j = 0; j < clusters[i].num_samples; j++) {
            printf("\t(%f, %f, %f)\n", clusters[i].samples[j].x, clusters[i].samples[j].y, clusters[i].samples[j].z);
        }
    }

    return 0;
}