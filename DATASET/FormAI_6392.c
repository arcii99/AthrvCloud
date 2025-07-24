//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include <stdio.h>

// Defining the number of Nodes
#define NODES 3

// Defining the number of Elements
#define ELEMENTS 2

// Defining the maximum iteration count
#define MAX_ITERATION 100

// Defining the resistance values
double R[ELEMENTS] = {8, 4};

// Defining the voltage sources
double V[ELEMENTS] = {10, 5};

// Defining the node connections of the elements
int C[ELEMENTS][2] = {{1, 2}, {2, 3}};

int main()
{
    double G[NODES][NODES], B[NODES], x[NODES], v;

    int i, j, k, iteration;
    
    // Initializing all the conductances in the G matrix to 0
    for (i = 0; i < NODES; i++)
        for (j = 0; j < NODES; j++)
            G[i][j] = 0;

    // Creating the G matrix
    for (k = 0; k < ELEMENTS; k++)
    {
        i = C[k][0] - 1;
        j = C[k][1] - 1;
        G[i][i] += 1 / R[k];
        G[i][j] += -1 / R[k];
        G[j][i] += -1 / R[k];
        G[j][j] += 1 / R[k];
    }

    // Initializing all the current sources in B matrix to 0
    for (i = 0; i < NODES; i++)
        B[i] = 0;

    // Creating B matrix
    for (k = 0; k < ELEMENTS; k++)
    {
        i = C[k][0] - 1;
        j = C[k][1] - 1;
        if (i != -1)
            B[i] += V[k] / R[k];
        if (j != -1)
            B[j] -= V[k] / R[k];
    }

    // Initializing the voltages of the nodes to 0
    for (i = 0; i < NODES; i++)
        x[i] = 0;

    // Solving using modified nodal analysis
    for (iteration = 0; iteration < MAX_ITERATION; iteration++)
    {
        for (i = 0; i < NODES; i++)
        {
            v = B[i];
            for (j = 0; j < NODES; j++)
            {
                if (i != j)
                {
                    v -= G[i][j] * x[j];
                }
            }
            x[i] = v / G[i][i];
        }
    }

    // Printing the voltages of the nodes
    printf("The voltages of the nodes are:\n");
    for (i = 0; i < NODES; i++)
    {
        printf("%lf\n", x[i]);
    }

    // Exiting the program
    return 0;
}