//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 2
#define NUM_POINTS 20
#define NUM_CLUSTERS 3
#define ITERATIONS 100

struct Point {
    double coords[DIMENSIONS];
};

struct Cluster {
    struct Point centroid;
    struct Point *points;
    int num_points;
};

double dist(struct Point p1, struct Point p2) {
    double total = 0;
    for (int i = 0; i < DIMENSIONS; i++) {
        double diff = p1.coords[i] - p2.coords[i];
        total += diff * diff;
    }
    return sqrt(total);
}

void update_centroids(struct Cluster *clusters) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        struct Cluster *cluster = &clusters[i];
        for (int j = 0; j < DIMENSIONS; j++) {
            double total = 0;
            for (int k = 0; k < cluster->num_points; k++) {
                total += cluster->points[k].coords[j];
            }
            cluster->centroid.coords[j] = total / cluster->num_points;
        }
    }
}

int main() {
    srand(0);
    struct Point points[NUM_POINTS];
    for (int i = 0; i < NUM_POINTS; i++) {
        struct Point point;
        for (int j = 0; j < DIMENSIONS; j++) {
            point.coords[j] = (double)rand() / RAND_MAX;
        }
        points[i] = point;
    }

    struct Cluster clusters[NUM_CLUSTERS];
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        struct Cluster cluster;
        cluster.centroid = points[rand() % NUM_POINTS];
        clusters[i] = cluster;
    }

    for (int i = 0; i < ITERATIONS; i++) {
        // assign points to clusters based on distance
        for (int j = 0; j < NUM_POINTS; j++) {
            double min_dist = INFINITY;
            int min_cluster_idx = 0;
            for (int k = 0; k < NUM_CLUSTERS; k++) {
                double d = dist(points[j], clusters[k].centroid);
                if (d < min_dist) {
                    min_dist = d;
                    min_cluster_idx = k;
                }
            }
            clusters[min_cluster_idx].num_points++;
        }

        // allocate memory for each cluster's points
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            struct Point *points = (struct Point *)malloc(sizeof(struct Point) * clusters[j].num_points);
            clusters[j].points = points;
            clusters[j].num_points = 0;
        }

        // assign points to clusters based on distance
        for (int j = 0; j < NUM_POINTS; j++) {
            double min_dist = INFINITY;
            int min_cluster_idx = 0;
            for (int k = 0; k < NUM_CLUSTERS; k++) {
                double d = dist(points[j], clusters[k].centroid);
                if (d < min_dist) {
                    min_dist = d;
                    min_cluster_idx = k;
                }
            }
            clusters[min_cluster_idx].points[clusters[min_cluster_idx].num_points++] = points[j];
        }

        // update centroids
        update_centroids(clusters);

        // free memory for each cluster's previous points
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            free(clusters[j].points);
        }
    }

    // print final clusters
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            struct Point point = clusters[i].points[j];
            printf("(%f, %f)\n", point.coords[0], point.coords[1]);
        }
    }

    return 0;
}