//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#define K 5    // number of clusters
#define N 100  // number of data points
#define D 2    // number of dimensions

// function to calculate distance between two points
float dist(float *point1, float *point2){
    float distance = 0.0;
    for (int i = 0; i < D; i++){
        distance += pow(point1[i]-point2[i],2);
    }
    return sqrt(distance);
}

int main(){
    // generate random data points in a 2D space
    float data[N][D];
    srand(time(NULL));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < D; j++){
            data[i][j] = (float)rand()/(float)RAND_MAX*10;  // data values range from 0 to 10
        }
    }

    // initialize centroids randomly 
    float centroids[K][D];
    for (int i = 0; i < K; i++){
        for (int j = 0; j < D; j++){
            centroids[i][j] = (float)rand()/(float)RAND_MAX*10;
        }
    }

    // initialize cluster assignments for each data point
    int labels[N];

    // iterate until convergence
    int iter = 0;
    int max_iter = 100;
    while (iter < max_iter){
        // assign each data point to nearest centroid
        for (int i = 0; i < N; i++){
            float min_distance = INFINITY;
            int min_centroid = 0;
            for (int j = 0; j < K; j++){
                float d = dist(data[i],centroids[j]);
                if (d < min_distance){
                    min_distance = d;
                    min_centroid = j;
                }
            }
            labels[i] = min_centroid;
        }

        // update centroids based on assigned data points
        float sum[K][D];
        int count[K];
        for (int i = 0; i < K; i++){
            for (int j = 0; j < D; j++){
                sum[i][j] = 0.0;
            }
            count[i] = 0;
        }
        for (int i = 0; i < N; i++){
            int k = labels[i];
            for (int j = 0; j < D; j++){
                sum[k][j] += data[i][j];
            }
            count[k] += 1;
        }
        for (int i = 0; i < K; i++){
            for (int j = 0; j < D; j++){
                if (count[i] != 0){
                    centroids[i][j] = sum[i][j]/count[i];
                }
            }
        }

        // increment iteration counter
        iter++;
    }

    // print final centroid locations
    printf("Final Centroids:\n");
    for (int i = 0; i < K; i++){
        printf("Centroid %d: (",i);
        for (int j = 0; j < D; j++){
            printf("%f,",centroids[i][j]);
        }
        printf(")\n");
    }

    return 0;
}