//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 2 // Number of clusters
#define N 8 // Number of data points
#define D 2 // Number of dimensions

// Data points array
float data[N][D] = {{2, 10}, {2, 5}, {8, 4}, {5, 8}, {7, 5}, {6, 4}, {1, 2}, {4, 9}};

// Centroids array
float centroids[K][D];

// Clusters array
int clusters[N];

// Calculate distance between two points
float distance(float point1[], float point2[]){
    float d = 0;
    for(int i=0; i<D; i++){
        d += pow((point1[i]-point2[i]), 2);
    }
    return sqrt(d);
}

// Find the index of the closest centroid to a point
int closest_centroid(float point[]){
    float min_distance = distance(point, centroids[0]);
    int min_index = 0;
    for(int i=1; i<K; i++){
        float dist = distance(point, centroids[i]);
        if(dist < min_distance){
            min_distance = dist;
            min_index = i;
        }
    }
    return min_index;
}

// Update the centroids by calculating the average of the points assigned to each cluster
void update_centroids(){
    float new_centroids[K][D];
    int count[K] = {0};
    for(int i=0; i<N; i++){
        int c = clusters[i];
        for(int j=0; j<D; j++){
            new_centroids[c][j] += data[i][j];
        }
        count[c]++;
    }
    for(int i=0; i<K; i++){
        if(count[i] > 0){
            for(int j=0; j<D; j++){
                centroids[i][j] = new_centroids[i][j] / count[i];
            }
        }
    }
}

int main(){
    // Initialize the centroids randomly
    for(int i=0; i<K; i++){
        for(int j=0; j<D; j++){
            centroids[i][j] = (float)rand() / RAND_MAX * 10;
        }
    }
    
    // Assign each data point to its closest centroid
    for(int i=0; i<N; i++){
        clusters[i] = closest_centroid(data[i]);
    }
    
    // Print the initial clusters
    printf("Initial clusters:\n");
    for(int i=0; i<N; i++){
        printf("(%f, %f) is in cluster %d\n", data[i][0], data[i][1], clusters[i]);
    }
    
    // Run the clustering algorithm for 10 iterations
    for(int i=0; i<10; i++){
        update_centroids();
        for(int j=0; j<N; j++){
            clusters[j] = closest_centroid(data[j]);
        }
    }
    
    // Print the final clusters
    printf("\nFinal clusters:\n");
    for(int i=0; i<N; i++){
        printf("(%f, %f) is in cluster %d\n", data[i][0], data[i][1], clusters[i]);
    }
    
    return 0;
}