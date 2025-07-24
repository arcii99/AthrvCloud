//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 5
#define THRESHOLD 0.05

// Function to calculate Euclidean distance between two points
float distance(float *p1, float *p2, int dimensions){
    float d = 0.0;
    for(int i = 0; i < dimensions; i++){
        d += pow(p1[i] - p2[i], 2);
    }
    return sqrt(d);
}

// Function to initialize centroids randomly
void initialize(float **centroids, int k, int dimensions){
    for(int i = 0; i < k; i++){
        centroids[i] = (float*) malloc(dimensions * sizeof(float));
        for(int j = 0; j < dimensions; j++){
            centroids[i][j] = (float) (rand() % 10);
        }
    }
}

// Function to assign each point to the closest centroid
void assign_cluster(float **data, int n, int dimensions, float **centroids, int k, int *cluster_assignment){
    float min_distance, d;
    int closest_cluster;
    for(int i = 0; i < n; i++){
        min_distance = distance(data[i], centroids[0], dimensions);
        closest_cluster = 0;
        for(int j = 1; j < k; j++){
            d = distance(data[i], centroids[j], dimensions);
            if(d < min_distance){
                min_distance = d;
                closest_cluster = j;
            }
        }
        cluster_assignment[i] = closest_cluster;
    }
}

// Function to update centroids based on the mean of the assigned points
void update(float **data, int n, int dimensions, float **centroids, int k, int *cluster_assignment, int *cluster_size){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < dimensions; j++){
            centroids[i][j] = 0.0;
        }
        cluster_size[i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < dimensions; j++){
            centroids[cluster_assignment[i]][j] += data[i][j];
        }
        cluster_size[cluster_assignment[i]]++;
    }
    for(int i = 0; i < k; i++){
        if(cluster_size[i] > 0){
            for(int j = 0; j < dimensions; j++){
                centroids[i][j] /= cluster_size[i];
            }
        }
    }
}

// Main function
int main(){
    int n, dimensions, k;
    float data[MAX_POINTS][MAX_CLUSTERS];
    float *data_p[MAX_POINTS];
    float *centroids[MAX_CLUSTERS];
    int cluster_assignment[MAX_POINTS];
    int cluster_size[MAX_CLUSTERS];
    scanf("%d %d %d", &n, &dimensions, &k);
    for(int i = 0; i < n; i++){
        data_p[i] = data[i];
        for(int j = 0; j < dimensions; j++){
            scanf("%f", &data[i][j]);
        }
    }
    initialize(centroids, k, dimensions);
    int iteration = 0;
    float prev_loss = 0.0, current_loss = 0.0;
    while(1){
        assign_cluster(data_p, n, dimensions, centroids, k, cluster_assignment);
        update(data_p, n, dimensions, centroids, k, cluster_assignment, cluster_size);
        iteration++;
        prev_loss = current_loss;
        current_loss = 0.0;
        for(int i = 0; i < n; i++){
            current_loss += pow(distance(data_p[i], centroids[cluster_assignment[i]], dimensions), 2);
        }
        if(fabs(current_loss - prev_loss) < THRESHOLD){
            break;
        }
    }
    // Printing the results
    printf("Iterations taken: %d\n", iteration);
    for(int i = 0; i < k; i++){
        printf("Cluster %d: ", i);
        for(int j = 0; j < n; j++){
            if(cluster_assignment[j] == i){
                printf("%d ", j+1);
            }
        }
        printf("\nCentroid: ");
        for(int j = 0; j < dimensions; j++){
            printf("%f ", centroids[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}