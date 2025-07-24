//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
void k_means_clustering(double *data_points, int num_data_points, int num_clusters, double *cluster_centers);

int main() {
    int num_clusters = 3;
    int num_data_points = 10;
    
    double data_points[num_data_points*2];
    double cluster_centers[num_clusters*2];
    
    // Generating random data points
    for(int i=0; i<num_data_points; i++) {
        double x = ((double)rand() / (double)(RAND_MAX)) * 10;
        double y = ((double)rand() / (double)(RAND_MAX)) * 10;
        data_points[i*2] = x;
        data_points[i*2 + 1] = y;
    }
    
    // Initializing cluster centers
    for(int i=0; i<num_clusters; i++) {
        int random_index = rand() % num_data_points;
        cluster_centers[i*2] = data_points[random_index*2];
        cluster_centers[i*2 + 1] = data_points[random_index*2 + 1];
    }
    
    // Running k-means clustering algorithm
    k_means_clustering(data_points, num_data_points, num_clusters, cluster_centers);
    
    return 0;
}

void k_means_clustering(double *data_points, int num_data_points, int num_clusters, double *cluster_centers) {
    double prev_cluster_centers[num_clusters*2];
    int iterations = 0;
    
    // Loop until convergence
    while(1) {
        iterations++;
        printf("Iteration %d:\n", iterations);
        
        // Initializing cluster sizes and sums
        int cluster_sizes[num_clusters];
        double cluster_sums[num_clusters*2];
        for(int i=0; i<num_clusters; i++) {
            cluster_sizes[i] = 0;
            cluster_sums[i*2] = 0;
            cluster_sums[i*2 + 1] = 0;
        }
        
        // Assigning data points to nearest clusters
        for(int i=0; i<num_data_points; i++) {
            double min_distance = INFINITY;
            int nearest_cluster = -1;
            for(int j=0; j<num_clusters; j++) {
                double distance = sqrt(pow(data_points[i*2] - cluster_centers[j*2], 2) + pow(data_points[i*2 + 1] - cluster_centers[j*2 + 1], 2));
                if(distance < min_distance) {
                    min_distance = distance;
                    nearest_cluster = j;
                }
            }
            
            // Adding data point to nearest cluster
            cluster_sizes[nearest_cluster]++;
            cluster_sums[nearest_cluster*2] += data_points[i*2];
            cluster_sums[nearest_cluster*2 + 1] += data_points[i*2 + 1];
        }
        
        // Updating cluster centers
        int num_changed_centers = 0;
        for(int i=0; i<num_clusters; i++) {
            if(cluster_sizes[i] != 0) {
                double x = cluster_sums[i*2] / cluster_sizes[i];
                double y = cluster_sums[i*2 + 1] / cluster_sizes[i];
                if(x != cluster_centers[i*2] || y != cluster_centers[i*2 + 1]) {
                    prev_cluster_centers[i*2] = cluster_centers[i*2];
                    prev_cluster_centers[i*2 + 1] = cluster_centers[i*2 + 1];
                    cluster_centers[i*2] = x;
                    cluster_centers[i*2 + 1] = y;
                    num_changed_centers++;
                }
            }
        }
        
        // Printing current cluster centers
        printf("Cluster Centers:\n");
        for(int i=0; i<num_clusters; i++) {
            printf("(%f, %f) ", cluster_centers[i*2], cluster_centers[i*2 + 1]);
        }
        printf("\n");
        
        // Checking for convergence
        int all_centers_converged = 1;
        for(int i=0; i<num_clusters; i++) {
            if(cluster_sizes[i] != 0 && (cluster_centers[i*2] != prev_cluster_centers[i*2] || cluster_centers[i*2 + 1] != prev_cluster_centers[i*2 + 1])) {
                all_centers_converged = 0;
                break;
            }
        }
        if(all_centers_converged) {
            printf("Algorithm converged after %d iterations.\n", iterations);
            break;
        }
    }
}