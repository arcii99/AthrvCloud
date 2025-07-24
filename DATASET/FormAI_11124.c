//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIM 2
#define NUM_POINTS 50
#define NUM_CLUSTERS 3
#define MAX_ITERATIONS 1000

typedef struct {
    double coords[DIM];
    int cluster_id;
} Point;

typedef struct {
    int num_points;
    Point *points;
    Point centroid;
} Cluster;

double distance(Point p1, Point p2) {
    double dist_sq = 0;
    for (int i = 0; i < DIM; i++) {
        dist_sq += pow(p1.coords[i] - p2.coords[i], 2);
    }
    return sqrt(dist_sq);
}

void assign_point_to_cluster(Point *p, Cluster *clusters, int num_clusters) {
    double min_distance = INFINITY;
    for (int i = 0; i < num_clusters; i++) {
        double d = distance(*p, clusters[i].centroid);
        if (d < min_distance) {
            min_distance = d;
            p->cluster_id = i;
        }
    }
}

void calculate_centroids(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        double sum_coords[DIM] = {0};
        for (int j = 0; j < clusters[i].num_points; j++) {
            for (int k = 0; k < DIM; k++) {
                sum_coords[k] += clusters[i].points[j].coords[k];
            }
        }
        for (int k = 0; k < DIM; k++) {
            clusters[i].centroid.coords[k] = sum_coords[k] / clusters[i].num_points;
        }
    }
}

void print_clusters(Cluster *clusters, int num_clusters) {
    printf("Clusters:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("\t(%.2f, %.2f)\n", clusters[i].points[j].coords[0], clusters[i].points[j].coords[1]);
        }
        printf("\tCentroid: (%.2f, %.2f)\n", clusters[i].centroid.coords[0], clusters[i].centroid.coords[1]);
    }
}

int main() {
    srand(time(NULL));
    Point points[NUM_POINTS];
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i].coords[0] = (double) rand() / RAND_MAX * 10;
        points[i].coords[1] = (double) rand() / RAND_MAX * 10;
        points[i].cluster_id = -1;
    }
    Cluster clusters[NUM_CLUSTERS];
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].points = malloc(sizeof(Point) * NUM_POINTS / NUM_CLUSTERS);
        clusters[i].num_points = 0;
        clusters[i].centroid.cluster_id = i;
    }
    for (int i = 0; i < NUM_POINTS; i++) {
        assign_point_to_cluster(&points[i], clusters, NUM_CLUSTERS);
        clusters[points[i].cluster_id].points[clusters[points[i].cluster_id].num_points++] = points[i];
    }
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        calculate_centroids(clusters, NUM_CLUSTERS);
        for (int j = 0; j < NUM_POINTS; j++) {
            assign_point_to_cluster(&points[j], clusters, NUM_CLUSTERS);
        }
        int num_changes = 0;
        for (int j = 0; j < NUM_POINTS; j++) {
            int old_cluster_id = points[j].cluster_id;
            assign_point_to_cluster(&points[j], clusters, NUM_CLUSTERS);
            if (old_cluster_id != points[j].cluster_id) {
                num_changes++;
                clusters[old_cluster_id].num_points--;
                clusters[points[j].cluster_id].points[clusters[points[j].cluster_id].num_points++] = points[j];
            }
        }
        if (num_changes == 0) {
            break;
        }
    }
    print_clusters(clusters, NUM_CLUSTERS);
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        free(clusters[i].points);
    }
    return 0;
}