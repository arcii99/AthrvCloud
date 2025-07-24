//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define DATA_POINTS 100
#define NUM_CLUSTERS 3
#define DIMENSIONS 2
#define THRESHOLD 0.00001

/* structure to represent a data point */
typedef struct point {
    double dimensions[DIMENSIONS];
    int cluster;
} Point;

/* function prototypes */
void initialize_data(Point data[]);
void initialize_clusters(Point clusters[]);
double find_distance(Point p1, Point p2);
void assign_points_to_clusters(Point data[], Point clusters[]);
void reposition_clusters(Point data[], Point clusters[]);

int main() {
    Point data[DATA_POINTS];
    Point clusters[NUM_CLUSTERS];
    int i, j, iterations = 0;
    double sum_of_distance;

    /* initialize random seed */
    srand(time(NULL));

    /* initialize data points and clusters */
    initialize_data(data);
    initialize_clusters(clusters);

    /* iterate until convergence */
    while(iterations < MAX_ITERATIONS) {
        iterations++;

        /* assign data points to clusters */
        assign_points_to_clusters(data, clusters);

        /* reposition clusters */
        reposition_clusters(data, clusters);

        /* calculate sum of distances between data points and their assigned clusters */
        sum_of_distance = 0.0;
        for(i = 0; i < DATA_POINTS; i++) {
            sum_of_distance += find_distance(data[i], clusters[data[i].cluster]);
        }

        /* check for convergence */
        if(sum_of_distance < THRESHOLD) {
            break;
        }
    }

    /* print final cluster assignments */
    printf("Final cluster assignments:\n");
    for(i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:", i);
        for(j = 0; j < DATA_POINTS; j++) {
            if(data[j].cluster == i) {
                printf(" (%.2f,%.2f)", data[j].dimensions[0], data[j].dimensions[1]);
            }
        }
        printf("\n");
    }

    return 0;
}

/* function to initialize data points with random values */
void initialize_data(Point data[]) {
    int i, j;

    for(i = 0; i < DATA_POINTS; i++) {
        for(j = 0; j < DIMENSIONS; j++) {
            data[i].dimensions[j] = (double)rand() / RAND_MAX;
        }
        data[i].cluster = 0;
    }
}

/* function to initialize clusters with random values */
void initialize_clusters(Point clusters[]) {
    int i, j;

    for(i = 0; i < NUM_CLUSTERS; i++) {
        for(j = 0; j < DIMENSIONS; j++) {
            clusters[i].dimensions[j] = (double)rand() / RAND_MAX;
        }
        clusters[i].cluster = i;
    }
}

/* function to find Euclidean distance between two points */
double find_distance(Point p1, Point p2) {
    int i;
    double sum = 0.0;

    for(i = 0; i < DIMENSIONS; i++) {
        sum += pow(p1.dimensions[i] - p2.dimensions[i], 2);
    }

    return sqrt(sum);
}

/* function to assign each data point to its nearest cluster */
void assign_points_to_clusters(Point data[], Point clusters[]) {
    int i, j;
    double dist, min_dist;

    for(i = 0; i < DATA_POINTS; i++) {
        min_dist = find_distance(data[i], clusters[0]);
        data[i].cluster = 0;

        for(j = 1; j < NUM_CLUSTERS; j++) {
            dist = find_distance(data[i], clusters[j]);
            if(dist < min_dist) {
                min_dist = dist;
                data[i].cluster = j;
            }
        }
    }
}

/* function to reposition each cluster as the centroid of its assigned data points */
void reposition_clusters(Point data[], Point clusters[]) {
    int i, j, num_points;
    double sum;

    for(i = 0; i < NUM_CLUSTERS; i++) {
        num_points = 0;
        for(j = 0; j < DATA_POINTS; j++) {
            if(data[j].cluster == i) {
                num_points++;
                clusters[i].dimensions[0] += data[j].dimensions[0];
                clusters[i].dimensions[1] += data[j].dimensions[1];
            }
        }

        if(num_points > 0) {
            clusters[i].dimensions[0] /= num_points;
            clusters[i].dimensions[1] /= num_points;
        }
    }
}