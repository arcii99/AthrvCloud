//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

int num_clusters = 3; // Default number of clusters
int num_points = 15; // Default number of data points

typedef struct {
    double x;
    double y;
    int cluster;
    double distance;
} point;

point points[MAX_POINTS];

double euclidean_distance(point p1, point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

double get_distance(point p, point centroid) {
    return euclidean_distance(p, centroid);
}

void assign_clusters(point* points, int num_points, point* centroids, int num_clusters) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        for (int j = 0; j < num_clusters; j++) {
            double dist = get_distance(points[i], centroids[j]);
            if (dist < min_distance) {
                min_distance = dist;
                points[i].cluster = j;
            }
        }
        points[i].distance = min_distance;
    }
}

void recalculate_centroids(point* points, int num_points, point* centroids, int num_clusters) {
    double total_x[num_clusters];
    double total_y[num_clusters];

    for (int i = 0; i < num_clusters; i++) {
        int count = 0;
        for (int j = 0; j < num_points; j++) {
            if (points[j].cluster == i) {
                total_x[i] += points[j].x;
                total_y[i] += points[j].y;
                count++;
            }
        }
        if (count > 0) {
            centroids[i].x = total_x[i] / count;
            centroids[i].y = total_y[i] / count;
        }
    }
}

void print_clusters(point* points, int num_points, point* centroids, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: Centroid at (%.2f, %.2f)\n", i, centroids[i].x, centroids[i].y);
        for (int j = 0; j < num_points; j++) {
            if (points[j].cluster == i) {
                printf("   (%.2f, %.2f)\n", points[j].x, points[j].y);
            }
        }
    }
}

void cluster_points() {
    point centroids[num_clusters];
    for (int i = 0; i < num_clusters; i++) {
        centroids[i].x = (double)rand() / RAND_MAX;
        centroids[i].y = (double)rand() / RAND_MAX;
        centroids[i].cluster = i;
    }

    assign_clusters(points, num_points, centroids, num_clusters);

    double prev_distance_sum = 0.0;
    double curr_distance_sum = -1.0;

    while (prev_distance_sum != curr_distance_sum) {
        prev_distance_sum = curr_distance_sum;
        curr_distance_sum = 0.0;

        recalculate_centroids(points, num_points, centroids, num_clusters);
        assign_clusters(points, num_points, centroids, num_clusters);

        for (int i = 0; i < num_points; i++) {
            curr_distance_sum += points[i].distance;
        }
    }

    print_clusters(points, num_points, centroids, num_clusters);
}

int main() {
    for (int i = 0; i < num_points; i++) {
        points[i].x = (double)rand() / RAND_MAX;
        points[i].y = (double)rand() / RAND_MAX;
    }

    cluster_points();

    return 0;
}