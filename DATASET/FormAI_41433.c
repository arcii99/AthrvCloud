//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define M 2
#define K 3

double data[N][M] = {
    {-1, -1},
    {-2, -1},
    {-3, -2},
    {1, 1},
    {2, 1},
    {3, 2},
    {0, 0.5},
    {0, -0.5},
    {0.5, 0},
    {-0.5, 0}
};
double centroid[K][M] = {
    {1, 1},
    {-1, -1},
    {0,0}
};
int clusters[N];

double dist(double p1[M], double p2[M]){
    double sum = 0;
    for(int i = 0; i < M; i++){
        sum += pow(p1[i] - p2[i], 2);
    }
    return sqrt(sum);
}

void assign_clusters(){
    for(int i = 0; i < N; i++){
        double min_dist = INFINITY;
        int min_cluster = -1;
        for(int j = 0; j < K; j++){
            double d = dist(data[i], centroid[j]);
            if(d < min_dist){
                min_dist = d;
                min_cluster = j;
            }
        }
        clusters[i] = min_cluster;
    }
}

void calculate_centroids(){
    double sums[K][M] = {0};
    int counts[K] = {0};
    for(int i = 0; i < N; i++){
        int c = clusters[i];
        for(int j = 0; j < M; j++){
            sums[c][j] += data[i][j];
        }
        counts[c]++;
    }
    for(int i = 0; i < K; i++){
        if(counts[i] > 0){
            for(int j = 0; j < M; j++){
                centroid[i][j] = sums[i][j] / counts[i];
            }
        }
    }
}

int main(){
    int iterations = 50;
    for(int i = 0; i < iterations; i++){
        assign_clusters();
        calculate_centroids();
    }
    for(int i = 0; i < N; i++){
        printf("Point (%g, %g) is in cluster %d\n", data[i][0], data[i][1], clusters[i]);
    }
    return 0;
}