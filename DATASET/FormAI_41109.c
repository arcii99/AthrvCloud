//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 100 // Maximum number of points
#define MAX_ITERATIONS 10 // Maximum number of iterations
#define K 3 // Number of clusters

// Custom struct to store a point's coordinates
typedef struct {
    float x;
    float y;
} Point;

// Distance calculation function between two points
float distance(Point a, Point b) {
    float x_diff = a.x - b.x;
    float y_diff = a.y - b.y;
    return sqrt((x_diff * x_diff) + (y_diff * y_diff));
}

// Cluster calculation function
void cluster(Point points[], int num_points, Point centroids[]) {
    float distances[num_points][K];
    for(int i = 0; i < num_points; i++) {
        for(int j = 0; j < K; j++) {
            distances[i][j] = distance(points[i], centroids[j]);
        }
    }
    int cluster_groups[num_points];
    for(int i = 0; i < num_points; i++) {
        float smallest_distance = distances[i][0];
        int group = 0;
        for(int j = 1; j < K; j++) {
            if(distances[i][j] < smallest_distance) {
                smallest_distance = distances[i][j];
                group = j;
            }
        }
        cluster_groups[i] = group;
    }
    int num_points_per_cluster[K] = {0};
    for(int i = 0; i < num_points; i++) {
        num_points_per_cluster[cluster_groups[i]]++;
    }
    for(int i = 0; i < K; i++) {
        centroids[i].x = 0;
        centroids[i].y = 0;
        for(int j = 0; j < num_points; j++) {
            if(cluster_groups[j] == i) {
                centroids[i].x += points[j].x;
                centroids[i].y += points[j].y;
            }
        }
        centroids[i].x /= num_points_per_cluster[i];
        centroids[i].y /= num_points_per_cluster[i];
    }
}

int main() {
    Point points[MAX_POINTS] = {{1,1}, {1,2}, {1,3}, {2,1}, {2,2}, {2,3}, {3,1}, {3,2}, {3,3}, {4,1}};
    Point initial_centroids[K] = {{1,1}, {2,2}, {3,3}}; // Initial centroid coordinates
    Point centroids[K];
    int iterations = 0;
    while(iterations < MAX_ITERATIONS) {
        cluster(points, MAX_POINTS, initial_centroids);
        for(int i = 0; i < K; i++) {
            centroids[i] = initial_centroids[i];
        }
        printf("Iteration %d:\n", iterations+1);
        for(int i = 0; i < K; i++) {
            printf("Centroid %d: (%.1f, %.1f)\n", i+1, centroids[i].x, centroids[i].y);
        }
        printf("\n");
        iterations++;
    }
    return 0;
}