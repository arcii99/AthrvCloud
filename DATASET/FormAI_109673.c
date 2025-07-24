//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Linus Torvalds
/*
 * This is my implementation of a clustering algorithm. I call it "TORVALDS CLUSTERING".
 * It is meant for use in Linux systems, hence the name. It's efficient and fast - just like 
 * the Linux kernel.
 *
 * Written by [YOUR NAME HERE] for [YOUR COMPANY/UNIVERSITY HERE]
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_POINTS 10000
#define MAX_DIMENSIONS 100
#define MAX_CLUSTERS 50

typedef struct {
    double point[MAX_DIMENSIONS];
    uint32_t id; 
} data_point_t;

typedef struct {
    data_point_t center;
    uint32_t count;
} cluster_t;

cluster_t clusters[MAX_CLUSTERS];
data_point_t data_points[MAX_POINTS];
uint32_t num_clusters = 3;
uint32_t num_points = 1000;
uint32_t num_dimensions = 2;
uint32_t max_iterations = 100;

double distance(data_point_t *p1, data_point_t *p2) {
    double dist = 0;
    for (uint32_t i = 0; i < num_dimensions; i++) {
        dist += (p1->point[i] - p2->point[i]) * (p1->point[i] - p2->point[i]);
    }
    return dist;
}

void init_clusters() {
    for (uint32_t i = 0; i < num_clusters; i++) {
        for (uint32_t j = 0; j < num_dimensions; j++) {
            clusters[i].center.point[j] = (double)rand() / RAND_MAX;
        }
        clusters[i].count = 0;
    }
}

uint32_t assign_cluster(data_point_t *point) {
    uint32_t min_cluster = 0;
    double min_distance = distance(point, &clusters[0].center);

    for (uint32_t i = 1; i < num_clusters; i++) {
        double dist = distance(point, &clusters[i].center);
        if (dist < min_distance) {
            min_cluster = i;
            min_distance = dist;
        }
    }

    return min_cluster;
}

void update_clusters() {
    for (uint32_t i = 0; i < num_clusters; i++) {
        for (uint32_t j = 0; j < num_dimensions; j++) {
            clusters[i].center.point[j] = 0;
        }
        clusters[i].count = 0;
    }

    for (uint32_t i = 0; i < num_points; i++) {
        uint32_t cluster_id = data_points[i].id;
        for (uint32_t j = 0; j < num_dimensions; j++) {
            clusters[cluster_id].center.point[j] += data_points[i].point[j];
        }
        clusters[cluster_id].count++;
    }

    for (uint32_t i = 0; i < num_clusters; i++) {
        if (clusters[i].count > 0) {
            for (uint32_t j = 0; j < num_dimensions; j++) {
                clusters[i].center.point[j] /= clusters[i].count;
            }
        }
    }
}

void torvalds_cluster() {
    init_clusters();

    for (uint32_t iter = 0; iter < max_iterations; iter++) {
        for (uint32_t i = 0; i < num_points; i++) {
            data_points[i].id = assign_cluster(&data_points[i]);
        }

        update_clusters();
    }
}

int main(int argc, char **argv) {
    srand(42);

    for (uint32_t i = 0; i < num_points; i++) {
        for (uint32_t j = 0; j < num_dimensions; j++) {
            data_points[i].point[j] = (double)rand() / RAND_MAX;
        }
    }

    torvalds_cluster();

    for (uint32_t i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("\tCenter: ");
        for (uint32_t j = 0; j < num_dimensions; j++) {
            printf("%f ", clusters[i].center.point[j]);
        }
        printf("\n");
        printf("\tCount: %d\n", clusters[i].count);
    }

    return 0;
}