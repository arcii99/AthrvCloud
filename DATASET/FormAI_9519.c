//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// define the number of clusters we want to find
#define NUM_CLUSTERS 3

// define the maximum number of iterations for the algorithm
#define MAX_ITERATIONS 50

// define the threshold for stopping the algorithm
#define THRESHOLD 0.01

// define the structure representing a data point in our example
struct data_point
{
    double x;
    double y;
};

// define the structure representing a cluster of data points
struct cluster
{
    struct data_point centroid;
    struct data_point *members;
    int num_members;
};

// function to initialize the clusters with initial centroids
void initialize_clusters(struct data_point *data, int num_data_points, struct cluster *clusters, int num_clusters)
{
    // randomly select initial centroids for each cluster from the data points
    for (int i = 0; i < num_clusters; i++)
    {
        int random_index = rand() % num_data_points;
        clusters[i].centroid = data[random_index];
    }
}

// function to calculate the Euclidean distance between two data points
double euclidean_distance(struct data_point p1, struct data_point p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// function to assign each data point to a cluster based on its distance to the centroids
void assign_to_clusters(struct data_point *data, int num_data_points, struct cluster *clusters, int num_clusters)
{
    // for each data point, calculate its distance to each cluster centroid
    for (int i = 0; i < num_data_points; i++)
    {
        double min_distance = INFINITY;
        int closest_cluster_index = -1;

        for (int j = 0; j < num_clusters; j++)
        {
            double distance = euclidean_distance(data[i], clusters[j].centroid);
            if (distance < min_distance)
            {
                min_distance = distance;
                closest_cluster_index = j;
            }
        }

        // add the data point to the closest cluster
        clusters[closest_cluster_index].members[clusters[closest_cluster_index].num_members++] = data[i];
    }
}

// function to update the centroids of each cluster based on the members of the cluster
void update_centroids(struct cluster *clusters, int num_clusters)
{
    for (int i = 0; i < num_clusters; i++)
    {
        double sum_x = 0.0;
        double sum_y = 0.0;

        for (int j = 0; j < clusters[i].num_members; j++)
        {
            sum_x += clusters[i].members[j].x;
            sum_y += clusters[i].members[j].y;
        }

        clusters[i].centroid.x = sum_x / clusters[i].num_members;
        clusters[i].centroid.y = sum_y / clusters[i].num_members;
    }
}

// function to print the current status of the clusters (for debugging purposes)
void print_clusters(struct cluster *clusters, int num_clusters)
{
    for (int i = 0; i < num_clusters; i++)
    {
        printf("Cluster %d:\n", i);
        printf("Centroid: (%lf, %lf)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Members:\n");
        for (int j = 0; j < clusters[i].num_members; j++)
        {
            printf("(%lf, %lf)\n", clusters[i].members[j].x, clusters[i].members[j].y);
        }
        printf("\n");
    }
}

// function to check if the algorithm has converged (i.e., the centroids have stopped changing by more than the threshold)
bool has_converged(struct cluster *clusters, int num_clusters, struct cluster *prev_clusters)
{
    for (int i = 0; i < num_clusters; i++)
    {
        if (euclidean_distance(clusters[i].centroid, prev_clusters[i].centroid) > THRESHOLD)
        {
            return false;
        }
    }
    return true;
}

// the main function
int main()
{
    // define some example data points
    struct data_point data[] = {
        {1.0, 1.0},
        {2.0, 1.0},
        {1.5, 2.0},
        {8.0, 6.0},
        {9.0, 8.0},
        {7.0, 8.0}
    };
    int num_data_points = sizeof(data) / sizeof(struct data_point);

    // define the clusters
    struct cluster clusters[NUM_CLUSTERS];
    for (int i = 0; i < NUM_CLUSTERS; i++)
    {
        clusters[i].members = malloc(num_data_points * sizeof(struct data_point));
        clusters[i].num_members = 0;
    }

    // initialize the clusters with random centroids
    initialize_clusters(data, num_data_points, clusters, NUM_CLUSTERS);

    // run the main loop of the algorithm
    int num_iterations = 0;
    while (num_iterations < MAX_ITERATIONS)
    {
        // assign each data point to a cluster based on its distance to the centroids
        assign_to_clusters(data, num_data_points, clusters, NUM_CLUSTERS);

        // update the centroids of each cluster based on the members of the cluster
        struct cluster prev_clusters[NUM_CLUSTERS];
        for (int i = 0; i < NUM_CLUSTERS; i++)
        {
            prev_clusters[i] = clusters[i];
        }
        update_centroids(clusters, NUM_CLUSTERS);

        // check if the algorithm has converged
        if (has_converged(clusters, NUM_CLUSTERS, prev_clusters))
        {
            break;
        }

        // print the current status of the clusters (for debugging purposes)
        printf("Iteration %d:\n", num_iterations);
        print_clusters(clusters, NUM_CLUSTERS);
        printf("\n");

        // reset the members of each cluster for the next iteration
        for (int i = 0; i < NUM_CLUSTERS; i++)
        {
            clusters[i].num_members = 0;
        }

        num_iterations++;
    }

    // print the final clusters
    printf("Final clusters:\n");
    print_clusters(clusters, NUM_CLUSTERS);

    // free the memory allocated for the members of each cluster
    for (int i = 0; i < NUM_CLUSTERS; i++)
    {
        free(clusters[i].members);
    }

    return 0;
}