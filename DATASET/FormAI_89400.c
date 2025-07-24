//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10           //Number of data points
#define DIM 2          //Number of dimensions
#define K 3            //Number of clusters
#define MAX_ITER 1000  //Maximum number of iterations

//Function to calculate Euclidean distance
double distance(int dim, double *a, double *b) {
    double dist = 0;
    for(int i=0; i<dim; i++) {
        dist += pow((a[i] - b[i]), 2);
    }
    return sqrt(dist);
}

//Function to randomly initialize centroids
void initialize_centroids(int dim, int n, int k, double *data, double *centroids) {
    for(int i=0; i<k; i++) {
        int index = rand() % n;
        for(int j=0; j<dim; j++) {
            centroids[i*dim+j] = data[index*dim+j];
        }
    }
}

//Function to assign data points to clusters
void assign_clusters(int dim, int n, int k, double *data, double *centroids, int *clusters) {
    for(int i=0; i<n; i++) {
        double min_dist = INFINITY;
        int c = 0;
        for(int j=0; j<k; j++) {
            double dist = distance(dim, &data[i*dim], &centroids[j*dim]);
            if(dist < min_dist) {
                min_dist = dist;
                c = j;
            }
        }
        clusters[i] = c;
    }
}

//Function to update centroids
void update_centroids(int dim, int n, int k, double *data, int *clusters, double *centroids) {
    for(int i=0; i<k; i++) {
        int count = 0;
        for(int j=0; j<dim; j++) {
            centroids[i*dim+j] = 0;
        }
        for(int j=0; j<n; j++) {
            if(clusters[j] == i) {
                count++;
                for(int l=0; l<dim; l++) {
                    centroids[i*dim+l] += data[j*dim+l];
                }
            }
        }
        for(int j=0; j<dim; j++) {
            centroids[i*dim+j] /= count;
        }
    }
}

//Main function
int main() {
    //Data generation
    double data[N][DIM] = {{1,2}, {1.5,1.8}, {5,8}, {8,8}, {1,0.6},
                           {9,11}, {12,12}, {3,2}, {4,4}, {3.5,3.5}};
                           
    //Centroids initialization                        
    double centroids[K][DIM];
    srand(0);
    initialize_centroids(DIM, N, K, &data[0][0], &centroids[0][0]);
    
    //Cluster assignment and centroid update
    int clusters[N];
    for(int iter=0; iter<MAX_ITER; iter++) {
        assign_clusters(DIM, N, K, &data[0][0], &centroids[0][0], &clusters[0]);
        update_centroids(DIM, N, K, &data[0][0], &clusters[0], &centroids[0][0]);
    }
    
    //Printing output
    for(int i=0; i<K; i++) {
        printf("Cluster %d: ", i);
        for(int j=0; j<N; j++) {
            if(clusters[j] == i) {
                printf("(%lf, %lf) ", data[j][0], data[j][1]);
            }
        }
        printf("\nCentroid %d: (%lf, %lf)\n\n", i, centroids[i][0], centroids[i][1]);
    }
    
    return 0;
}