//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define a struct to represent a datapoint in the dataset
typedef struct datapoint {
    double x;
    double y;
    double z;
} datapoint;

//Define a struct to represent a cluster of datapoints
typedef struct cluster {
    datapoint centroid;
    datapoint* points;
    int num_points;
    int max_points;
} cluster;

//Define a function to compute the Euclidean distance between two datapoints
double distance(datapoint a, datapoint b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

//Define a function to initialize a new cluster
cluster* create_cluster(datapoint centroid, int max_points) {
    cluster* c = malloc(sizeof(cluster));
    c->centroid = centroid;
    c->points = malloc(max_points * sizeof(datapoint));
    c->num_points = 0;
    c->max_points = max_points;
    return c;
}

//Define a function to add a datapoint to a cluster
void add_point_to_cluster(cluster* c, datapoint p) {
    if(c->num_points < c->max_points) {
        c->points[c->num_points] = p;
        c->num_points++;
    }
}

//Define a function to compute the centroid of a cluster
datapoint compute_centroid(cluster* c) {
    double x_sum = 0;
    double y_sum = 0;
    double z_sum = 0;
    for(int i=0; i<c->num_points; i++) {
        x_sum += c->points[i].x;
        y_sum += c->points[i].y;
        z_sum += c->points[i].z;
    }
    datapoint centroid = { x_sum/c->num_points, y_sum/c->num_points, z_sum/c->num_points};
    return centroid;
}

int main() {

    //Initialize the dataset
    datapoint dataset[10] = { {1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}, {5, 6, 7}, {6, 7, 8}, {7, 8, 9}, {8, 9, 10}, {9, 10, 11}, {10, 11, 12}};

    //Initialize the clusters
    cluster* cluster1 = create_cluster(dataset[0], 5);
    cluster* cluster2 = create_cluster(dataset[9], 5);

    //Assign datapoints to initial clusters
    for(int i=0; i<10; i++) {
        if(distance(dataset[i], cluster1->centroid) < distance(dataset[i], cluster2->centroid)) {
            add_point_to_cluster(cluster1, dataset[i]);
        }
        else {
            add_point_to_cluster(cluster2, dataset[i]);
        }
    }

    //Compute initial centroids
    cluster1->centroid = compute_centroid(cluster1);
    cluster2->centroid = compute_centroid(cluster2);

    //Perform clustering iterations
    for(int i=0; i<10; i++) {
        for(int j=0; j<cluster1->num_points; j++) {
            if(distance(cluster1->points[j], cluster2->centroid) < distance(cluster1->points[j], cluster1->centroid)) {
                datapoint p = cluster1->points[j];
                add_point_to_cluster(cluster2, p);
                cluster1->num_points--;
                for(int k=j; k<cluster1->num_points; k++) {
                    cluster1->points[k] = cluster1->points[k+1];
                }
            }
        }
        cluster1->centroid = compute_centroid(cluster1);
        cluster2->centroid = compute_centroid(cluster2);
    }

    //Print final clusters
    printf("Cluster 1:\n");
    for(int i=0; i<cluster1->num_points; i++) {
        printf("(%f, %f, %f)\n", cluster1->points[i].x, cluster1->points[i].y, cluster1->points[i].z);
    }
    printf("\nCluster 2:\n");
    for(int i=0; i<cluster2->num_points; i++) {
        printf("(%f, %f, %f)\n", cluster2->points[i].x, cluster2->points[i].y, cluster2->points[i].z);
    }

    return 0;
}