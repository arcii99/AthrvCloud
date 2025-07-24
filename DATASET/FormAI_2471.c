//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>

// Define the size of our world
#define WORLD_SIZE 10

// Define the number of clusters we want to form
#define NUM_CLUSTERS 2

// Declare our world
int world[WORLD_SIZE][WORLD_SIZE];

// Define a struct for keeping track of cluster information
typedef struct Cluster {
    int x;
    int y;
    int size;
} Cluster;

// Declare an array of clusters
Cluster clusters[NUM_CLUSTERS];

// Function for initializing our world
void initWorld() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Fill the world with random values between 0 and 1
    for(int i = 0; i < WORLD_SIZE; i++) {
        for(int j = 0; j < WORLD_SIZE; j++) {
            world[i][j] = rand() % 2;
        }
    }
}

// Function for printing the world
void printWorld() {
    for(int i = 0; i < WORLD_SIZE; i++) {
        for(int j = 0; j < WORLD_SIZE; j++) {
            printf("%d ", world[i][j]);
        }
        printf("\n");
    }
}

// Function for finding the nearest cluster to a point
int findNearestCluster(int x, int y) {
    int minDist = WORLD_SIZE * WORLD_SIZE;
    int minIndex = -1;
    
    for(int i = 0; i < NUM_CLUSTERS; i++) {
        int dist = (x - clusters[i].x) * (x - clusters[i].x) + (y - clusters[i].y) * (y - clusters[i].y);
        if(dist < minDist) {
            minDist = dist;
            minIndex = i;
        }
    }
    
    return minIndex;
}

// Function for updating the location of each cluster
void updateClusterLocations() {
    // Calculate the new location for each cluster
    for(int i = 0; i < NUM_CLUSTERS; i++) {
        int sumX = 0;
        int sumY = 0;
        int numPoints = 0;
        
        // Calculate the average location of all points in the cluster
        for(int j = 0; j < WORLD_SIZE; j++) {
            for(int k = 0; k < WORLD_SIZE; k++) {
                if(findNearestCluster(j, k) == i) {
                    sumX += j;
                    sumY += k;
                    numPoints++;
                }
            }
        }
        
        // Update the cluster location
        clusters[i].x = sumX / numPoints;
        clusters[i].y = sumY / numPoints;
    }
}

// Function for initializing the clusters
void initClusters() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the clusters to random locations
    for(int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].x = rand() % WORLD_SIZE;
        clusters[i].y = rand() % WORLD_SIZE;
        clusters[i].size = 0;
    }
}

// Function for updating the clusters
void updateClusters() {
    // Reset the cluster sizes
    for(int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].size = 0;
    }
    
    // Add each point to its nearest cluster
    for(int i = 0; i < WORLD_SIZE; i++) {
        for(int j = 0; j < WORLD_SIZE; j++) {
            int clusterIndex = findNearestCluster(i, j);
            clusters[clusterIndex].size++;
        }
    }
}

int main() {
    // Initialize the world and clusters
    initWorld();
    initClusters();
    
    // Perform clustering iterations
    for(int i = 0; i < 10; i++) {
        // Update the location of each cluster
        updateClusterLocations();
        
        // Update the clusters
        updateClusters();
    }
    
    // Print the world and cluster information
    printf("World:\n");
    printWorld();
    
    printf("Clusters:\n");
    for(int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d: (%d, %d), size=%d\n", i, clusters[i].x, clusters[i].y, clusters[i].size);
    }
    
    return 0;
}