//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: excited
/* Hooray! Let's cluster! */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define K 5 // Number of clusters
#define N 100 // Number of data points
#define D 2 // Dimensionality of data
#define MAX_ITER 100 // Maximum number of iterations for k-means

double data[N][D]; // Our data points
double centroids[K][D]; // Centroids for each cluster
int assignments[N]; // Assignments of each data point to a cluster
double distances[N][K]; // Distances between each data point and each centroid

/* Our distance function: Euclidean distance */
double distance(double *p, double *q)
{
    double sum = 0.0;
    for (int i = 0; i < D; i++) {
        sum += pow(p[i] - q[i], 2.0);
    }
    return sqrt(sum);
}

/* Initialize centroids randomly */
void init_centroids()
{
    srand(time(NULL));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            centroids[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

/* Assign each data point to the nearest centroid */
void assign_points()
{
    for (int i = 0; i < N; i++) {
        double min_dist = INFINITY;
        int min_index;
        for (int j = 0; j < K; j++) {
            double d = distance(data[i], centroids[j]);
            distances[i][j] = d;
            if (d < min_dist) {
                min_dist = d;
                min_index = j;
            }
        }
        assignments[i] = min_index;
    }
}

/* Update centroids by taking the mean of all data points assigned to it */
void update_centroids()
{
    double sums[K][D] = {0};
    int counts[K] = {0};
    for (int i = 0; i < N; i++) {
        int k = assignments[i];
        for (int j = 0; j < D; j++) {
            sums[k][j] += data[i][j];
        }
        counts[k]++;
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            if (counts[i] > 0) {
                centroids[i][j] = sums[i][j] / counts[i];
            }
        }
    }
}

/* Main function */
int main()
{
    // Generate random data
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Initialize centroids
    init_centroids();

    // K-means
    printf("Let's start clustering!\n");
    for (int i = 0; i < MAX_ITER; i++) {
        assign_points();
        update_centroids();
        printf("Iteration %d done!\n", i+1);
    }
    printf("Clustering done!\n");

    return 0;
}