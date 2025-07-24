//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Linus Torvalds
/*
 * Cluster.c
 *
 * A simple C Clustering Algorithm Implementation 
 * inspired by Linus Torvalds' coding style.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

struct point {
    double x, y;
};

struct cluster {
    int size;
    struct point centroid;
    struct point points[MAX_POINTS];
};

double distance(struct point p1, struct point p2) {
    // Euclidean distance formula
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void cluster_init(struct cluster *c) {
    c->size = 0;
    c->centroid.x = 0.0;
    c->centroid.y = 0.0;
}

void cluster_add_point(struct cluster *c, struct point p) {
    c->points[c->size++] = p;
    c->centroid.x += p.x;
    c->centroid.y += p.y;
}

void cluster_compute_centroid(struct cluster *c) {
    if (c->size == 0)
        return;

    c->centroid.x /= (double) c->size;
    c->centroid.y /= (double) c->size;
}

void cluster_assign_points(struct cluster *clusters, int num_clusters, struct point *points, int num_points) {
    int i, j;
    double min_distance, curr_distance;

    for (i = 0; i < num_points; i++) {
        min_distance = distance(points[i], clusters[0].centroid);
        clusters[0].size = 1;
        for (j = 1; j < num_clusters; j++) {
            curr_distance = distance(points[i], clusters[j].centroid);
            if (curr_distance < min_distance) {
                min_distance = curr_distance;
                clusters[j].size++;
            }
        }
        cluster_add_point(&clusters[j], points[i]);
    }
}

void cluster_print(struct cluster cluster) {
    printf("Size: %d\nCentroid: (%.2f, %.2f)\nPoints:\n", 
           cluster.size, cluster.centroid.x, cluster.centroid.y);
    for (int i = 0; i < cluster.size; i++) {
        printf("\t(%.2f, %.2f)\n", cluster.points[i].x, cluster.points[i].y);
    }
}

int main() {
    // Generate random points
    struct point points[MAX_POINTS];
    int num_points = 0;
    srand(1234);
    for (int i = 0; i < MAX_POINTS; i++) {
        points[i].x = (double) rand() / RAND_MAX * 100;
        points[i].y = (double) rand() / RAND_MAX * 100;
        num_points++;
    }

    // Initialize clusters
    struct cluster clusters[3];
    int num_clusters = sizeof(clusters) / sizeof(struct cluster);
    for (int i = 0; i < num_clusters; i++)
        cluster_init(&clusters[i]);

    // Assign points to clusters
    cluster_assign_points(clusters, num_clusters, points, num_points);

    // Compute centroids for each cluster
    for (int i = 0; i < num_clusters; i++)
        cluster_compute_centroid(&clusters[i]);

    // Print clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        cluster_print(clusters[i]);
    }

    return 0;
}