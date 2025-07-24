//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

#define K 2 //Number of clusters
#define MAX_ITERATIONS 100 //Maximum number of iterations

struct point {
    double x; //X co-ordinate
    double y; //Y co-ordinate
};

double euclidean_distance(struct point a, struct point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main() {
    struct point data_points[] = {{1, 1}, {2, 1}, {4, 3}, {5, 4}, {6, 5}}; //Sample data points
    int data_point_count = sizeof(data_points)/sizeof(data_points[0]);
    struct point centroids[K]; //Centroids array
    int membership[data_point_count]; //Membership array
    int i, j, k, current_iteration, min_index;
    double min_distance, current_distance, sum_x, sum_y, cluster_size;
    srand(0);

    //Initialize centroids randomly
    for(i = 0; i < K; i++) {
        centroids[i].x = (double)rand()/(double)RAND_MAX * 6;
        centroids[i].y = (double)rand()/(double)RAND_MAX * 5;
    }

    //Perform K-means clustering
    for(current_iteration = 0; current_iteration < MAX_ITERATIONS; current_iteration++) {
        printf("Iteration %d:\n", current_iteration);
        //Assign data points to nearest centroid
        for(i = 0; i < data_point_count; i++) {
            min_index = 0;
            min_distance = euclidean_distance(data_points[i], centroids[0]);
            for(j = 1; j < K; j++) {
                current_distance = euclidean_distance(data_points[i], centroids[j]);
                if(current_distance < min_distance) {
                    min_index = j;
                    min_distance = current_distance;
                }
            }
            membership[i] = min_index;
        }

        //Update centroids
        for(i = 0; i < K; i++) {
            sum_x = 0;
            sum_y = 0;
            cluster_size = 0;
            for(j = 0; j < data_point_count; j++) {
                if(membership[j] == i) {
                    sum_x += data_points[j].x;
                    sum_y += data_points[j].y;
                    cluster_size++;
                }
            }
            if(cluster_size > 0) {
                centroids[i].x = sum_x/cluster_size;
                centroids[i].y = sum_y/cluster_size;
            }
        }

        //Print current centroids
        for(i = 0; i < K; i++) {
            printf("Centroid %d: (%.2f, %.2f)\n", i+1, centroids[i].x, centroids[i].y);
        }
        printf("\n");
    }

    return 0;
}