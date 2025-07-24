//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 5
#define MAX_ITERATIONS 10
#define THRESHOLD 0.01

struct point {
    float x;
    float y;
};

struct cluster {
    struct point centroid;
    struct point points[MAX_POINTS];
    int num_points;
};

float distance(struct point p1, struct point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

struct point calculate_centroid(struct cluster c) {
    int i;
    float sum_x = 0, sum_y = 0;
    for (i = 0; i < c.num_points; i++) {
        sum_x += c.points[i].x;
        sum_y += c.points[i].y;
    }
    struct point centroid = {sum_x/c.num_points, sum_y/c.num_points};
    return centroid;
}

void assign_points_to_clusters(struct cluster clusters[], int num_clusters, struct point points[], int num_points) {
    int i, j;
    float min_distance, distance_to_point;
    int assigned_cluster;
    for (i = 0; i < num_points; i++) {
        min_distance = INFINITY;
        for (j = 0; j < num_clusters; j++) {
            distance_to_point = distance(clusters[j].centroid, points[i]);
            if (distance_to_point < min_distance) {
                min_distance = distance_to_point;
                assigned_cluster = j;
            }
        }
        clusters[assigned_cluster].points[clusters[assigned_cluster].num_points] = points[i];
        clusters[assigned_cluster].num_points++;
    }
}

float recalculate_centroids(struct cluster clusters[], int num_clusters) {
    int i;
    float old_distance, new_distance = 0;
    struct point old_centroid;
    for (i = 0; i < num_clusters; i++) {
        old_centroid = clusters[i].centroid;
        clusters[i].centroid = calculate_centroid(clusters[i]);
        new_distance += distance(old_centroid, clusters[i].centroid);
    }
    return new_distance;
}

void print_clusters(struct cluster clusters[], int num_clusters) {
    int i, j;
    printf("Clusters:\n");
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points:\n");
        for (j = 0; j < clusters[i].num_points; j++) {
            printf("(%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

int main() {
    struct point points[MAX_POINTS] = {{2, 10}, {2, 5}, {8, 4}, {5, 8}, {7, 5}, {6, 4}, {1, 2}, {4, 9}};
    struct cluster clusters[MAX_CLUSTERS];
    int num_points = 8, num_clusters = 2, i, j;
    float distance_difference, total_distance_difference;
    for (i = 0; i < num_clusters; i++) {
        clusters[i].centroid = points[i];
        clusters[i].num_points = 0;
    }
    assign_points_to_clusters(clusters, num_clusters, points, num_points);
    for (i = 0; i < MAX_ITERATIONS; i++) {
        total_distance_difference = recalculate_centroids(clusters, num_clusters);
        for (j = 0; j < num_clusters; j++) {
            clusters[j].num_points = 0;
        }
        assign_points_to_clusters(clusters, num_clusters, points, num_points);
        if (total_distance_difference < THRESHOLD) {
            break;
        }
    }
    print_clusters(clusters, num_clusters);
    return 0;
}