//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIM 2 // number of dimensions
#define N 10 // number of data points
#define M 3 // number of clusters to form

float data[N][DIM] = {{1.0, 1.0}, {2.0, 1.0}, {4.0, 3.0}, {5.0, 4.0}, {2.0, 4.0}, {7.0, 9.0}, {9.0, 8.0}, {8.0, 7.0}, {9.0, 6.0}, {10.0, 8.0}}; // input data
float centroids[M][DIM]; // cluster centroids
int assignments[N]; // assignments of data points to clusters

// function to compute the Euclidean distance between two points
float distance(float *p1, float *p2)
{
    float sum = 0.0;
    for (int i = 0; i < DIM; i++)
    {
        sum += pow(p1[i] - p2[i], 2);
    }
    return sqrt(sum);
}

int main()
{
    // initialize random number generator
    srand(time(NULL));

    // select initial centroids randomly from the input data
    for (int i = 0; i < M; i++)
    {
        int j = rand() % N;
        for (int k = 0; k < DIM; k++)
        {
            centroids[i][k] = data[j][k];
        }
    }

    // start clustering
    int n_iterations = 10;
    for (int i = 0; i < n_iterations; i++)
    {
        // assign data points to nearest centroid
        for (int j = 0; j < N; j++)
        {
            float min_distance = INFINITY;
            int min_index = -1;
            for (int k = 0; k < M; k++)
            {
                float d = distance(data[j], centroids[k]);
                if (d < min_distance)
                {
                    min_distance = d;
                    min_index = k;
                }
            }
            assignments[j] = min_index;
        }

        // update centroids
        for (int k = 0; k < M; k++)
        {
            float sum[DIM] = {0.0};
            int count = 0;
            for (int j = 0; j < N; j++)
            {
                if (assignments[j] == k)
                {
                    for (int l = 0; l < DIM; l++)
                    {
                        sum[l] += data[j][l];
                    }
                    count++;
                }
            }
            if (count > 0)
            {
                for (int l = 0; l < DIM; l++)
                {
                    centroids[k][l] = sum[l] / count;
                }
            }
            else
            {
                int j = rand() % N;
                for (int l = 0; l < DIM; l++)
                {
                    centroids[k][l] = data[j][l];
                }
            }
        }
    }

    // print results
    for (int k = 0; k < M; k++)
    {
        printf("centroid %d: (%f, %f)\n", k, centroids[k][0], centroids[k][1]);
        printf("points assigned to centroid %d:\n", k);
        for (int j = 0; j < N; j++)
        {
            if (assignments[j] == k)
            {
                printf("(%f, %f)\n", data[j][0], data[j][1]);
            }
        }
    }

    return 0;
}