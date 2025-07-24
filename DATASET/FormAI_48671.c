//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define K 3  // Number of clusters

// Function prototypes
void init_clusters(float data[][2], int size, int clusters[][2]);
float distance(float x1, float y1, float x2, float y2);
int assign_points(float data[][2], int size, int clusters[][2], int assignment[]);
void move_clusters(float data[][2], int size, int clusters[][2], int assignment[]);
void print_clusters(int clusters[][2]);

int main() {
    float data[MAX][2] = {{2, 4}, {3, 6}, {6, 8}, {5, 15}, {11, 14}, {12, 12}, {14, 14}, {16, 15}, {18, 10}, {22, 8}, {24, 5}, {28, 8}, {21, 18}, {25, 14}, {23, 20}, {27, 18}, {28, 22}, {29, 24}, {30, 26}, {35, 28}};
    int size = 20;
    int clusters[K][2];
    int assignment[MAX];

    // Initialize clusters randomly
    init_clusters(data, size, clusters);

    // Initialize assignment array to -1
    for (int i = 0; i < size; i++) {
        assignment[i] = -1;
    }

    // Loop until no changes in assignments
    int flag = 1;
    while (flag == 1) {
        flag = assign_points(data, size, clusters, assignment);
        move_clusters(data, size, clusters, assignment);
    }

    print_clusters(clusters);

    return 0;
}

// Initialize clusters randomly
void init_clusters(float data[][2], int size, int clusters[][2]) {
    for (int i = 0; i < K; i++) {
        int index = rand() % size;
        clusters[i][0] = data[index][0];
        clusters[i][1] = data[index][1];
    }
}

// Calculate euclidean distance between two points
float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Assign each point to the nearest cluster
// Return 1 if any assignments change, else 0
int assign_points(float data[][2], int size, int clusters[][2], int assignment[]) {
    int flag = 0;
    float min_dist, temp_dist;
    int cluster_index;

    for (int i = 0; i < size; i++) {
        min_dist = 10000;
        for (int j = 0; j < K; j++) {
            temp_dist = distance(data[i][0], data[i][1], clusters[j][0], clusters[j][1]);
            if (temp_dist < min_dist) {
                min_dist = temp_dist;
                cluster_index = j;
            }
        }
        if (assignment[i] != cluster_index) {
            assignment[i] = cluster_index;
            flag = 1;
        }
    }

    return flag;
}

// Move each cluster to the average position of its assigned points
void move_clusters(float data[][2], int size, int clusters[][2], int assignment[]) {
    int count[K] = {0};
    float x_sum[K] = {0};
    float y_sum[K] = {0};

    // Calculate sum of x and y values for each cluster
    for (int i = 0; i < size; i++) {
        count[assignment[i]]++;
        x_sum[assignment[i]] += data[i][0];
        y_sum[assignment[i]] += data[i][1];
    }

    // Calculate average position for each cluster
    for (int i = 0; i < K; i++) {
        if (count[i] > 0) {
            clusters[i][0] = (int) (x_sum[i] / count[i]);
            clusters[i][1] = (int) (y_sum[i] / count[i]);
        }
    }
}

// Print the final position of the clusters
void print_clusters(int clusters[][2]) {
    printf("Final clusters:\n");
    for (int i = 0; i < K; i++) {
        printf("(%d, %d)\n", clusters[i][0], clusters[i][1]);
    }
}