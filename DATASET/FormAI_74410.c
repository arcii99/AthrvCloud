//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Number of clusters */
#define NUM_CLUSTERS 3

/* Number of data points */
#define NUM_POINTS 10

/* Maximum number of iterations */
#define MAX_ITERATIONS 100

/* Threshold to stop iterating */
#define THRESHOLD 0.0001

/* Data points */
float data[NUM_POINTS][2] = {{1.0, 2.0},
                             {1.5, 1.8},
                             {5.0, 8.0},
                             {8.0, 8.0},
                             {1.0, 1.0},
                             {9.0, 11.0},
                             {4.0, 5.0},
                             {3.5, 4.5},
                             {2.0, 5.0},
                             {10.0, 10.0}};

/* Clusters */
float clusters[NUM_CLUSTERS][2];

/* Cluster assignments */
int assignments[NUM_POINTS];

/* Distance function */
float distance(float x1, float y1, float x2, float y2) 
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

/* Initialize clusters */
void initialize_clusters() 
{
    int i;
    for(i=0; i<NUM_CLUSTERS; i++) 
    {
        int random_index = rand() % NUM_POINTS;
        clusters[i][0] = data[random_index][0];
        clusters[i][1] = data[random_index][1];
    }
}

/* Assign points to clusters */
void assign() 
{
    int i;
    for(i=0; i<NUM_POINTS; i++) 
    {
        float min_distance = distance(data[i][0], data[i][1], clusters[0][0], clusters[0][1]);
        int min_cluster = 0;
        int j;
        for(j=1; j<NUM_CLUSTERS; j++) 
        {
            float dist = distance(data[i][0], data[i][1], clusters[j][0], clusters[j][1]);
            if(dist < min_distance) 
            {
                min_distance = dist;
                min_cluster = j;
            }
        }
        assignments[i] = min_cluster;
    }
}

/* Update clusters */
void update() 
{
    int i, j, count[NUM_CLUSTERS];
    for(i=0; i<NUM_CLUSTERS; i++) 
    {
        clusters[i][0] = 0;
        clusters[i][1] = 0;
        count[i] = 0;
    }
    for(i=0; i<NUM_POINTS; i++) 
    {
        int cluster = assignments[i];
        clusters[cluster][0] += data[i][0];
        clusters[cluster][1] += data[i][1];
        count[cluster]++;
    }
    for(i=0; i<NUM_CLUSTERS; i++) 
    {
        if(count[i] != 0) 
        {
            clusters[i][0] /= count[i];
            clusters[i][1] /= count[i];
        }
    }
}

/* Main function */
int main() 
{
    initialize_clusters();

    int i, j;
    float prev_error = -1;
    for(i=0; i<MAX_ITERATIONS; i++) 
    {
        assign();
        update();

        /* Calculate error */
        float error = 0;
        for(j=0; j<NUM_POINTS; j++) 
        {
            int cluster = assignments[j];
            error += distance(data[j][0], data[j][1], clusters[cluster][0], clusters[cluster][1]);
        }
        printf("Iteration %d: error = %.2f\n", i+1, error);

        /* Check if error has converged */
        if(prev_error != -1 && fabs(prev_error - error) < THRESHOLD) 
        {
            printf("Converged after %d iterations!\n", i+1);
            break;
        }
        prev_error = error;
    }

    return 0;
}