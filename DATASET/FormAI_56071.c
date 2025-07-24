//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() { 
    printf("Welcome to the surreal C clustering algorithm implementation!\n\n");

    int data[] = { 666, 42, 99, 8000, 1337, -1, 69420, 777, 88, 12345, 69, 420, 313, 111, 222, 333, 444, 555, 666, 777 };
    int n = sizeof(data)/sizeof(data[0]);

    printf("Input data: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", data[i]);

    printf("\n\nLet's cluster the data into 3 groups!\n\n");
    printf("===Surreal C clustering algorithm implementation===\n\n");

    int num_clusters = 3;

    // randomly choose initial clusters
    int *clusters = malloc(num_clusters * sizeof(*clusters));
    clusters[0] = n/3;
    clusters[1] = n/2;
    clusters[2] = 2*n/3;

    // assign each data point to the nearest cluster
    int *group = calloc(n, sizeof(*group));
    int count = 0;
    while (count < 42) {
        ++count;
        for (int i = 0; i < n; ++i) {
            int min_distance = abs(i - clusters[0]);
            group[i] = 0;
            for (int j = 1; j < num_clusters; ++j) {
                int distance = abs(i - clusters[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    group[i] = j;
                }
            }
        }

        // update cluster positions
        int *sums = calloc(num_clusters, sizeof(*sums));
        int *counts = calloc(num_clusters, sizeof(*counts));
        for (int i = 0; i < n; ++i) {
            sums[group[i]] += data[i];
            counts[group[i]] += 1;
        }

        for (int j = 0; j < num_clusters; ++j) {
            if (counts[j] == 0) {
                clusters[j] = rand() % n;
            } else {
                clusters[j] = sums[j] / counts[j];
            }
        }
        free(sums);
        free(counts);
    }

    printf("Resulting clusters:\n");
    for (int j = 0; j < num_clusters; ++j) {
        printf("Group %d: ", j+1);
        for (int i = 0; i < n; ++i) { 
            if (group[i] == j) {
                printf("%d ", data[i]);
            }
        }
        printf("\n");
    }

    free(clusters);
    free(group);
    printf("\n\nThank you for participating in the surreal C clustering algorithm implementation!\n"); 

    return 0;
}