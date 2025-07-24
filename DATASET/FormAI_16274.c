//FormAI DATASET v1.0 Category: Data mining ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIMENSIONS 3    // number of dimensions in dataset
#define DATA_SIZE 100   // number of data points in dataset
#define CLUSTER_SIZE 3  // number of clusters to generate

// function prototypes
void generate_dataset(float dataset[][DIMENSIONS], int size);
float euclidean_distance(float *point1, float *point2);
int nearest_cluster(float *point, float **clusters, int cluster_size);
void update_clusters(float dataset[][DIMENSIONS], int size, int *assignments, float **clusters, int cluster_size);
float calculate_cost(float dataset[][DIMENSIONS], int size, int *assignments, float **clusters, int cluster_size);

int main(void) {
    // seed random number generator
    srand(time(NULL));

    // generate dataset
    float dataset[DATA_SIZE][DIMENSIONS];
    generate_dataset(dataset, DATA_SIZE);

    // initialize clusters
    float *clusters[CLUSTER_SIZE];
    for (int i = 0; i < CLUSTER_SIZE; i++) {
        clusters[i] = malloc(DIMENSIONS * sizeof(float));
    }

    // randomly select initial cluster centers
    int index;
    for (int i = 0; i < CLUSTER_SIZE; i++) {
        index = rand() % DATA_SIZE;
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i][j] = dataset[index][j];
        }
    }

    // initialize assignments
    int assignments[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        assignments[i] = -1;
    }

    // perform k-means clustering
    float old_cost = INFINITY;
    float new_cost = calculate_cost(dataset, DATA_SIZE, assignments, clusters, CLUSTER_SIZE);
    while (new_cost < old_cost) {
        old_cost = new_cost;

        // assign each data point to nearest cluster
        for (int i = 0; i < DATA_SIZE; i++) {
            assignments[i] = nearest_cluster(dataset[i], clusters, CLUSTER_SIZE);
        }

        // update cluster centers
        update_clusters(dataset, DATA_SIZE, assignments, clusters, CLUSTER_SIZE);

        // calculate new cost
        new_cost = calculate_cost(dataset, DATA_SIZE, assignments, clusters, CLUSTER_SIZE);
    }

    // print final cluster assignments
    for (int i = 0; i < DATA_SIZE; i++) {
        printf("Data point %d assigned to cluster %d.\n", i, assignments[i]);
    }

    // free memory
    for (int i = 0; i < CLUSTER_SIZE; i++) {
        free(clusters[i]);
    }

    return 0;
}

// generate dataset of random values between 0 and 1
void generate_dataset(float dataset[][DIMENSIONS], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            dataset[i][j] = (float) rand() / RAND_MAX;
        }
    }
}

// calculate euclidean distance between two points
float euclidean_distance(float *point1, float *point2) {
    float sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(point1[i] - point2[i], 2);
    }
    return sqrt(sum);
}

// find nearest cluster to a data point
int nearest_cluster(float *point, float **clusters, int cluster_size) {
    int nearest = 0;
    float min_distance = INFINITY;
    float distance;
    for (int i = 0; i < cluster_size; i++) {
        distance = euclidean_distance(point, clusters[i]);
        if (distance < min_distance) {
            nearest = i;
            min_distance = distance;
        }
    }
    return nearest;
}

// update cluster centers to be mean of assigned data points
void update_clusters(float dataset[][DIMENSIONS], int size, int *assignments, float **clusters, int cluster_size) {
    float sums[CLUSTER_SIZE][DIMENSIONS] = {0};
    int counts[CLUSTER_SIZE] = {0};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            sums[assignments[i]][j] += dataset[i][j];
        }
        counts[assignments[i]]++;
    }
    for (int i = 0; i < cluster_size; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            if (counts[i] > 0) {
                clusters[i][j] = sums[i][j] / counts[i];
            }
        }
    }
}

// calculate cost of current clustering
float calculate_cost(float dataset[][DIMENSIONS], int size, int *assignments, float **clusters, int cluster_size) {
    float cost = 0.0;
    for (int i = 0; i < size; i++) {
        cost += pow(euclidean_distance(dataset[i], clusters[assignments[i]]), 2);
    }
    return cost;
}