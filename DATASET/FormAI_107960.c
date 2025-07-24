//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define the maximum number of nodes */
#define MAX_NODES 50

/* Define the maximum number of components */
#define MAX_COMPONENTS 50

/* Define the number of inputs and the input array */
#define NUM_INPUTS 3
int inputs[NUM_INPUTS];

/* Define the number of outputs and the output array */
#define NUM_OUTPUTS 1
int outputs[NUM_OUTPUTS];

/* Define component types */
typedef enum
{
    RESISTOR,
    CAPACITOR,
    INDUCTOR
} ComponentType;

/* Define component structure */
typedef struct
{
    ComponentType type;
    int node1;
    int node2;
    double value;
} Component;

/* Define global variables */
Component components[MAX_COMPONENTS];
int numComponents = 0;
double nodes[MAX_NODES] = { 0 };
double A[MAX_NODES][MAX_NODES] = { 0 };
double b[MAX_NODES] = { 0 };

/* Function to add a component */
void addComponent(Component component)
{
    components[numComponents] = component;
    numComponents++;
}

/* Function to build matrix A and vector b */
void buildMatrix()
{
    /* Loop through all components */
    for (int i = 0; i < numComponents; i++)
    {
        Component component = components[i];

        /* Handle resistor */
        if (component.type == RESISTOR)
        {
            double conductance = 1.0 / component.value;
            A[component.node1][component.node1] += conductance;
            A[component.node1][component.node2] -= conductance;
            A[component.node2][component.node1] -= conductance;
            A[component.node2][component.node2] += conductance;
        }

        /* Handle capacitor */
        else if (component.type == CAPACITOR)
        {
            double conductance = 2.0 / component.value;
            A[component.node1][component.node1] += conductance;
            A[component.node1][component.node2] -= conductance;
            A[component.node2][component.node1] -= conductance;
            A[component.node2][component.node2] += conductance;
        }

        /* Handle inductor */
        else if (component.type == INDUCTOR)
        {
            double resistance = 2.0 * component.value;
            A[component.node1][component.node1] += resistance;
            A[component.node1][component.node2] -= resistance;
            A[component.node2][component.node1] -= resistance;
            A[component.node2][component.node2] += resistance;
        }
    }

    /* Loop through all inputs */
    for (int i = 0; i < NUM_INPUTS; i++)
    {
        int node = inputs[i];
        A[node][node] += 1.0;
    }

    /* Loop through all outputs */
    for (int i = 0; i < NUM_OUTPUTS; i++)
    {
        int node = outputs[i];
        b[node] = 1.0;
    }
}

/* Function to solve matrix equation */
void solveMatrix()
{
    /* Build augmented matrix */
    double augmented[MAX_NODES][MAX_NODES + 1];
    for (int i = 0; i < MAX_NODES; i++)
    {
        for (int j = 0; j < MAX_NODES + 1; j++)
        {
            if (j == MAX_NODES)
            {
                augmented[i][j] = b[i];
            }
            else
            {
                augmented[i][j] = A[i][j];
            }
        }
    }

    /* Solve matrix equation using Gaussian elimination */
    for (int i = 0; i < MAX_NODES; i++)
    {
        double max = augmented[i][i];
        int maxIndex = i;
        for (int j = i + 1; j < MAX_NODES; j++)
        {
            if (fabs(augmented[j][i]) > fabs(max))
            {
                max = augmented[j][i];
                maxIndex = j;
            }
        }
        for (int j = i; j < MAX_NODES + 1; j++)
        {
            double temp = augmented[i][j];
            augmented[i][j] = augmented[maxIndex][j];
            augmented[maxIndex][j] = temp;
        }
        for (int j = i + 1; j < MAX_NODES; j++)
        {
            double factor = augmented[j][i] / augmented[i][i];
            for (int k = i; k < MAX_NODES + 1; k++)
            {
                augmented[j][k] -= factor * augmented[i][k];
            }
        }
    }

    /* Calculate solution */
    for (int i = MAX_NODES - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < MAX_NODES; j++)
        {
            sum += augmented[i][j] * nodes[j];
        }
        nodes[i] = (augmented[i][MAX_NODES] - sum) / augmented[i][i];
    }
}

int main()
{
    /* Add components */
    Component r1 = { RESISTOR, 0, 1, 1000.0 };
    Component r2 = { RESISTOR, 1, 2, 1000.0 };
    Component c1 = { CAPACITOR, 2, 0, 0.000001 };
    addComponent(r1);
    addComponent(r2);
    addComponent(c1);

    /* Set inputs and outputs */
    inputs[0] = 0;
    inputs[1] = 1;
    inputs[2] = 2;
    outputs[0] = 2;

    /* Build matrix and solve */
    buildMatrix();
    solveMatrix();

    /* Print results */
    printf("Node Voltages:\n");
    for (int i = 0; i < MAX_NODES; i++)
    {
        printf("Node %d: %lf\n", i, nodes[i]);
    }

    return 0;
}