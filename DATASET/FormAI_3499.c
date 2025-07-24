//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include <stdio.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_ELEMS 200

#define TYPE_RESISTOR 'R'
#define TYPE_CAPACITOR 'C'
#define TYPE_INDUCTOR 'L'
#define TYPE_VOLTAGE 'V'
#define TYPE_CURRENT 'I'

#define PI 3.14159265359

typedef struct circuit_element
{
    char type;
    int node1, node2;
    double value;
} CircuitElement;

CircuitElement circuit[MAX_ELEMS];
double node_matrix[MAX_NODES][MAX_NODES + 1];
int nodes;

int is_nonzero(double val)
{
    return val < -1e-6 || val > 1e-6;
}

void init_system()
{
    int i, j;
    for (i = 0; i < MAX_NODES; i++)
    {
        for (j = 0; j <= MAX_NODES; j++)
        {
            node_matrix[i][j] = 0;
        }
    }
}

void add_resistor(int node1, int node2, double resistance)
{
    circuit[nodes].type = TYPE_RESISTOR;
    circuit[nodes].node1 = node1;
    circuit[nodes].node2 = node2;
    circuit[nodes].value = resistance;
    nodes++;
}

void add_capacitor(int node1, int node2, double capacitance)
{
    circuit[nodes].type = TYPE_CAPACITOR;
    circuit[nodes].node1 = node1;
    circuit[nodes].node2 = node2;
    circuit[nodes].value = capacitance;
    nodes++;
}

void add_inductor(int node1, int node2, double inductance)
{
    circuit[nodes].type = TYPE_INDUCTOR;
    circuit[nodes].node1 = node1;
    circuit[nodes].node2 = node2;
    circuit[nodes].value = inductance;
    nodes++;
}

void add_voltage_source(int node1, int node2, double voltage)
{
    circuit[nodes].type = TYPE_VOLTAGE;
    circuit[nodes].node1 = node1;
    circuit[nodes].node2 = node2;
    circuit[nodes].value = voltage;
    nodes++;
}

void add_current_source(int node1, int node2, double current)
{
    circuit[nodes].type = TYPE_CURRENT;
    circuit[nodes].node1 = node1;
    circuit[nodes].node2 = node2;
    circuit[nodes].value = current;
    nodes++;
}

void print_matrix()
{
    int i, j;
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j <= nodes; j++)
        {
            printf("%.2f ", node_matrix[i][j]);
        }
        printf("\n");
    }
}

void fill_matrix()
{
    int i, j, k;
    for (i = 0; i < nodes; i++)
    {
        switch (circuit[i].type)
        {
            case TYPE_RESISTOR:
                node_matrix[circuit[i].node1][circuit[i].node1] += 1.0 / circuit[i].value;
                node_matrix[circuit[i].node2][circuit[i].node2] += 1.0 / circuit[i].value;
                node_matrix[circuit[i].node1][circuit[i].node2] -= 1.0 / circuit[i].value;
                node_matrix[circuit[i].node2][circuit[i].node1] -= 1.0 / circuit[i].value;
                break;

            case TYPE_CAPACITOR:
                node_matrix[circuit[i].node1][circuit[i].node1] += circuit[i].value;
                node_matrix[circuit[i].node2][circuit[i].node2] += circuit[i].value;
                node_matrix[circuit[i].node1][circuit[i].node2] -= circuit[i].value;
                node_matrix[circuit[i].node2][circuit[i].node1] -= circuit[i].value;
                break;

            case TYPE_INDUCTOR:
                node_matrix[circuit[i].node1][circuit[i].node1] += 1.0 / circuit[i].value;
                node_matrix[circuit[i].node2][circuit[i].node2] += 1.0 / circuit[i].value;
                node_matrix[circuit[i].node1][circuit[i].node2] -= 1.0 / circuit[i].value;
                node_matrix[circuit[i].node2][circuit[i].node1] -= 1.0 / circuit[i].value;
                break;

            case TYPE_VOLTAGE:
                node_matrix[circuit[i].node1][nodes] -= circuit[i].value;
                node_matrix[circuit[i].node2][nodes] += circuit[i].value;
                break;

            case TYPE_CURRENT:
                node_matrix[circuit[i].node1][circuit[i].node2] += circuit[i].value;
                node_matrix[circuit[i].node2][circuit[i].node1] -= circuit[i].value;
                break;

            default:
                printf("Invalid circuit element type!\n");
                break;
        }
    }
}

void solve_matrix()
{
    int i, j, k;
    double pivot, temp;

    for (i = 0; i < nodes; i++)
    {
        pivot = node_matrix[i][i];
        if (fabs(pivot) < 1e-6)
        {
            printf("Pivot too small!\n");
            return;
        }

        // Divide row i by pivot
        for (j = i; j <= nodes; j++)
        {
            node_matrix[i][j] /= pivot;
        }

        // Subtract pivot row from all other rows
        for (j = 0; j < nodes; j++)
        {
            if (j != i)
            {
                temp = node_matrix[j][i];
                for (k = i; k <= nodes; k++)
                {
                    node_matrix[j][k] -= temp * node_matrix[i][k];
                }
            }
        }
    }
}

void print_solution()
{
    int i;
    for (i = 0; i < nodes; i++)
    {
        if (is_nonzero(node_matrix[i][nodes]))
        {
            printf("Node %d: %.2f\n", i+1, node_matrix[i][nodes]);
        }
    }
}

int main()
{
    init_system();

    add_resistor(1, 2, 100);
    add_inductor(2, 3, 0.001);
    add_capacitor(3, 0, 0.001);
    add_voltage_source(1, 0, 5);
    add_current_source(2, 3, 0.1);

    fill_matrix();
    print_matrix();

    solve_matrix();
    print_solution();

    return 0;
}