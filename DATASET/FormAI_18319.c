//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define MAX_COORD_LENGTH 10

/* Surreal Clustering Algorithm Implementation */
int main() {
    int data_points[][MAX_COORD_LENGTH] = { 
                                            {1, 2, 6, 8, 9}, 
                                            {2, 3, 7, 9, 10}, 
                                            {3, 4, 8, 10, 11}, 
                                            {4, 5, 9, 11, 12},
                                            {6, 7, 12, 13, 18},
                                            {7, 8, 13, 14, 19},
                                            {8, 9, 14, 15, 20},
                                            {9, 10, 15, 16, 21},
                                            {10, 11, 16, 17, 22}
                                          };
    int num_points = sizeof(data_points) / sizeof(data_points[0]);

    int num_clusters = 3;
    int cluster_membership[num_points];

    int cluster_centers[MAX_COORD_LENGTH][num_clusters];
    int prev_cluster_centers[MAX_COORD_LENGTH][num_clusters];

    /* Randomly initialize cluster_centers */
    for(int i = 0; i < num_clusters; i++) {
        for(int j = 0; j < MAX_COORD_LENGTH; j++) {
            int rand_index = rand() % num_points;
            cluster_centers[j][i] = data_points[rand_index][j];
        }
    }

    /* Run surreal clustering algorithm */
    int num_iterations = 0;
    while(num_iterations < MAX_ITERATIONS) {
        /* Assign cluster membership based on distance to cluster centers */
        for(int i = 0; i < num_points; i++) {
            int closest_cluster = 0;
            double min_distance = INFINITY;
            for(int j = 0; j < num_clusters; j++) {
                double distance = 0;
                for(int k = 0; k < MAX_COORD_LENGTH; k++) {
                    distance += pow(data_points[i][k] - cluster_centers[k][j], 2);
                }
                distance = sqrt(distance);
                if(distance < min_distance) {
                    closest_cluster = j;
                    min_distance = distance;
                }
            }
            cluster_membership[i] = closest_cluster;
        }

        /* Update cluster centers based on cluster membership */
        for(int i = 0; i < num_clusters; i++) {
            for(int j = 0; j < MAX_COORD_LENGTH; j++) {
                int sum = 0;
                int count = 0;
                for(int k = 0; k < num_points; k++) {
                    if(cluster_membership[k] == i) {
                        sum += data_points[k][j];
                        count++;
                    }
                }
                if(count > 0) {
                    cluster_centers[j][i] = sum / count;
                }
            }
        }

        /* Check if cluster centers have converged */
        int centers_converged = 1;
        for(int i = 0; i < num_clusters; i++) {
            for(int j = 0; j < MAX_COORD_LENGTH; j++) {
                if(cluster_centers[j][i] != prev_cluster_centers[j][i]) {
                    centers_converged = 0;
                    break;
                }
            }
            if(!centers_converged) {
                break;
            }
        }
        if(centers_converged) {
            break;
        }

        /* Save current cluster centers */
        for(int i = 0; i < num_clusters; i++) {
            for(int j = 0; j < MAX_COORD_LENGTH; j++) {
                prev_cluster_centers[j][i] = cluster_centers[j][i];
            }
        }

        num_iterations++;
    }

    /* Print final cluster membership and cluster centers */
    printf("Final Cluster Membership:\n");
    for(int i = 0; i < num_points; i++) {
        printf("%d ", cluster_membership[i]);
    }
    printf("\n\nFinal Cluster Centers:\n");
    for(int i = 0; i < num_clusters; i++) {
        for(int j = 0; j < MAX_COORD_LENGTH; j++) {
            printf("%d ", cluster_centers[j][i]);
        }
        printf("\n");
    }

    return 0;
}