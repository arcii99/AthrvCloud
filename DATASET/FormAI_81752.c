//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3
#define N 10

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point centroid;
    Point points[N];
    int count;
} Cluster;

float distance(Point p1, Point p2);
void initialize_clusters(Cluster clusters[]);
void print_clusters(Cluster clusters[]);
int assign_points(Cluster clusters[]);
void update_centroids(Cluster clusters[]);

int main() {
    int i, j, iterations = 0;
    int converged = 0;
    Cluster clusters[K];

    initialize_clusters(clusters);

    while (!converged) {
        iterations++;

        // Assign points to clusters
        if (assign_points(clusters) == 0) {
            converged = 1;
        }

        // Update centroids
        update_centroids(clusters);
    }

    printf("Iterations: %d\n", iterations);
    print_clusters(clusters);

    return 0;
}

// Calculate Euclidean distance between two points
float distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Initialize clusters with random centroids
void initialize_clusters(Cluster clusters[]) {
    int i, j, idx;
    float x, y;

    // Initialize random centroids
    for (i = 0; i < K; i++) {
        idx = rand() % N;
        clusters[i].centroid = clusters[i].points[idx];
        clusters[i].count = 0;
    }
}

// Assign each point to the nearest cluster
int assign_points(Cluster clusters[]) {
    int i, j, k;
    float min_distance, cur_distance;
    int cluster_idx;
    int changed = 0;

    for (i = 0; i < K; i++) {
        clusters[i].count = 0;
    }

    for (i = 0; i < N; i++) {
        min_distance = INFINITY;

        for (j = 0; j < K; j++) {
            cur_distance = distance(clusters[j].centroid, clusters[j].points[i]);

            if (cur_distance < min_distance) {
                min_distance = cur_distance;
                cluster_idx = j;
            }
        }

        if (clusters[cluster_idx].count == 0 || 
            clusters[cluster_idx].points[clusters[cluster_idx].count - 1].x != clusters[cluster_idx].points[i].x ||
            clusters[cluster_idx].points[clusters[cluster_idx].count - 1].y != clusters[cluster_idx].points[i].y) {
            clusters[cluster_idx].points[clusters[cluster_idx].count++] = clusters[cluster_idx].points[i];
            changed = 1;
        }
    }

    return changed;
}

// Update centroids based on the mean of points in each cluster
void update_centroids(Cluster clusters[]) {
    int i, j;
    float sum_x, sum_y;

    for (i = 0; i < K; i++) {
        if (clusters[i].count > 0) {
            sum_x = 0;
            sum_y = 0;

            for (j = 0; j < clusters[i].count; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }

            clusters[i].centroid.x = sum_x / clusters[i].count;
            clusters[i].centroid.y = sum_y / clusters[i].count;
        }
    }
}

// Print each cluster and its points
void print_clusters(Cluster clusters[]) {
    int i, j;

    for (i = 0; i < K; i++) {
        printf("Cluster #%d:\n", i + 1);
        printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points: ");

        for (j = 0; j < clusters[i].count; j++) {
            printf("(%.2f, %.2f) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }

        printf("\n");
    }
}