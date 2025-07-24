//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_K 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    int num_points;
    Point centroid;
    Point *points;
} Cluster;

void calc_centroid(Cluster *cluster) {
    double sum_x = 0.0;
    double sum_y = 0.0;

    for (int i = 0; i < cluster->num_points; i++) {
        sum_x += cluster->points[i].x;
        sum_y += cluster->points[i].y;
    }

    cluster->centroid.x = sum_x / (double)cluster->num_points;
    cluster->centroid.y = sum_y / (double)cluster->num_points;
}

double distance(Point p1, Point p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;

    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int main() {
    // Generate random points
    Point points[MAX_POINTS];
    for (int i = 0; i < MAX_POINTS; i++) {
        points[i].x = (double)rand() / (double)RAND_MAX * 100.0;
        points[i].y = (double)rand() / (double)RAND_MAX * 100.0;
    }

    // Initialize clusters
    Cluster clusters[MAX_K];
    for (int i = 0; i < MAX_K; i++) {
        int random_point_index = rand() % MAX_POINTS;

        clusters[i].num_points = 0;
        clusters[i].centroid = points[random_point_index];
        clusters[i].points = malloc(sizeof(Point) * MAX_POINTS);
    }

    // Assign points to clusters
    for (int i = 0; i < MAX_POINTS; i++) {
        Point current_point = points[i];
        double min_dist = INFINITY;
        int closest_cluster = -1;

        for (int j = 0; j < MAX_K; j++) {
            Cluster current_cluster = clusters[j];
            double dist = distance(current_point, current_cluster.centroid);

            if (dist < min_dist) {
                min_dist = dist;
                closest_cluster = j;
            }
        }

        Cluster assigned_cluster = clusters[closest_cluster];
        assigned_cluster.points[assigned_cluster.num_points++] = current_point;
        calc_centroid(&assigned_cluster);
        clusters[closest_cluster] = assigned_cluster;
    }

    // Print cluster info
    for (int i = 0; i < MAX_K; i++) {
        Cluster current_cluster = clusters[i];

        printf("===================\n");
        printf("Cluster %d:\n", i);

        for (int j = 0; j < current_cluster.num_points; j++) {
            printf("Point (%f, %f)\n", current_cluster.points[j].x, current_cluster.points[j].y);
        }

        printf("Centroid: (%f, %f)\n", current_cluster.centroid.x, current_cluster.centroid.y);
    }

    // Free memory
    for (int i = 0; i < MAX_K; i++) {
        free(clusters[i].points);
    }

    return 0;
}