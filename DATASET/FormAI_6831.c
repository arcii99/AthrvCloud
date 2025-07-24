//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3
#define MAX_ITERATIONS 1000
#define THRESHOLD 0.001

typedef struct
{
    float x, y;
    int cluster_id;
} point_t;

typedef struct
{
    int n_points;
    point_t* points[K];
} cluster_t;

void initialize_clusters(cluster_t clusters[])
{
    int i, j;
    float x, y;

    for (i = 0; i < K; i++)
    {
        x = (float) rand() / RAND_MAX;
        y = (float) rand() / RAND_MAX;

        clusters[i].n_points = 0;

        for (j = 0; j < K; j++)
        {
            clusters[i].points[j] = NULL;
        }

        clusters[i].points[clusters[i].n_points++] = malloc(sizeof(point_t));
        clusters[i].points[clusters[i].n_points - 1]->x = x;
        clusters[i].points[clusters[i].n_points - 1]->y = y;
    }
}

void assign_cluster(point_t* point, cluster_t clusters[])
{
    int i, cluster_id;
    float distance, min_distance = INFINITY;

    for (i = 0; i < K; i++)
    {
        distance = sqrt(pow(point->x - clusters[i].points[0]->x, 2) + pow(point->y - clusters[i].points[0]->y, 2));

        if (distance < min_distance)
        {
            min_distance = distance;
            cluster_id = i;
        }
    }

    point->cluster_id = cluster_id;
    clusters[cluster_id].points[clusters[cluster_id].n_points++] = point;
}

void update_clusters(cluster_t clusters[])
{
    int i, j, k;
    float sum_x, sum_y;

    for (i = 0; i < K; i++)
    {
        sum_x = sum_y = 0;

        for (j = 0; j < clusters[i].n_points; j++)
        {
            sum_x += clusters[i].points[j]->x;
            sum_y += clusters[i].points[j]->y;
        }

        clusters[i].points[0]->x = sum_x / clusters[i].n_points;
        clusters[i].points[0]->y = sum_y / clusters[i].n_points;

        for (j = 1; j < clusters[i].n_points; j++)
        {
            free(clusters[i].points[j]);
            clusters[i].points[j] = NULL;
        }

        clusters[i].n_points = 1;
    }
}

float calculate_error(cluster_t clusters[])
{
    int i, j;
    float error = 0;

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < clusters[i].n_points; j++)
        {
            error += pow(clusters[i].points[j]->x - clusters[i].points[0]->x, 2) + pow(clusters[i].points[j]->y - clusters[i].points[0]->y, 2);
        }
    }

    return error;
}

void print_clusters(cluster_t clusters[])
{
    int i, j;

    for (i = 0; i < K; i++)
    {
        printf("Cluster %d:\n", i);

        for (j = 0; j < clusters[i].n_points; j++)
        {
            printf("\t(%f, %f)\n", clusters[i].points[j]->x, clusters[i].points[j]->y);
        }
    }

    printf("\n");
}

int main()
{
    int i;
    float error = INFINITY, prev_error = INFINITY;
    point_t* point;
    cluster_t clusters[K];

    srand(time(NULL));

    initialize_clusters(clusters);

    for (i = 0; i < MAX_ITERATIONS && fabs(error - prev_error) > THRESHOLD; i++)
    {
        prev_error = error;
        error = 0;

        for (i = 0; i < K; i++)
        {
            clusters[i].n_points = 1;
        }

        while ((point = malloc(sizeof(point_t))) != NULL && scanf("%f %f", &point->x, &point->y) == 2)
        {
            assign_cluster(point, clusters);
        }

        update_clusters(clusters);
        error = calculate_error(clusters);
    }

    print_clusters(clusters);

    return 0;
}