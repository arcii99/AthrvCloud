//FormAI DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Declare variables
    int data[100];
    int i, j;
    int num_clusters = 3;
    int cluster_centers[num_clusters];
    int cluster_size[num_clusters];
    int distance_min, distance_temp, closest_cluster;
    int num_iterations = 10;
    
    // Generate random data
    srand(time(NULL));
    for (i = 0; i < 100; i++) {
        data[i] = random_int(0, 100);
    }

    // Initialize cluster centers randomly
    for (i = 0; i < num_clusters; i++) {
        cluster_centers[i] = random_int(0, 100);
    }
    
    // Run k-means algorithm for specified number of iterations
    for (i = 0; i < num_iterations; i++) {
        // Reset cluster size and distances to center
        memset(cluster_size, 0, num_clusters * sizeof(int));
        memset(distance_min, 0, num_clusters * sizeof(int));
        
        // Assign each data point to its closest cluster
        for (j = 0; j < 100; j++) {
            closest_cluster = 0;
            distance_min = abs(data[j] - cluster_centers[0]);
            for (int k = 1; k < num_clusters; k++) {
                distance_temp = abs(data[j] - cluster_centers[k]);
                if (distance_temp < distance_min) {
                    closest_cluster = k;
                    distance_min = distance_temp;
                }
            }
            // Add data point to cluster and update center
            cluster_size[closest_cluster]++;
            cluster_centers[closest_cluster] += (data[j] - cluster_centers[closest_cluster]) / cluster_size[closest_cluster];
        }
    }
    
    // Print final cluster centers and size
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d center: %d\n", i + 1, cluster_centers[i]);
        printf("Cluster %d size: %d\n", i + 1, cluster_size[i]);
    }
    
    return 0;
}