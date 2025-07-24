//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define num_points 1000
#define k 5
#define num_iterations 10

float points[num_points][2];
int cluster_id[num_points];
float centroids[k][2];

float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

void initialize_centroids() {
    int i, j;
    for(i=0; i<k; i++) {
        j = rand() % num_points;
        centroids[i][0] = points[j][0];
        centroids[i][1] = points[j][1];
    }
}

void assign_points_to_clusters() {
    int i, j, c;
    float min_dist, dist;
    for(i=0; i<num_points; i++) {
        min_dist = INFINITY;
        for(j=0; j<k; j++) {
            dist = distance(points[i][0], points[i][1], centroids[j][0], centroids[j][1]);
            if(dist < min_dist) {
                min_dist = dist;
                c = j;
            }
        }
        cluster_id[i] = c;
    }
}

void recalculate_centroids() {
    int i, j, count;
    float x_sum, y_sum;
    for(i=0; i<k; i++) {
        count = 0;
        x_sum = 0;
        y_sum = 0;
        for(j=0; j<num_points; j++) {
            if(cluster_id[j] == i) {
                count++;
                x_sum += points[j][0];
                y_sum += points[j][1];
            }
        }
        centroids[i][0] = x_sum/count;
        centroids[i][1] = y_sum/count;
    }
}

void print_clusters() {
    int i, j;
    for(i=0; i<k; i++) {
        printf("Cluster %d:\n", i+1);
        for(j=0; j<num_points; j++) {
            if(cluster_id[j] == i) {
                printf("(%f, %f)\n", points[j][0], points[j][1]);
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j, iter;
    for(i=0; i<num_points; i++) {
        points[i][0] = ((float)rand()/(float)(RAND_MAX)) * 100;
        points[i][1] = ((float)rand()/(float)(RAND_MAX)) * 100;
    }
    initialize_centroids();
    for(iter=0; iter<num_iterations; iter++) {
        assign_points_to_clusters();
        recalculate_centroids();
    }
    print_clusters();
    return 0;
}