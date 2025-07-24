//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100
#define NUM_CLUSTERS 5

struct Point {
    double x, y;
};

struct Cluster {
    int id;
    struct Point centroid;
    int num_points;
    struct Point points[NUM_POINTS];
};

double distance(struct Point a, struct Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initialize_points(struct Point *points) {
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
}

void initialize_clusters(struct Cluster *clusters) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].id = i;
        clusters[i].centroid.x = rand() % 100;
        clusters[i].centroid.y = rand() % 100;
        clusters[i].num_points = 0;
    }
}

void assign_points_to_clusters(struct Point *points, struct Cluster *clusters) {
    for (int i = 0; i < NUM_POINTS; i++) {
        double min_distance = INFINITY;
        int min_cluster_index = -1;
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            double d = distance(points[i], clusters[j].centroid);
            if (d < min_distance) {
                min_distance = d;
                min_cluster_index = j;
            }
        }
        clusters[min_cluster_index].points[clusters[min_cluster_index].num_points] = points[i];
        clusters[min_cluster_index].num_points++;
    }
}

void compute_new_centroids(struct Cluster *clusters) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        double sum_x = 0;
        double sum_y = 0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].num_points;
        clusters[i].centroid.y = sum_y / clusters[i].num_points;
    }
}

void print_clusters(struct Cluster *clusters) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d\n", clusters[i].id);
        printf("Centroid (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points: ");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

int main() {
    srand(42);

    struct Point points[NUM_POINTS];
    initialize_points(points);

    struct Cluster clusters[NUM_CLUSTERS];
    initialize_clusters(clusters);

    for (int i = 0; i < 10; i++) {
        printf("Iteration %d\n", i);
        assign_points_to_clusters(points, clusters);
        compute_new_centroids(clusters);
        print_clusters(clusters);
    }

    return 0;
}