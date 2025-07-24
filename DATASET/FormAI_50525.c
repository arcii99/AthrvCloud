//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <pthread.h>

// Constants
#define NUM_POINTS 100
#define NUM_CLUSTERS 3
#define ITERATIONS 5

// Data Types
typedef struct Point {
    float x, y;
    int cluster;
} Point;

typedef struct Cluster {
    float x, y;
    int count;
} Cluster;

// Global Variables
Point points[NUM_POINTS];
Cluster clusters[NUM_CLUSTERS];

// Function Prototypes
void* kmeans(void* arg);
void init();
float distance(Point p, Cluster c);
void assign_clusters();
void update_centers();

// Main Function
int main() {
    init();
    
    // Create threads for each iteration
    pthread_t threads[ITERATIONS];
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_create(&threads[i], NULL, kmeans, NULL);
    }
    
    // Wait for threads to finish
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print final cluster centers and their counts
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d: (%.2f, %.2f) - %d points\n", i, clusters[i].x, clusters[i].y, clusters[i].count);
    }
    
    return 0;
}

// K-Means Algorithm Thread Function
void* kmeans(void* arg) {
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i].cluster = -1;
    }
    
    // Assign each point to a random cluster
    for (int i = 0; i < NUM_POINTS; i++) {
        int cluster_id = rand() % NUM_CLUSTERS;
        points[i].cluster = cluster_id;
        clusters[cluster_id].count++;
    }
    
    // Perform clustering iterations
    for (int i = 0; i < ITERATIONS; i++) {
        assign_clusters();
        update_centers();
    }
    
    pthread_exit(NULL);
}

// Initialize Data
void init() {
    srand(time(NULL));
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i].x = (float) rand() / RAND_MAX * 10;
        points[i].y = (float) rand() / RAND_MAX * 10;
        points[i].cluster = -1;
    }
    
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].x = (float) rand() / RAND_MAX * 10;
        clusters[i].y = (float) rand() / RAND_MAX * 10;
        clusters[i].count = 0;
    }    
}

// Calculate Euclidean Distance between a Point and a Cluster Center
float distance(Point p, Cluster c) {
    float dx = p.x - c.x;
    float dy = p.y - c.y;
    return sqrt(dx * dx + dy * dy);
}

// Assign Points to Clusters
void assign_clusters() {
    for (int i = 0; i < NUM_POINTS; i++) {
        Point p = points[i];
        int min_cluster = -1;
        float min_distance = INFINITY;
        
        // Find closest cluster
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            float d = distance(p, clusters[j]);
            if (d < min_distance) {
                min_distance = d;
                min_cluster = j;
            }
        }
        
        // Update point cluster assignment
        points[i].cluster = min_cluster;
    }
}

// Update Cluster Centers
void update_centers() {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        Cluster c = {0, 0, 0};
        
        // Calculate new center based on assigned points
        for (int j = 0; j < NUM_POINTS; j++) {
            Point p = points[j];
            if (p.cluster == i) {
                c.x += p.x;
                c.y += p.y;
                c.count++;
            }
        }
        
        // Update cluster center
        c.x /= c.count;
        c.y /= c.count;
        clusters[i] = c;
    }
}