//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Claude Shannon
/* Welcome to the Clustering Algorithm Simulator */
/* By Claude the Coder */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Initializing constants */
#define MAX_POINTS 50 /* Let's cluster up to 50 points */
#define MAX_CLUSTERS 10 /* Let's have a maximum of 10 clusters */
#define MIN_COORD -100 /* Minimum coordinate value */
#define MAX_COORD 100 /* Maximum coordinate value */
#define MAX_ITER 100 /* Maximum number of iterations to find the optimal clustering */

/* Defining a point with coordinates */
typedef struct Point {
    double x;
    double y;
} Point;

/* Defining a cluster with a centroid and a point list */
typedef struct Cluster {
    Point centroid;
    Point points[MAX_POINTS];
    int num_points;
} Cluster;

/* Function declarations */
double distance(Point p1, Point p2);
int assign_points_to_clusters(Point points[], int num_points, Cluster clusters[], int num_clusters);
void recalculate_centroids(Cluster clusters[], int num_clusters);
void simulate_clustering(Point points[], int num_points);

/* The main function */
int main() {
    srand(time(NULL)); /* Initializing the random number generator */

    printf("Welcome to the Clustering Algorithm Simulator!\n");
    printf("I am Claude the Coder, here to help you cluster your data points.\n");

    Point points[MAX_POINTS];
    int num_points;

    printf("Please enter the number of points you want to cluster (up to %d): ",MAX_POINTS);
    scanf("%d", &num_points);

    /* Initializing random points */
    for(int i=0; i<num_points; i++) {
        points[i].x = (double) (MIN_COORD + rand() % (MAX_COORD - MIN_COORD + 1));
        points[i].y = (double) (MIN_COORD + rand() % (MAX_COORD - MIN_COORD + 1));
    }

    simulate_clustering(points, num_points);

    printf("Thank you for using the Clustering Algorithm Simulator. Have a nice day!");
    return 0;
}

/* Function to calculate the Euclidean distance between two points */
double distance(Point p1, Point p2) { 
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

/* Function to assign each point to its closest cluster */
int assign_points_to_clusters(Point points[], int num_points, Cluster clusters[], int num_clusters) {
    int num_changes = 0;

    for(int i=0; i<num_points; i++) {
        double min_dist = distance(points[i], clusters[0].centroid); /* Initializing the minimum distance */
        int min_cluster_idx = 0; /* Initializing the minimum cluster index */

        /* Finding the closest cluster centroid */
        for(int j=1; j<num_clusters; j++) {
            double curr_dist = distance(points[i], clusters[j].centroid);
            if(curr_dist < min_dist) {
                min_dist = curr_dist;
                min_cluster_idx = j;
            }
        }

        /* Updating the cluster to which the point belongs */
        if(clusters[min_cluster_idx].num_points < MAX_POINTS) { /* Checking if the cluster is full */
            clusters[min_cluster_idx].points[clusters[min_cluster_idx].num_points++] = points[i];
            num_changes++;
        }
    }
    return num_changes;
}

/* Function to recalculate each cluster centroid */
void recalculate_centroids(Cluster clusters[], int num_clusters) {
    for(int i=0; i<num_clusters; i++) {
        double sum_x = 0, sum_y = 0;

        for(int j=0; j<clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }

        clusters[i].centroid.x = sum_x / clusters[i].num_points;
        clusters[i].centroid.y = sum_y / clusters[i].num_points;

        /* Clearing the point list */
        clusters[i].num_points = 0;
    }
}

/* Function to simulate the clustering algorithm */
void simulate_clustering(Point points[], int num_points) {
    int num_clusters;

    printf("Please enter the number of clusters you want to form (up to %d): ",MAX_CLUSTERS);
    scanf("%d", &num_clusters);

    /* Initializing random clusters with centroids */
    Cluster clusters[num_clusters];
    for(int i=0; i<num_clusters; i++) {
        clusters[i].centroid.x = (double) (MIN_COORD + rand() % (MAX_COORD - MIN_COORD + 1));
        clusters[i].centroid.y = (double) (MIN_COORD + rand() % (MAX_COORD - MIN_COORD + 1));
        clusters[i].num_points = 0;
    }

    /* Iterating until convergence or maximum number of iterations */
    int iter = 0;
    int num_changes;
    do {
        printf("Iteration #%d:\n",++iter);
        num_changes = assign_points_to_clusters(points, num_points, clusters, num_clusters);
        recalculate_centroids(clusters, num_clusters);

        /* Printing the clusters information */
        for(int i=0; i<num_clusters; i++) {
            printf("Cluster #%d: Centroid=(%.1f,%.1f) Points=",i+1,clusters[i].centroid.x,clusters[i].centroid.y);
            for(int j=0; j<clusters[i].num_points; j++)
                printf("(%.1f,%.1f) ",clusters[i].points[j].x,clusters[i].points[j].y);
            printf("\n");
        }

        /* Checking if there were any changes in the cluster assignments */
        if(num_changes==0) {
            printf("No changes in cluster assignments. Clustering converged.\n");
            break;
        }
    } while(iter<MAX_ITER);

    printf("Clustering simulation finished after %d iterations and %d point-to-cluster assignments.\n",iter,num_points);
}