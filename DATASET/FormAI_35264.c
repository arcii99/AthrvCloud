//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void initialize_array(int [], int);
void display_array(int [], int);
void perform_clustering(int [], int);

int main() {
    int data[N];
    srand(time(NULL));
    initialize_array(data, N);
    printf("Initial data set:\n");
    display_array(data, N);
    perform_clustering(data, N);
    return 0;
}

void initialize_array(int data[], int size) {
    int i;
    for (i = 0; i < size; i++)
        data[i] = rand() % 11;
}

void display_array(int data[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d,", data[i]);
    printf("\n");
}

void perform_clustering(int data[], int size) {
    int i, j, cluster = 1;
    printf("Performing clustering...\n");
    for (i = 0; i < size; i++) {
        if (data[i] != -1) { // if not clustered
            printf("Data point %d belongs to cluster %d\n", data[i], cluster);
            for (j = i + 1; j < size; j++) { // check the rest of data points
                if (data[j] != -1) { // if not clustered
                    if (abs(data[i] - data[j]) <= 1) { // if within range
                        printf("Data point %d belongs to cluster %d\n", data[j], cluster);
                        data[j] = -1; // flag as clustered
                    }
                }
            }
            data[i] = -1; // flag as clustered
            printf("\n");
            cluster++;
        }
    }
}