//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_POINTS 100
#define N_CLUSTERS 3
#define N_ITERATIONS 10

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point center;
    int n_points;
    Point *points;
} Cluster;

void init_clusters(Point *points, Cluster *clusters)
{
    int i, j;

    /* Pick N_CLUSTERS random points as cluster centers */
    for(i = 0; i < N_CLUSTERS; i++) {
        clusters[i].center = points[rand() % N_POINTS];
        clusters[i].n_points = 0;
        clusters[i].points = NULL;
    }

    /* Assign each point to the closest cluster center */
    for(i = 0; i < N_POINTS; i++) {
        float best_dist = 1e9;
        int best_cluster = 0;

        for(j = 0; j < N_CLUSTERS; j++) {
            float dist = (points[i].x - clusters[j].center.x) * (points[i].x - clusters[j].center.x) +
                         (points[i].y - clusters[j].center.y) * (points[i].y - clusters[j].center.y);

            if(dist < best_dist) {
                best_dist = dist;
                best_cluster = j;
            }
        }

        clusters[best_cluster].n_points++;
        clusters[best_cluster].points = (Point *) realloc(clusters[best_cluster].points, clusters[best_cluster].n_points * sizeof(Point));
        clusters[best_cluster].points[clusters[best_cluster].n_points - 1] = points[i];
    }
}

void compute_cluster_centers(Cluster *clusters)
{
    int i, j;

    for(i = 0; i < N_CLUSTERS; i++) {
        float sum_x = 0.0, sum_y = 0.0;
        int n_points = clusters[i].n_points;

        for(j = 0; j < n_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }

        if(n_points > 0) {
            clusters[i].center.x = sum_x / n_points;
            clusters[i].center.y = sum_y / n_points;
        }
    }
}

int main()
{
    Point points[N_POINTS];
    Cluster clusters[N_CLUSTERS];
    int i, j, k;

    /* Initialize random seed */
    srand(time(NULL));

    /* Initialize points */
    for(i = 0; i < N_POINTS; i++) {
        points[i].x = (float) rand() / RAND_MAX;
        points[i].y = (float) rand() / RAND_MAX;
    }

    /* Initialize clusters */
    init_clusters(points, clusters);

    for(i = 0; i < N_ITERATIONS; i++) {
        /* Compute new cluster centers */
        compute_cluster_centers(clusters);

        /* Reassign points to clusters */
        for(j = 0; j < N_CLUSTERS; j++)
            clusters[j].n_points = 0;

        for(j = 0; j < N_POINTS; j++) {
            float best_dist = 1e9;
            int best_cluster = 0;

            for(k = 0; k < N_CLUSTERS; k++) {
                float dist = (points[j].x - clusters[k].center.x) * (points[j].x - clusters[k].center.x) +
                             (points[j].y - clusters[k].center.y) * (points[j].y - clusters[k].center.y);

                if(dist < best_dist) {
                    best_dist = dist;
                    best_cluster = k;
                }
            }

            clusters[best_cluster].n_points++;
            clusters[best_cluster].points = (Point *) realloc(clusters[best_cluster].points, clusters[best_cluster].n_points * sizeof(Point));
            clusters[best_cluster].points[clusters[best_cluster].n_points - 1] = points[j];
        }
    }

    /* Print result */
    printf("Final cluster centers:\n");
    for(i = 0; i < N_CLUSTERS; i++)
        printf("(%f, %f)\n", clusters[i].center.x, clusters[i].center.y);

    /* Clean up */
    for(i = 0; i < N_CLUSTERS; i++)
        free(clusters[i].points);

    return 0;
}