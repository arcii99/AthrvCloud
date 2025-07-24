//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 100
#define NUM_DIMENSIONS 3
#define NUM_CLUSTERS 5
#define MAX_ITERATIONS 100
#define THRESHOLD 0.001

// Definition of a cyberpunk point in 3D space
typedef struct CyberpunkPoint {
    float x;
    float y;
    float z;
    int cluster;
} CyberpunkPoint;

// Global variables
CyberpunkPoint population[POPULATION_SIZE];
CyberpunkPoint centroids[NUM_CLUSTERS];

// Calculates the Euclidean distance between two points
float euclideanDistance(CyberpunkPoint point1, CyberpunkPoint point2) {
    float x_diff = point1.x - point2.x;
    float y_diff = point1.y - point2.y;
    float z_diff = point1.z - point2.z;
    return sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
}

// Assigns each point to the closest cluster centroid
void assignPointsToClusters() {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        float min_distance = euclideanDistance(population[i], centroids[0]);
        int closest_cluster = 0;
        for (int j = 1; j < NUM_CLUSTERS; j++) {
            float distance = euclideanDistance(population[i], centroids[j]);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        population[i].cluster = closest_cluster;
    }
}

// Calculates the new position for each cluster centroid
void calculateNewCentroids() {
    int cluster_sizes[NUM_CLUSTERS] = {0};
    for (int i = 0; i < POPULATION_SIZE; i++) {
        int cluster = population[i].cluster;
        centroids[cluster].x += population[i].x;
        centroids[cluster].y += population[i].y;
        centroids[cluster].z += population[i].z;
        cluster_sizes[cluster]++;
    }
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        centroids[i].x /= cluster_sizes[i];
        centroids[i].y /= cluster_sizes[i];
        centroids[i].z /= cluster_sizes[i];
    }
}

// Runs the clustering algorithm
void runClustering() {
    // Initialize the population with random points
    srand(time(NULL));
    for (int i = 0; i < POPULATION_SIZE; i++) {
        float x = ((float) rand() / RAND_MAX) * 1000;
        float y = ((float) rand() / RAND_MAX) * 1000;
        float z = ((float) rand() / RAND_MAX) * 1000;
        population[i].x = x;
        population[i].y = y;
        population[i].z = z;
    }
    // Initialize the centroids with random points from the population
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        int index = rand() % POPULATION_SIZE;
        centroids[i].x = population[index].x;
        centroids[i].y = population[index].y;
        centroids[i].z = population[index].z;
    }
    // Run the clustering algorithm for a maximum of MAX_ITERATIONS
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        // Assign each point to the closest cluster centroid
        assignPointsToClusters();
        // Calculate the new position for each cluster centroid
        calculateNewCentroids();
        // Calculate the total distance moved by the centroids
        float total_distance = 0;
        for (int i = 0; i < NUM_CLUSTERS; i++) {
            total_distance += euclideanDistance(population[i], centroids[i]);
        }
        // Stop if the centroids have moved less than THRESHOLD since the last iteration
        if (total_distance < THRESHOLD) {
            break;
        }
    }
    // Print the final cluster assignments
    printf("Final cluster assignments:\n");
    for (int i = 0; i < POPULATION_SIZE; i++) {
        printf("Point %d: cluster %d\n", i, population[i].cluster);
    }
}

int main() {
    runClustering();
    return 0;
}