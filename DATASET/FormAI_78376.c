//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define K 3     // Number of Clusters
#define N 10    // Number of Points
#define D 2     // Number of Dimensions

float points[N][D] = { {2, 3}, {1, 3}, {3, 6}, {7, 6}, {8, 5}, {9, 5}, {10, 6}, {11, 5}, {9, 4}, {8, 4} };
float means[K][D];
float distances[N][K];
int groups[N];

void printMeans()
{
    int i, j;
    printf("Current means:\n");
    for (i = 0; i < K; ++i)
    {
        for (j = 0; j < D; ++j)
        {
            printf("%f ", means[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void calculateDistances()
{
    int i, j, k;
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < K; ++j)
        {
            distances[i][j] = 0;
            for (k = 0; k < D; ++k)
            {
                distances[i][j] += pow(points[i][k] - means[j][k], 2);
            }
            distances[i][j] = sqrt(distances[i][j]);
        }
    }
}

void assignGroups()
{
    int i, j, minIndex;
    float minDistance;
    for (i = 0; i < N; ++i)
    {
        minIndex = -1;
        minDistance = -1;
        for (j = 0; j < K; ++j)
        {
            if (minIndex == -1 || distances[i][j] < minDistance)
            {
                minIndex = j;
                minDistance = distances[i][j];
            }
        }
        groups[i] = minIndex;
    }
}

void recalculateMeans()
{
    int i, j, count[K], groupIndex;
    for (i = 0; i < K; ++i)
    {
        count[i] = 0;
        for (j = 0; j < D; ++j)
        {
            means[i][j] = 0;
        }
    }
    for (i = 0; i < N; ++i)
    {
        groupIndex = groups[i];
        count[groupIndex] += 1;
        for (j = 0; j < D; ++j)
        {
            means[groupIndex][j] += points[i][j];
        }
    }
    for (i = 0; i < K; ++i)
    {
        if (count[i] > 0)
        {
            for (j = 0; j < D; ++j)
            {
                means[i][j] /= count[i];
            }
        }
    }
}

int areMeansSame()
{
    int i, j;
    for (i = 0; i < K; ++i)
    {
        for (j = 0; j < D; ++j)
        {
            if (means[i][j] != means[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int i, j, iterations = 0;
    for (i = 0; i < K; ++i)
    {
        for (j = 0; j < D; ++j)
        {
            means[i][j] = points[(i*N)/K][j];
        }
    }
    printf("--- Initial State ---\n");
    printMeans();
    while (!areMeansSame())
    {
        iterations += 1;
        calculateDistances();
        assignGroups();
        recalculateMeans();
        printf("--- Iteration %d ---\n", iterations);
        printMeans();
    }
    printf("--- Final State ---\n");
    printMeans();
    return 0;
}