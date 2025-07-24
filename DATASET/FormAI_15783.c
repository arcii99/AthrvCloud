//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // number of clusters
#define N 10 // number of data points
#define D 2 // number of dimensions

typedef struct {
    double x[D]; // data point with D dimensions
    int cluster; // the cluster that this data point belongs to
} DataPoint;

typedef struct {
    DataPoint centroid; // the center of the cluster
    int num_points; // the number of data points in the cluster
} Cluster;

// calculate the Euclidean distance between two data points
double distance(DataPoint p1, DataPoint p2) {
    double sum = 0;
    int i;
    for (i = 0; i < D; i++) {
        sum += pow(p1.x[i] - p2.x[i], 2);
    }
    return sqrt(sum);
}

// initialize the clusters randomly
void init_clusters(DataPoint data[], Cluster clusters[]) {
    int i, j, k;
    int indices[N];
    for (i = 0; i < N; i++) {
        indices[i] = i;
    }
    for (k = 0; k < K; k++) {
        // shuffle the indices
        for (i = N - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = indices[i];
            indices[i] = indices[j];
            indices[j] = temp;
        }
        // set the centroid to be the first data point in the shuffled list
        clusters[k].centroid = data[indices[0]];
        clusters[k].num_points = 0;
        // assign the rest of the data points to the cluster that is closest to their centroid
        for (i = 1; i < N; i++) {
            double min_dist = distance(clusters[k].centroid, data[indices[i]]);
            int closest_point = indices[i];
            for (j = 0; j < i; j++) {
                double dist = distance(clusters[k].centroid, data[indices[j]]);
                if (dist < min_dist) {
                    min_dist = dist;
                    closest_point = indices[j];
                }
            }
            data[closest_point].cluster = k;
            clusters[k].num_points++;
            // update the centroid of the cluster
            int num_points_so_far = clusters[k].num_points - 1;
            for (j = 0; j < D; j++) {
                clusters[k].centroid.x[j] = (num_points_so_far * clusters[k].centroid.x[j] + data[closest_point].x[j]) / clusters[k].num_points;
            }
        }
    }
}

// perform one iteration of the k-means algorithm
void k_means(DataPoint data[], Cluster clusters[]) {
    int i, j, k;
    // assign each data point to the closest cluster
    for (i = 0; i < N; i++) {
        double min_dist = distance(data[i], clusters[0].centroid);
        int closest_cluster = 0;
        for (j = 1; j < K; j++) {
            double dist = distance(data[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                closest_cluster = j;
            }
        }
        data[i].cluster = closest_cluster;
    }
    // recompute the centroids of the clusters
    for (k = 0; k < K; k++) {
        clusters[k].num_points = 0;
        for (j = 0; j < D; j++) {
            clusters[k].centroid.x[j] = 0;
        }
    }
    for (i = 0; i < N; i++) {
        int cluster_id = data[i].cluster;
        clusters[cluster_id].num_points++;
        for (j = 0; j < D; j++) {
            clusters[cluster_id].centroid.x[j] += data[i].x[j];
        }
    }
    for (k = 0; k < K; k++) {
        if (clusters[k].num_points > 0) {
            for (j = 0; j < D; j++) {
                clusters[k].centroid.x[j] /= clusters[k].num_points;
            }
        }
    }
}

// print the results
void print_results(DataPoint data[], Cluster clusters[]) {
    int i, k;
    for (k = 0; k < K; k++) {
        printf("Cluster %d:\n", k);
        printf("Centroid: (");
        for (i = 0; i < D; i++) {
            printf("%.2lf", clusters[k].centroid.x[i]);
            if (i < D - 1) {
                printf(", ");
            }
        }
        printf(")\n");
        printf("Data points:\n");
        for (i = 0; i < N; i++) {
            if (data[i].cluster == k) {
                printf("(");
                int j;
                for (j = 0; j < D; j++) {
                    printf("%.2lf", data[i].x[j]);
                    if (j < D - 1) {
                        printf(", ");
                    }
                }
                printf(")\n");
            }
        }
    }
}

int main() {
    // generate some random data
    DataPoint data[N];
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < D; j++) {
            data[i].x[j] = (double) rand() / RAND_MAX;
        }
        data[i].cluster = -1;
    }
    // initialize the clusters
    Cluster clusters[K];
    init_clusters(data, clusters);
    // run the k-means algorithm
    int max_iterations = 100;
    int iteration;
    for (iteration = 0; iteration < max_iterations; iteration++) {
        k_means(data, clusters);
    }
    // print the results
    print_results(data, clusters);
    return 0;
}