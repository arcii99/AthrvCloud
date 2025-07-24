//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// define constants
#define DIMENSIONS 2
#define CLUSTERS 3
#define MAX_ITERATIONS 100
#define DATASETS 100

// structure to hold data point information
typedef struct {
    double coordinates[DIMENSIONS];
    int cluster;
} DataPoint;

// global variables
DataPoint data[DATASETS]; // dataset
DataPoint centroids[CLUSTERS]; // centroids

// initialize dataset and centroids
void initialize() {
    int i, j;

    // initialize dataset
    srand(time(NULL));
    for (i = 0; i < DATASETS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            data[i].coordinates[j] = (double)rand() / RAND_MAX;
        }
    }

    // initialize centroids
    for (i = 0; i < CLUSTERS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            centroids[i].coordinates[j] = (double)rand() / RAND_MAX;
        }
    }
}

// calculate distance between two data points
double distance(DataPoint *a, DataPoint *b) {
    double result = 0;
    int i;

    for (i = 0; i < DIMENSIONS; i++) {
        result += pow(a->coordinates[i] - b->coordinates[i], 2);
    }

    return sqrt(result);
}

// assign each data point to closest centroid
void assign_clusters() {
    int i, j, c;
    double min_distance, temp_distance;

    for (i = 0; i < DATASETS; i++) {
        min_distance = INFINITY;
        for (j = 0; j < CLUSTERS; j++) {
            temp_distance = distance(&data[i], &centroids[j]);
            if (temp_distance < min_distance) {
                min_distance = temp_distance;
                c = j;
            }
        }
        data[i].cluster = c;
    }
}

// update centroid coordinates
void update_centroids() {
    int i, j, count;
    double sum[DIMENSIONS];
    DataPoint *current_point;

    for (i = 0; i < CLUSTERS; i++) {
        count = 0;
        for (j = 0; j < DIMENSIONS; j++) {
            sum[j] = 0;
        }
        for (j = 0; j < DATASETS; j++) {
            current_point = &data[j];
            if (current_point->cluster == i) {
                count++;
                sum[0] += current_point->coordinates[0];
                sum[1] += current_point->coordinates[1];
            }
        }
        centroids[i].coordinates[0] = sum[0] / count;
        centroids[i].coordinates[1] = sum[1] / count;
    }
}

// main function
int main() {
    int i, j, k;

    // initialize dataset and centroids
    initialize();

    // perform clustering
    for (k = 0; k < MAX_ITERATIONS; k++) {

        // assign each data point to closest centroid
        assign_clusters();

        // update centroid coordinates
        update_centroids();
    }

    // print data points and corresponding cluster
    printf("Data Points and corresponding cluster:\n");
    for (i = 0; i < DATASETS; i++) {
        printf("%f, %f - Cluster %d\n", data[i].coordinates[0], data[i].coordinates[1], data[i].cluster);
    }

    // print final centroids
    printf("Final centroids:\n");
    for (i = 0; i < CLUSTERS; i++) {
        printf("(%f, %f)\n", centroids[i].coordinates[0], centroids[i].coordinates[1]);
    }

    return 0;
}