//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 50
#define MAX_ITERATIONS 1000

// Definition of the Point Struct
typedef struct point_t
{
    double x;
    double y;
} Point;

// Definition of the Clusters Struct
typedef struct cluster_t
{
    Point centroid;
    Point points[MAX_POINTS];
    int num_points;
} Cluster;

// Calculate the Euclidean Distance Between Two Points
double euclidean_distance(Point p1, Point p2)
{
    double x_diff = p2.x - p1.x;
    double y_diff = p2.y - p1.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// Find the Nearest Cluster to a Point
void find_nearest_cluster(Point point, Cluster clusters[], int k, int *nearest_cluster_index, double *min_distance)
{
    *nearest_cluster_index = 0;
    *min_distance = euclidean_distance(point, clusters[0].centroid);
    for (int i = 1; i < k; i++)
    {
        double distance = euclidean_distance(point, clusters[i].centroid);
        if (distance < *min_distance)
        {
            *nearest_cluster_index = i;
            *min_distance = distance;
        }
    }
}

// Update the Centroids of All Clusters
void update_centroids(Cluster clusters[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (clusters[i].num_points > 0)
        {
            double total_x = 0;
            double total_y = 0;
            for (int j = 0; j < clusters[i].num_points; j++)
            {
                total_x += clusters[i].points[j].x;
                total_y += clusters[i].points[j].y;
            }
            clusters[i].centroid.x = total_x / clusters[i].num_points;
            clusters[i].centroid.y = total_y / clusters[i].num_points;
        }
    }
}

// Perform the K-Means Clustering Algorithm
void k_means(Point points[], int n, Cluster clusters[], int k)
{
    int iterations = 0;
    int nearest_cluster_index;
    double min_distance;
    while (iterations < MAX_ITERATIONS)
    {
        // Assign each point to its nearest cluster
        for (int i = 0; i < n; i++)
        {
            find_nearest_cluster(points[i], clusters, k, &nearest_cluster_index, &min_distance);
            clusters[nearest_cluster_index].points[clusters[nearest_cluster_index].num_points++] = points[i];
        }

        // Update the centroids of all clusters
        update_centroids(clusters, k);

        // Check if clusters have changed
        int changed = 0;
        for (int i = 0; i < k; i++)
        {
            if (clusters[i].num_points == 0)
            {
                // If an empty cluster is found, pick a random point as its centroid
                int random_index = rand() % n;
                clusters[i].centroid = points[random_index];
                changed = 1;
            }
            else
            {
                for (int j = 0; j < clusters[i].num_points; j++)
                {
                    if (clusters[i].points[j].x != clusters[i].centroid.x || clusters[i].points[j].y != clusters[i].centroid.y)
                    {
                        changed = 1;
                    }
                }
            }
            clusters[i].num_points = 0;
        }

        // If clusters have not changed, break out of loop
        if (!changed)
        {
            break;
        }

        iterations++;
    }
}

// Main Function
int main()
{
    printf("Welcome to the K-Means Clustering Algorithm Implementation Program!\n\n");

    // Define the data points
    Point points[] = {
        {2, 3},
        {4, 5},
        {3, 6},
        {5, 7},
        {12, 15},
        {10, 13},
        {11, 14},
        {13, 16},
        {27, 30},
        {28, 32},
        {29, 31},
        {31, 34},
        {33, 36},
        {37, 40},
        {40, 42},
        {42, 44},
        {47, 49},
        {49, 51},
        {52, 55},
        {55, 60},
        {61, 65},
        {63, 68},
        {69, 72},
        {70, 71},
        {74, 77},
        {78, 80}};

    int n = sizeof(points) / sizeof(points[0]);

    // Define the number of clusters
    int k = 3;

    // Initialize the clusters
    Cluster clusters[k];
    for (int i = 0; i < k; i++)
    {
        clusters[i].centroid = points[i];
    }

    // Apply the K-Means Clustering Algorithm
    k_means(points, n, clusters, k);

    // Print the Clusters
    for (int i = 0; i < k; i++)
    {
        printf("Cluster %d:\n", i + 1);
        for (int j = 0; j < clusters[i].num_points; j++)
        {
            printf("(%0.1f, %0.1f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    printf("Thank you for using the K-Means Clustering Algorithm Implementation Program!\n");

    return 0;
}