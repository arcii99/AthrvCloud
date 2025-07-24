//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_POINTS 1000
#define NUM_CLUSTERS 5
#define DIMENSIONS 2

float points[NUM_POINTS][DIMENSIONS];
int belongs_to_cluster[NUM_POINTS];

typedef struct cluster {
    float centroid[DIMENSIONS];
    int num_points;
    float points[NUM_POINTS][DIMENSIONS];
} Cluster;

Cluster clusters[NUM_CLUSTERS];

void generate_points() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < NUM_POINTS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            points[i][j] = (float)rand() / RAND_MAX;
        }
    }
}

void init_clusters() {
    int i, j, k;
    for (i = 0; i < NUM_CLUSTERS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid[j] = (float)rand() / RAND_MAX;
        }
        clusters[i].num_points = 0;
        for (k = 0; k < NUM_POINTS; k++) {
            clusters[i].points[k][0] = -1;
            clusters[i].points[k][1] = -1;
        }
    }
}

float distance(float *p1, float *p2) {
    float dist = 0;
    int i;
    for (i = 0; i < DIMENSIONS; i++) {
        dist += pow(p1[i] - p2[i], 2);
    }
    return sqrt(dist);
}

void assign_points_to_clusters() {
    int i, j;
    for (i = 0; i < NUM_POINTS; i++) {
        float min_dist = INFINITY;
        for (j = 0; j < NUM_CLUSTERS; j++) {
            float dist = distance(points[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                belongs_to_cluster[i] = j;
            }
        }
        clusters[belongs_to_cluster[i]].points[clusters[belongs_to_cluster[i]].num_points][0] = points[i][0];
        clusters[belongs_to_cluster[i]].points[clusters[belongs_to_cluster[i]].num_points][1] = points[i][1];
        clusters[belongs_to_cluster[i]].num_points++;
    }
}

void update_centroids() {
    int i, j, k;
    for (i = 0; i < NUM_CLUSTERS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            float sum = 0;
            for (k = 0; k < clusters[i].num_points; k++) {
                sum += clusters[i].points[k][j];
            }
            if (clusters[i].num_points > 0) {
                clusters[i].centroid[j] = sum / clusters[i].num_points;
            } else {
                clusters[i].centroid[j] = (float)rand() / RAND_MAX;
            }
        }
        clusters[i].num_points = 0;
        for (k = 0; k < NUM_POINTS; k++) {
            clusters[i].points[k][0] = -1;
            clusters[i].points[k][1] = -1;
        }
    }
}

int main() {
    generate_points();
    init_clusters();
    int i;
    for (i = 0; i < 10; i++) {
        assign_points_to_clusters();
        update_centroids();
    }
    for (i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d centroid: (%f, %f)\n", i, clusters[i].centroid[0], clusters[i].centroid[1]);
    }
    return 0;
}