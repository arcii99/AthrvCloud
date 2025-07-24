//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLAYERS 10
#define NUM_DIMENSIONS 2
#define NUM_CLUSTERS 3
#define MAX_ITERS 100

double players[NUM_PLAYERS][NUM_DIMENSIONS] = {
    {2, 3},
    {2, 4},
    {3, 4},
    {10, 11},
    {12, 12},
    {11, 9},
    {7, 6},
    {15, 16},
    {19, 20},
    {18, 22}
};

double centroids[NUM_CLUSTERS][NUM_DIMENSIONS] = {
    {1, 2},
    {4, 5},
    {9, 10}
};

int cluster_assignments[NUM_PLAYERS] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int main() {
    int iter = 0;
    int i, j, k;
    double min_distance, distance;
    
    while(iter < MAX_ITERS) {
        // Assign players to nearest centroid
        for(i = 0; i < NUM_PLAYERS; i++) {
            min_distance = INFINITY;
            for(j = 0; j < NUM_CLUSTERS; j++) {
                distance = 0;
                for(k = 0; k < NUM_DIMENSIONS; k++) {
                    distance += pow(players[i][k] - centroids[j][k], 2);
                }
                distance = sqrt(distance);
                if(distance < min_distance) {
                    min_distance = distance;
                    cluster_assignments[i] = j;
                }
            }
        }
        
        // Update centroids
        int num_players_in_cluster;
        for(i = 0; i < NUM_CLUSTERS; i++) {
            num_players_in_cluster = 0;
            for(j = 0; j < NUM_DIMENSIONS; j++) {
                centroids[i][j] = 0;
            }
            for(j = 0; j < NUM_PLAYERS; j++) {
                if(cluster_assignments[j] == i) {
                    num_players_in_cluster++;
                    for(k = 0; k < NUM_DIMENSIONS; k++) {
                        centroids[i][k] += players[j][k];
                    }
                }
            }
            if(num_players_in_cluster > 0) {
                for(j = 0; j < NUM_DIMENSIONS; j++) {
                    centroids[i][j] /= num_players_in_cluster;
                }
            }
        }
        
        // Check if clusters have changed
        int clusters_changed = 0;
        for(i = 0; i < NUM_PLAYERS; i++) {
            if(cluster_assignments[i] != -1 &&
               cluster_assignments[i] != cluster_assignments[(i+1)%NUM_PLAYERS]) {
                clusters_changed = 1;
            }
        }
        if(!clusters_changed) {
            break;
        }
        iter++;
    }
    
    // Print cluster assignments
    printf("Final cluster assignments:\n");
    for(i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: Cluster %d\n", i, cluster_assignments[i]);
    }
    
    return EXIT_SUCCESS;
}