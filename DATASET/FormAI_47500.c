//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 1000    // number of data points
#define K 5       // number of clusters
#define D 2       // number of dimensions

int id[N];        // stores the cluster ID of each data point 
float data[N][D]; // stores the coordinates of each data point
float centroids[K][D]; // stores the coordinates of each centroid
int size[K];      // stores the number of data points in each cluster

// Generate random data points
void generateData() {
    int i, j;
    for(i=0; i<N; i++) {
        for(j=0; j<D; j++) {
            data[i][j] = (float)rand()/(float)(RAND_MAX/10);
        }
        id[i] = -1; // set initial cluster ID to -1
    }
}

// Initialize the centroids
void initializeCentroids() {
    int i, j, k;
    for(k=0; k<K; k++) {
        int r = rand()%N;
        for(j=0; j<D; j++) {
            centroids[k][j] = data[r][j];
        }
        size[k] = 0;
    }
}

// Compute the distance between two data points
float distance(float* p1, float* p2) {
    float dist = 0.0;
    int i;
    for(i=0; i<D; i++) {
        dist += pow(p1[i]-p2[i], 2);
    }
    return sqrt(dist);
}

// Assign data points to the nearest centroid
void assignPointsToClusters() {
    int i, k;
    for(i=0; i<N; i++) {
        float minDist = INFINITY;
        int minIndex = -1;
        for(k=0; k<K; k++) {
            float dist = distance(data[i], centroids[k]);
            if(dist < minDist) {
                minDist = dist;
                minIndex = k;
            }
        }
        id[i] = minIndex;
        size[minIndex]++;
    }
}

// Update the centroids
void updateCentroids() {
    int i, j, k;
    for(k=0; k<K; k++) {
        if(size[k] == 0) {
            continue;
        }
        for(j=0; j<D; j++) {
            float sum = 0.0;
            for(i=0; i<N; i++) {
                if(id[i] == k) {
                    sum += data[i][j];
                }
            }
            centroids[k][j] = sum/(float)size[k];
        }
    }
}

// Print the cluster assignments
void printResults() {
    int i;
    printf("Clusters:\n");
    for(i=0; i<N; i++) {
        printf("%d ", id[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    generateData();
    initializeCentroids();
    int iter = 0;
    while(iter < 10) {
        iter++;
        assignPointsToClusters();
        updateCentroids();
    }
    printResults();
    return 0;
}