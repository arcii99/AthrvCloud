//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Number of data points
#define N 100

// Number of clusters
#define K 4

// Maximum number of iterations
#define MAX_ITER 100

// Data point structure
typedef struct Point {
    double x, y;
} Point;

// Cluster structure
typedef struct Cluster {
    Point centroid;
    int count;
    Point points[N];
} Cluster;

// Compute Euclidean distance between two points
double distance(Point a, Point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

// Initialize clusters randomly
void init_clusters(Point points[N], Cluster clusters[K]) {
    int i, j, r;

    // Randomly select 'K' points to be the initial centroids
    for (i = 0; i < K; i++) {
        r = rand() % N;
        clusters[i].centroid = points[r];
    }

    // Initialize counts and points for each cluster
    for (i = 0; i < K; i++) {
        clusters[i].count = 0;
        for (j = 0; j < N; j++) {
            clusters[i].points[j] = (Point) {0.0, 0.0};
        }
    }
}

// Assign each point to the nearest cluster
void assign_points(Point points[N], Cluster clusters[K]) {
    int i, j, min_index;
    double min_distance, dist;

    for (i = 0; i < N; i++) {
        min_distance = INFINITY;
        for (j = 0; j < K; j++) {
            dist = distance(points[i], clusters[j].centroid);
            if (dist < min_distance) {
                min_distance = dist;
                min_index = j;
            }
        }
        clusters[min_index].points[clusters[min_index].count++] = points[i];
    }
}

// Update cluster centroids
void update_centroids(Cluster clusters[K]) {
    int i, j;

    for (i = 0; i < K; i++) {
        double sum_x = 0.0, sum_y = 0.0;
        for (j = 0; j < clusters[i].count; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].count;
        clusters[i].centroid.y = sum_y / clusters[i].count;
    }
}

// Print cluster information
void print_clusters(Cluster clusters[K]) {
    int i, j;

    for (i = 0; i < K; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid: (%.2lf, %.2lf)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points:\n");
        for (j = 0; j < clusters[i].count; j++) {
            printf("\t(%.2lf, %.2lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Generate random points
    Point points[N];
    int i;
    for (i = 0; i < N; i++) {
        points[i].x = (double) rand() / RAND_MAX;
        points[i].y = (double) rand() / RAND_MAX;
    }

    // Initialize clusters
    Cluster clusters[K];
    init_clusters(points, clusters);

    // Perform clustering
    int iter = 0;
    while (iter < MAX_ITER) {
        assign_points(points, clusters);
        update_centroids(clusters);
        iter++;
    }

    // Print cluster information
    print_clusters(clusters);

    return 0;
}