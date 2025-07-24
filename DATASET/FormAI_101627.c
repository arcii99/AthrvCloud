//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define K 3

double data[N][2] = {
    {2, 4}, {1, 3}, {3, 5}, {6, 1}, {5, 2},
    {4, 5}, {7, 3}, {5, 4}, {6, 5}, {7, 6}
};

double centers[K][2] = {0};

int assignments[N] = {0};

double euclidean_distance(double *vec1, double *vec2, int n) {
    double dist = 0;
    for (int i = 0; i < n; i++) {
        dist += pow(vec1[i] - vec2[i], 2);
    }
    return sqrt(dist);
}

void print_centers() {
    for (int i = 0; i < K; i++) {
        printf("(%lf, %lf)", centers[i][0], centers[i][1]);
    }
    printf("\n");
}

void print_assignments(){
    for (int i = 0; i < N; i++) {
        printf("%d ", assignments[i]);
    }
    printf("\n");
}

int main() {
    // Initialize centers randomly
    for (int i = 0; i < K; i++) {
        int idx = rand() % N;
        centers[i][0] = data[idx][0];
        centers[i][1] = data[idx][1];
    }

    int iter = 0;
    while(iter < 10){
        // Assign each point to the closest cluster center
        for (int i = 0; i < N; i++) {
            double closest_dist = INFINITY;
            int closest_idx = -1;
            for (int j = 0; j < K; j++) {
                double dist = euclidean_distance(data[i], centers[j], 2);
                if (dist < closest_dist) {
                    closest_dist = dist;
                    closest_idx = j;
                }
            }
            assignments[i] = closest_idx;
        }

        print_assignments();

        // Move the cluster centers to the mean of their assigned points
        for (int i = 0; i < K; i++) {
            double sum_x = 0, sum_y = 0;
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (assignments[j] == i) {
                    sum_x += data[j][0];
                    sum_y += data[j][1];
                    count++;
                }
            }
            if(count > 0){
                centers[i][0] = sum_x / count;
                centers[i][1] = sum_y / count;
            }
        }
        print_centers();
        iter++;
    }

    return 0;
}