//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STEP_SIZE 0.001 // Step size for gradient descent
#define MAX_ITER 10000 // Maximum iterations for gradient descent
#define MIN_CENT_DIST 0.01 // Minimum distance between centroids for convergence
#define NUM_CLUSTERS 3 // Number of clusters to form
#define DIMENSIONS 2 // Number of dimensions for data points

// Function to read in data points from a file
int read_data(char* filename, double** data_points, int* num_points){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file!\n");
        return -1;
    }
    fscanf(fp, "%d", num_points);
    *data_points = (double*) malloc((*num_points) * DIMENSIONS * sizeof(double));
    for(int i = 0; i < *num_points; i++){
        for(int j = 0; j < DIMENSIONS; j++){
            fscanf(fp, "%lf", &(*data_points)[i*DIMENSIONS + j]);
        }
    }
    fclose(fp);

    return 0;
}

// Function to calculate the distance between two data points
double calc_distance(double* point_1, double* point_2){
    double sum_of_squares = 0;
    for(int i = 0; i < DIMENSIONS; i++){
        double diff = point_1[i] - point_2[i];
        sum_of_squares += (diff * diff);
    }
    return sqrt(sum_of_squares);
}

// Function to calculate the centroid of a cluster
void calc_centroid(double* data, int* cluster_assignment, int num_points, int cluster_num, double* centroid){
    int num_points_in_cluster = 0;
    for(int i = 0; i < num_points; i++){
        if(cluster_assignment[i] == cluster_num){
            for(int j = 0; j < DIMENSIONS; j++){
                centroid[j] += data[i*DIMENSIONS + j];
            }
            num_points_in_cluster++;
        }
    }
    for(int j = 0; j < DIMENSIONS; j++){
        if(num_points_in_cluster != 0){
            centroid[j] /= num_points_in_cluster;
        }
    }
}

// Function to assign each data point to the nearest cluster
void assign_clusters(double* data, double** centroids, int* cluster_assignment, int num_points, int num_clusters){
    for(int i = 0; i < num_points; i++){
        double min_distance = INFINITY;
        int min_cluster = -1;
        for(int j = 0; j < num_clusters; j++){
            double distance = calc_distance(&data[i*DIMENSIONS], centroids[j]);
            if(distance < min_distance){
                min_distance = distance;
                min_cluster = j;
            }
        }
        cluster_assignment[i] = min_cluster;
    }
}

// Function to run the k-means clustering algorithm
int k_means(double* data, int num_points, int num_clusters, int max_iter, double min_cent_dist, double** centroids, int* cluster_assignment){
    // Initialize centroids randomly
    for(int i = 0; i < num_clusters; i++){
        for(int j = 0; j < DIMENSIONS; j++){
            centroids[i][j] = ((double) rand() / RAND_MAX);
        }
    }
    // Initialize variables for gradient descent
    int iter = 0;
    double prev_cent_dist = INFINITY;
    double centroid_update[num_clusters][DIMENSIONS];
    for(int i = 0; i < num_clusters; i++){
        for(int j = 0; j < DIMENSIONS; j++){
            centroid_update[i][j] = 0;
        }
    }
    // Run gradient descent until convergence or maximum iterations reached
    while(iter < MAX_ITER && prev_cent_dist > MIN_CENT_DIST){
        assign_clusters(data, centroids, cluster_assignment, num_points, num_clusters);
        prev_cent_dist = 0;
        for(int i = 0; i < num_clusters; i++){
            double prev_centroid[DIMENSIONS];
            for(int j = 0; j < DIMENSIONS; j++){
                prev_centroid[j] = centroids[i][j];
            }
            calc_centroid(data, cluster_assignment, num_points, i, centroids[i]);
            prev_cent_dist += calc_distance(prev_centroid, centroids[i]);
        }
        // Update centroids using gradient descent
        for(int i = 0; i < num_points; i++){
            for(int j = 0; j < num_clusters; j++){
                if(cluster_assignment[i] == j){
                    for(int k = 0; k < DIMENSIONS; k++){
                        centroid_update[j][k] += (data[i*DIMENSIONS + k] - centroids[j][k]);
                    }
                }
            }
        }
        for(int i = 0; i < num_clusters; i++){
            for(int j = 0; j < DIMENSIONS; j++){
                centroids[i][j] += (STEP_SIZE * centroid_update[i][j] / num_points);
                centroid_update[i][j] = 0;
            }
        }
        iter++;
    }
    return iter;
}

/* Driver program to test above functions */
int main(){
    double* data = NULL;
    int num_points;
    int* cluster_assignment = NULL;
    double* centroids[NUM_CLUSTERS];
    for(int i = 0; i < NUM_CLUSTERS; i++){
        centroids[i] = (double*) malloc(DIMENSIONS * sizeof(double));
    }

    read_data("data.txt", &data, &num_points);
    cluster_assignment = (int*) malloc(num_points * sizeof(int));

    k_means(data, num_points, NUM_CLUSTERS, MAX_ITER, MIN_CENT_DIST, centroids, cluster_assignment);

    // Print out cluster assignments and centroids
    printf("Cluster assignments:\n");
    for(int i = 0; i < num_points; i++){
        printf("%d ", cluster_assignment[i]);
    }
    printf("\n");

    printf("Centroids:\n");
    for(int i = 0; i < NUM_CLUSTERS; i++){
        for(int j = 0; j < DIMENSIONS; j++){
            printf("%lf ", centroids[i][j]);
        }
        printf("\n");
    }

    // Free memory
    free(data);
    for(int i = 0; i < NUM_CLUSTERS; i++){
        free(centroids[i]);
    }
    free(cluster_assignment);

    return 0;
}