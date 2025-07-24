//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find distance between two points
double calc_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Function to find the nearest cluster 
int find_nearest_cluster(double *centroids, double x, double y, int k) {
    int nearest_cluster = 0;
    double distance, min_distance = calc_distance(x, y, centroids[0], centroids[1]);
    for(int i=2; i<2*k; i=i+2) {
        distance = calc_distance(x, y, centroids[i], centroids[i+1]);
        if(distance < min_distance) {
            min_distance = distance;
            nearest_cluster = i/2;
        }
    }
    return nearest_cluster;
}

// Function to calculate new centroids
void calc_centroids(double *points, int *labels, double *centroids, int m, int k) {
    int count;
    double x_sum, y_sum;
    for(int i=0; i<k; i++) {
        count = 0;
        x_sum = 0;
        y_sum = 0;
        for(int j=0; j<m; j++) {
            if(labels[j] == i) {
                x_sum += points[2*j];
                y_sum += points[2*j+1];
                count++;
            }
        }
        centroids[2*i] = x_sum/count;
        centroids[2*i+1] = y_sum/count;
    }
}

int main() {
    int k, m;
    printf("Enter number of clusters: ");
    scanf("%d", &k);
    printf("Enter number of data points: ");
    scanf("%d", &m);
    
    double *points = (double*)malloc(2*m*sizeof(double));
    printf("Enter data points (x y) separated by space:\n");
    for(int i=0; i<m; i++) {
        scanf("%lf %lf", &points[2*i], &points[2*i+1]);
    }
    
    double *centroids = (double*)malloc(2*k*sizeof(double));
    printf("Enter initial cluster centroids (x y) separated by space:\n");
    for(int i=0; i<k; i++) {
        scanf("%lf %lf", &centroids[2*i], &centroids[2*i+1]);
    }
    
    int *labels = (int*)malloc(m*sizeof(int));
    int nearest_cluster;
    for(int i=0; i<m; i++) {
        nearest_cluster = find_nearest_cluster(centroids, points[2*i], points[2*i+1], k);
        labels[i] = nearest_cluster;
    }
    
    // Iterations for finding optimum centroids
    int iteration = 0;
    int max_iterations = 100;
    while(iteration < max_iterations) {
        printf("\nIteration %d:\n", iteration+1);
        calc_centroids(points, labels, centroids, m, k);
        for(int i=0; i<k; i++) {
            printf("Centroid %d: (%.3lf, %.3lf)\n", i+1, centroids[2*i], centroids[2*i+1]);
        }
        int changed = 0;
        for(int i=0; i<m; i++) {
            nearest_cluster = find_nearest_cluster(centroids, points[2*i], points[2*i+1], k);
            if(labels[i] != nearest_cluster) {
                labels[i] = nearest_cluster;
                changed = 1;
            }
        }
        if(changed == 0) {
            printf("\nConverged after %d iterations.\n", iteration+1);
            break;
        }
        iteration++;
    }
    
    printf("\nFinal labels:\n");
    for(int i=0; i<m; i++) {
        printf("%d ", labels[i]+1);
    }
    
    free(points);
    free(centroids);
    free(labels);
    
    return 0;
}