//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// A struct that represents a point in 3D space
typedef struct Point
{
    double x;
    double y;
    double z;
} Point;

// A struct that represents a cluster of points
typedef struct Cluster
{
    Point center;
    Point *points;
    int size;
} Cluster;

// A function that calculates the distance between two points
double distance(Point p1, Point p2)
{
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    double z_diff = p1.z - p2.z;
    return sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
}

// A function that finds the closest cluster to a given point
int find_closest_cluster(Point p, Cluster *clusters, int num_clusters)
{
    int closest_cluster_index = 0;
    double min_distance = distance(p, clusters[0].center);
    for (int i = 1; i < num_clusters; i++)
    {
        double d = distance(p, clusters[i].center);
        if (d < min_distance)
        {
            closest_cluster_index = i;
            min_distance = d;
        }
    }
    return closest_cluster_index;
}

// A function that updates each cluster's center based on its points
void update_cluster_centers(Cluster *clusters, int num_clusters)
{
    for (int i = 0; i < num_clusters; i++)
    {
        Point new_center = {0, 0, 0};
        for (int j = 0; j < clusters[i].size; j++)
        {
            new_center.x += clusters[i].points[j].x;
            new_center.y += clusters[i].points[j].y;
            new_center.z += clusters[i].points[j].z;
        }
        new_center.x /= clusters[i].size;
        new_center.y /= clusters[i].size;
        new_center.z /= clusters[i].size;
        clusters[i].center = new_center;
    }
}

// A function that performs the clustering algorithm
void cluster_points(Point *points, int num_points, Cluster *clusters, int num_clusters, int max_iterations)
{
    // Initialize each cluster's center to a random point
    for (int i = 0; i < num_clusters; i++)
    {
        int random_index = rand() % num_points;
        clusters[i].center = points[random_index];
    }

    // Perform the clustering algorithm for the maximum number of iterations or until convergence
    int iteration = 0;
    while (iteration < max_iterations)
    {
        // Assign each point to the closest cluster
        for (int i = 0; i < num_points; i++)
        {
            int closest_cluster_index = find_closest_cluster(points[i], clusters, num_clusters);
            clusters[closest_cluster_index].points[clusters[closest_cluster_index].size++] = points[i];
        }

        // Update each cluster's center
        update_cluster_centers(clusters, num_clusters);

        // Reset each cluster's points
        for (int i = 0; i < num_clusters; i++)
        {
            clusters[i].size = 0;
            free(clusters[i].points);
            clusters[i].points = malloc(num_points * sizeof(Point));
        }

        iteration++;
    }
}

int main()
{
    // Create an array of points
    Point points[] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18},
        {19, 20, 21},
        {22, 23, 24},
        {25, 26, 27},
        {28, 29, 30}};

    int num_points = sizeof(points) / sizeof(Point);

    // Create an array of clusters
    int num_clusters = 3;
    Cluster *clusters = malloc(num_clusters * sizeof(Cluster));
    for (int i = 0; i < num_clusters; i++)
    {
        clusters[i].size = 0;
        clusters[i].points = malloc(num_points * sizeof(Point));
    }

    // Cluster the points
    int max_iterations = 100;
    cluster_points(points, num_points, clusters, num_clusters, max_iterations);

    // Print the final cluster centers
    for (int i = 0; i < num_clusters; i++)
    {
        printf("Cluster %d center: (%f, %f, %f)\n", i + 1, clusters[i].center.x, clusters[i].center.y, clusters[i].center.z);
    }

    // Free memory
    for (int i = 0; i < num_clusters; i++)
    {
        free(clusters[i].points);
    }
    free(clusters);

    return 0;
}