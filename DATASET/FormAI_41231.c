//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define K 4     // Number of Clusters
#define N 100   // Number of data points
#define D 2     // Number of dimensions
#define MAX_ITER 10

// Structure to store 2D data point
typedef struct{
    float x;
    float y;
} Point;

// Function prototypes
int randInt(int min, int max);
float distance(Point a, Point b);
int findClosest(Point data, Point centroids[]);
void assignToCluster(Point data[], Point centroids[], int cluster[]);
void updateCentroids(Point data[], int cluster[], Point centroids[]);
void printClusters(Point data[], int cluster[]);

// Main function
int main(){

    Point data[N];              // Array to store data points
    Point centroids[K];         // Array to store centroids
    int cluster[N];             // Array to store cluster number
    int i, j, iter;
    
    // Initialize data with random values
    for(i=0; i<N; i++){
        data[i].x = (float)randInt(0, 100);
        data[i].y = (float)randInt(0, 100);
    }
    
    // Initialize centroids with random data points
    for(i=0; i<K; i++){
       centroids[i] = data[randInt(0, N-1)];
    }
    
    // Assign data points to clusters
    assignToCluster(data, centroids, cluster);
    
    // Update centroids
    for(iter=1; iter<=MAX_ITER; iter++){
        printf("Iteration %d\n", iter);
        updateCentroids(data, cluster, centroids);
        assignToCluster(data, centroids, cluster);
        printClusters(data, cluster);
        printf("\n");
    }
    
    return 0;
}

// Generate a random integer between min and max
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Calculate Euclidean distance between two data points 
float distance(Point a, Point b){
    float result = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    return result;
}

// Find the closest centroid to a data point and return its index
int findClosest(Point data, Point centroids[]){
    int c = 0;
    float dist, minDist = distance(data, centroids[0]);
    
    for(int i=1; i<K; i++){
        dist = distance(data, centroids[i]);
        if(dist < minDist){
            c = i;
            minDist = dist;
        }
    }
    
    return c;
}

// Assign data points to clusters based on closest centroid 
void assignToCluster(Point data[], Point centroids[], int cluster[]){
    for(int i=0; i<N; i++){
        cluster[i] = findClosest(data[i], centroids);
    }
}

// Update centroid values based on data points in each cluster
void updateCentroids(Point data[], int cluster[], Point centroids[]){
    Point sum[K] = {0};
    int count[K] = {0};
    
    for(int i=0; i<N; i++){
        sum[cluster[i]].x += data[i].x;
        sum[cluster[i]].y += data[i].y;
        count[cluster[i]]++;
    }
    
    for(int i=0; i<K; i++){
        if(count[i] == 0) continue;
        centroids[i].x = sum[i].x / count[i];
        centroids[i].y = sum[i].y / count[i];
    }
}

// Print clustered data points
void printClusters(Point data[], int cluster[]){
    for(int i=0; i<K; i++){
        printf("Cluster %d:\n", i+1);
        for(int j=0; j<N; j++){
            if(cluster[j] == i){
                printf("(%.1f, %.1f) ", data[j].x, data[j].y);
            }
        }
        printf("\n");
    }
}