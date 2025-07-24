//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // Number of clusters
#define DIM 2 // Number of dimensions in data vectors

float data_points[10][DIM] = { {13,15}, {1,2}, {5,8}, {7,4}, {18,20}, {17,18}, {11,5}, {9,8}, {6,13}, {4,5} };

struct cluster {
    float mean[DIM];
    int num_points;
};

void print_cluster(struct cluster c) {
    printf("Cluster mean: (");
    for(int i = 0; i < DIM; i++) {
        printf("%.2f", c.mean[i]);
        if(i < DIM-1) printf(", ");
    }
    printf(")\nNumber of points: %d\n\n", c.num_points);
}

void update_means(struct cluster clusters[]) {
    for(int i = 0; i < K; i++) {
        if(clusters[i].num_points != 0) {
            for(int j = 0; j < DIM; j++) {
                clusters[i].mean[j] /= clusters[i].num_points;
            }
        }
    }
}

float dist(float v1[], float v2[]) {
    float d = 0;
    for(int i = 0; i < DIM; i++) {
        d += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
    return sqrt(d);
}

int main() {
    struct cluster clusters[K];
    for(int i = 0; i < K; i++) {
        clusters[i].num_points = 0;
        for(int j = 0; j < DIM; j++) {
            clusters[i].mean[j] = 0;
        }
    }

    // Initialization - start with K random data points as cluster means
    int indices[K];
    for(int i = 0; i < K; i++) {
        int random_idx = rand() % 10;
        while(1) {
            int duplicate = 0;
            for(int j = 0; j < i; j++) {
                if(random_idx == indices[j]) {
                    duplicate = 1;
                    break;
                }
            }
            if(!duplicate) break;
            random_idx = rand() % 10;
        }
        indices[i] = random_idx;
        for(int j = 0; j < DIM; j++) {
            clusters[i].mean[j] = data_points[random_idx][j];
        }
    }

    // Clustering
    int num_iterations = 0;
    int cluster_assignment[10];
    while(1) {
        num_iterations++;
        for(int i = 0; i < K; i++) {
            clusters[i].num_points = 0;
            for(int j = 0; j < DIM; j++) {
                clusters[i].mean[j] = 0;
            }
        }

        // Assign data points to nearest cluster mean
        int cluster_changed = 0;
        for(int i = 0; i < 10; i++) {
            float min_d = INFINITY;
            int min_idx = -1;
            for(int j = 0; j < K; j++) {
                float d = dist(data_points[i], clusters[j].mean);
                if(d < min_d) {
                    min_d = d;
                    min_idx = j;
                }
            }
            cluster_assignment[i] = min_idx;
            clusters[min_idx].num_points++;
            for(int j = 0; j < DIM; j++) {
                clusters[min_idx].mean[j] += data_points[i][j];
            }
        }

        // Check if cluster assignments changed, stop if they didn't
        for(int i = 0; i < 10; i++) {
            if(cluster_assignment[i] != i) {
                cluster_changed = 1;
                break;
            }
        }
        if(!cluster_changed) break;

        // Update cluster means
        update_means(clusters);
    }

    // Print results
    printf("Number of iterations: %d\n\n", num_iterations);
    for(int i = 0; i < K; i++) {
        printf("Cluster %d:\n", i+1);
        print_cluster(clusters[i]);
    }

    return 0;
}