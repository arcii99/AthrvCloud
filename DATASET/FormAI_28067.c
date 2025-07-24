//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define constants
#define N 1000 // Number of points
#define K 5 // Number of clusters
#define ITERATIONS 500 // Maximum number of iterations
#define THRESHOLD 0.0001 // Convergence threshold

// Define structures
typedef struct {
    float x;
    float y;
} point_t;

typedef struct {
    int size;
    point_t centroid;
    point_t *points;
} cluster_t;

// Define functions
float euclidean_distance(point_t p1, point_t p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void assign_points_to_clusters(cluster_t *clusters, point_t *points) {
    for (int i = 0; i < N; i++) {
        float min_distance = INFINITY;
        int closest_cluster;
        for (int j = 0; j < K; j++) {
            float distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].points[clusters[closest_cluster].size] = points[i];
        clusters[closest_cluster].size++;
    }
}

void update_cluster_centroids(cluster_t *clusters) {
    for (int i = 0; i < K; i++) {
        float x_sum = 0;
        float y_sum = 0;
        for (int j = 0; j < clusters[i].size; j++) {
            x_sum += clusters[i].points[j].x;
            y_sum += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = x_sum / clusters[i].size;
        clusters[i].centroid.y = y_sum / clusters[i].size;
    }
}

float calculate_total_distance(cluster_t *clusters) {
    float total_distance = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < clusters[i].size; j++) {
            total_distance += euclidean_distance(clusters[i].centroid, clusters[i].points[j]);
        }
    }
    return total_distance;
}

void print_cluster_sizes(cluster_t *clusters) {
    for (int i = 0; i < K; i++) {
        printf("Cluster %d has %d points\n", i+1, clusters[i].size);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate random points
    point_t points[N];
    for (int i = 0; i < N; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    
    // Initialize clusters
    cluster_t clusters[K];
    for (int i = 0; i < K; i++) {
        clusters[i].size = 0;
        clusters[i].centroid.x = rand() % 100;
        clusters[i].centroid.y = rand() % 100;
        clusters[i].points = malloc(sizeof(point_t) * N);
    }
    
    // Perform clustering
    float previous_distance;
    float current_distance = INFINITY;
    int iterations = 0;
    while (fabs(current_distance - previous_distance) > THRESHOLD && iterations < ITERATIONS) {
        // Assign points to clusters
        assign_points_to_clusters(clusters, points);
        
        // Update cluster centroids
        update_cluster_centroids(clusters);
        
        // Calculate total distance
        previous_distance = current_distance;
        current_distance = calculate_total_distance(clusters);
        
        // Print information
        printf("Iteration %d: Total distance = %.2f\n", iterations+1, current_distance);
        print_cluster_sizes(clusters);
        
        // Reset cluster points
        for (int i = 0; i < K; i++) {
            clusters[i].size = 0;
        }
        
        // Increment iteration
        iterations++;
    }
    
    // Free memory
    for (int i = 0; i < K; i++) {
        free(clusters[i].points);
    }
    
    return 0;
}