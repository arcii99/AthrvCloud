//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include<stdio.h>
#include<math.h>

#define MAX_NODES 20
#define MAX_NEIGHBORS 10

int main()
{
    int i, j, k;

    int num_nodes = 4;

    int neighbors[MAX_NODES][MAX_NEIGHBORS] = {
        {1, 2, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 2, 3, -1, -1, -1, -1, -1, -1, -1},
        {0, 1, 3, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, -1, -1, -1, -1, -1, -1, -1, -1}
    };

    float admittance[MAX_NODES][MAX_NODES] = {0};

    float resistance[MAX_NODES][MAX_NODES] = {0};

    // calculate admittance and resistance matrices
    for(i = 0; i < num_nodes; i++)
    {
        for(j = 0; neighbors[i][j] != -1; j++)
        {
            int neighbor = neighbors[i][j];

            float conductance = (neighbor > i) ? 1.0 : -1.0;
            admittance[i][i] += conductance;
            admittance[i][neighbor] -= conductance;

            resistance[i][neighbor] = -1.0;
            resistance[neighbor][i] = -1.0;
            resistance[i][i] += 1.0;
        }
    }

    // print admittance and resistance matrices
    printf("Admittance Matrix:\n");
    for(i = 0; i < num_nodes; i++)
    {
        for(j = 0; j < num_nodes; j++)
        {
            printf("%0.2f ", admittance[i][j]);
        }
        printf("\n");
    }

    printf("\nResistance Matrix:\n");
    for(i = 0; i < num_nodes; i++)
    {
        for(j = 0; j < num_nodes; j++)
        {
            printf("%0.2f ", resistance[i][j]);
        }
        printf("\n");
    }

    return 0;
}