//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define number of data points and number of clusters
#define N 100
#define K 3

// define maximum number of iterations and minimum change
#define MAX_ITER 100
#define MIN_CHANGE 0.001

// define distance function (euclidean distance)
double distance(double *a, double *b, int dim)
{
    double sum = 0;
    for (int i = 0; i < dim; ++i) {
        sum += pow((*(a + i) - *(b + i)), 2);
    }
    return sqrt(sum);
}

int main()
{
    // generate random data points
    double data[N][2];
    for (int i = 0; i < N; ++i) {
        *(data[i] + 0) = (double) rand() / RAND_MAX * 10;
        *(data[i] + 1) = (double) rand() / RAND_MAX * 10;
    }

    // initialize cluster centers
    double centers[K][2];
    for (int i = 0; i < K; ++i) {
        *(centers[i] + 0) = (double) rand() / RAND_MAX * 10;
        *(centers[i] + 1) = (double) rand() / RAND_MAX * 10;
    }

    // initialize variables for clustering
    int clusters[N];
    double change = 0;
    int iter = 0;
    int flag = 1;

    // cluster data points
    while (flag && iter < MAX_ITER) {
        // assign data points to clusters
        for (int i = 0; i < N; ++i) {
            double min_dist = INFINITY;
            int min_index = 0;
            for (int j = 0; j < K; ++j) {
                double dist = distance(*(data + i), *(centers + j), 2);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_index = j;
                }
            }
            if (*(clusters + i) != min_index) {
                *(clusters + i) = min_index;
                change = 1;
            }
        }

        // update cluster centers
        for (int i = 0; i < K; ++i) {
            double center[2] = {0};
            int count = 0;
            for (int j = 0; j < N; ++j) {
                if (*(clusters + j) == i) {
                    *(center + 0) += *(data[j] + 0);
                    *(center + 1) += *(data[j] + 1);
                    count++;
                }
            }
            if (count > 0) {
                *(centers[i] + 0) = *(center + 0) / (double) count;
                *(centers[i] + 1) = *(center + 1) / (double) count;
            }
        }

        // check for convergence
        if (change < MIN_CHANGE) {
            flag = 0;
        }
        else {
            change = 0;
        }

        iter++;
    }

    // print final cluster centers and data points
    printf("Final Cluster Centers:\n");
    for (int i = 0; i < K; ++i) {
        printf("Cluster %d: (%.2f, %.2f)\n", i + 1, *(centers[i] + 0), *(centers[i] + 1));
    }

    printf("\nData Points:\n");
    for (int i = 0; i < N; ++i) {
        printf("(%.2f, %.2f) - Cluster %d\n", *(data[i] + 0), *(data[i] + 1), *(clusters + i) + 1);
    }

    return 0;
}