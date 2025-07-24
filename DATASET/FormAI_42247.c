//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define N 100 // Maximum number of players
#define K 5 // Number of clusters
#define RADIUS 10 // Radius of each cluster

// Structure to represent a player with x and y coordinates
struct Player {
    int x;
    int y;
};

// Function to generate random players
void generatePlayers(struct Player players[], int n) {
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        players[i].x = rand()%50;
        players[i].y = rand()%50;
    }
}

// Function to calculate distance between two players
int distance(struct Player a, struct Player b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to find the closest cluster for a player
int closestCluster(struct Player player, struct Player centroids[], int k) {
    int minDist = distance(player, centroids[0]);
    int closest = 0;
    for(int i=1; i<k; i++) {
        int dist = distance(player, centroids[i]);
        if(dist < minDist) {
            minDist = dist;
            closest = i;
        }
    }
    return closest;
}

// Function to update the centroids of each cluster
void updateCentroids(struct Player players[], int n, struct Player centroids[], int clusters[]) {
    int count[K] = {0};
    for(int i=0; i<n; i++) {
        count[clusters[i]]++;
        centroids[clusters[i]].x += players[i].x;
        centroids[clusters[i]].y += players[i].y;
    }
    for(int i=0; i<K; i++) {
        if(count[i] > 0) {
            centroids[i].x /= count[i];
            centroids[i].y /= count[i];
        }
    }
}

// Function to assign players to closest clusters
void assignClusters(struct Player players[], int n, struct Player centroids[], int clusters[]) {
    for(int i=0; i<n; i++) {
        clusters[i] = closestCluster(players[i], centroids, K);
    }
}

// Function to initialize centroids to random positions
void initializeCentroids(struct Player centroids[], int k) {
    srand(time(NULL));
    for(int i=0; i<k; i++) {
        centroids[i].x = rand()%50;
        centroids[i].y = rand()%50;
    }
}

// Function to print clusters and their respective players
void printClusters(struct Player players[], int n, struct Player centroids[], int clusters[]) {
    printf("\nClusters: \n");
    for(int i=0; i<K; i++) {
        printf("Cluster %d:", i+1);
        for(int j=0; j<n; j++) {
            if(clusters[j] == i) {
                printf("(%d, %d) ", players[j].x, players[j].y);
            }
        }
        printf("\nCentroid: (%d, %d)\n", centroids[i].x, centroids[i].y);
    }
}

// Main function
int main() {
    struct Player players[N];
    struct Player centroids[K];
    int clusters[N];

    generatePlayers(players, N); // Generate random players
    initializeCentroids(centroids, K); // Initialize centroids to random positions

    // Run clustering algorithm for 10 iterations
    for(int i=0; i<10; i++) {
        assignClusters(players, N, centroids, clusters);
        updateCentroids(players, N, centroids, clusters);
    }

    // Print final clusters and their respective players
    printClusters(players, N, centroids, clusters);

    return 0;
}