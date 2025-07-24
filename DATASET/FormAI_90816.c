//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define MAX_CLUSTERS 10

struct Point {
    double *coords;
    int cluster;
};

struct Cluster {
    double *centroid;
    int size;
    struct Point *points;
};

double euclidean_distance(double *a, double *b, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow((a[i] - b[i]), 2);
    }
    return sqrt(sum);
}

void print_clusters(struct Cluster *clusters, int num_clusters, int num_dims) {
    printf("Clusters:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d centroid: [ ", i + 1);
        for (int j = 0; j < num_dims; j++) {
            printf("%.2f ", clusters[i].centroid[j]);
        }
        printf("]\n");
        printf("Points in cluster %d:\n", i + 1);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("[ ");
            for (int k = 0; k < num_dims; k++) {
                printf("%.2f ", clusters[i].points[j].coords[k]);
            }
            printf("]\n");
        }
    }
}

void kmeans(struct Point *points, int num_points, int num_clusters, int num_dims) {
    struct Cluster clusters[MAX_CLUSTERS];
    int done = 0;
    int iterations = 0;

    // Initialize the clusters with random centroids
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid = (double *) malloc(num_dims * sizeof(double));
        for (int j = 0; j < num_dims; j++) {
            clusters[i].centroid[j] = points[rand() % num_points].coords[j];
        }
        clusters[i].size = 0;
        clusters[i].points = NULL;
    }

    while (!done && iterations < MAX_ITERATIONS) {
        // Assign each point to the closest cluster
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            for (int j = 0; j < num_clusters; j++) {
                double distance = euclidean_distance(points[i].coords, clusters[j].centroid, num_dims);
                if (distance < min_distance) {
                    min_distance = distance;
                    points[i].cluster = j;
                }
            }
        }

        // Recalculate the centroids of each cluster
        for (int i = 0; i < num_clusters; i++) {
            for (int j = 0; j < num_dims; j++) {
                clusters[i].centroid[j] = 0;
            }
            clusters[i].size = 0;
            clusters[i].points = (struct Point *) malloc(num_points * sizeof(struct Point));
        }

        for (int i = 0; i < num_points; i++) {
            int cluster_index = points[i].cluster;
            clusters[cluster_index].size++;
            clusters[cluster_index].points = (struct Point *) realloc(clusters[cluster_index].points, clusters[cluster_index].size * sizeof(struct Point));
            clusters[cluster_index].points[clusters[cluster_index].size - 1] = points[i];
            for (int j = 0; j < num_dims; j++) {
                clusters[cluster_index].centroid[j] += points[i].coords[j];
            }
        }

        for (int i = 0; i < num_clusters; i++) {
            if (clusters[i].size > 0) {
                for (int j = 0; j < num_dims; j++) {
                    clusters[i].centroid[j] /= clusters[i].size;
                }
            }
        }

        // Check if the clusters have converged
        done = 1;
        for (int i = 0; i < num_clusters; i++) {
            double distance = euclidean_distance(clusters[i].centroid, points[0].coords, num_dims);
            for (int j = 0; j < num_points; j++) {
                if (points[j].cluster != i) {
                    continue;
                }
                double new_distance = euclidean_distance(clusters[i].centroid, points[j].coords, num_dims);
                if (new_distance != distance) {
                    done = 0;
                    break;
                }
            }
            if (!done) {
                break;
            }
        }

        iterations++;
    }

    print_clusters(clusters, num_clusters, num_dims);
}

int main() {
    // Read in data points and number of clusters
    int num_points, num_dims, num_clusters;
    scanf("%d %d %d", &num_points, &num_dims, &num_clusters);

    struct Point points[num_points];

    for (int i = 0; i < num_points; i++) {
        points[i].coords = (double *) malloc(num_dims * sizeof(double));
        for (int j = 0; j < num_dims; j++) {
            scanf("%lf", &points[i].coords[j]);
        }
    }

    kmeans(points, num_points, num_clusters, num_dims);

    // Free memory
    for (int i = 0; i < num_points; i++) {
        free(points[i].coords);
    }

    return 0;
}