//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: scientific
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>

#define K 2
#define N 10 
#define MAX_ITER 100 

void k_means_clustering(float points[][2], int clusters[][2], int assignment[]) 
{ 
    int i, j, k, index, count, iter;
    float distance, min_distance;
    int cluster_population[K] = {0};

    /* Initialize random cluster centers */
    for (i = 0; i < K; i++) {
        index = rand() % N;
        clusters[i][0] = points[index][0];
        clusters[i][1] = points[index][1];
    }

    /* Cluster assignment */
    for (iter = 0; iter < MAX_ITER; iter++) {
        for (i = 0; i < N; i++) {
            min_distance = INFINITY;
            for (j = 0; j < K; j++) {
                distance = sqrt(pow(clusters[j][0] - points[i][0], 2) +
                                pow(clusters[j][1] - points[i][1], 2));
                if (distance < min_distance) {
                    min_distance = distance;
                    assignment[i] = j;
                }
            }
            cluster_population[assignment[i]]++;
        }

        /* Update cluster centers */
        for (k = 0; k < K; k++) {
            clusters[k][0] = clusters[k][1] = 0;
            count = 0;
            for (i = 0; i < N; i++) {
                if (assignment[i] == k) {
                    clusters[k][0] += points[i][0];
                    clusters[k][1] += points[i][1];
                    count++;
                }
            }
            clusters[k][0] /= count;
            clusters[k][1] /= count;
        }

        /* Check if clusters have changed */
        if (cluster_population[0] == 0 || cluster_population[1] == 0)
            break;

        /* Reset cluster population */
        cluster_population[0] = cluster_population[1] = 0;
    }
}

int main() 
{ 
    float points[N][2] = {{0, 3}, {0, 4}, {1, 4}, {1, 5}, {2, 3},
                          {2, 4}, {3, 5}, {4, 6}, {5, 7}, {6, 8}};

    int clusters[K][2];
    int assignment[N] = {0};

    k_means_clustering(points, clusters, assignment);

    printf("Clusters:\n");
    for (int i = 0; i < K; i++) {
        printf("(%d, %d)\n", clusters[i][0], clusters[i][1]);
    }

    printf("Cluster assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", assignment[i]);
    }
    printf("\n"); 

    return 0; 
}