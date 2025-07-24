//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
#include <stdio.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_ELEMS 2000

double nodes_voltage[MAX_NODES];
double nodes_current[MAX_NODES];
double elems_voltage[MAX_ELEMS];
double elems_current[MAX_ELEMS];

struct element
{
    int node_from, node_to;
    double value;
    char type;
};

int node_id_map[MAX_NODES];
int elem_count;
struct element elems[MAX_ELEMS];


int get_node_id(int node_num)
{
    if (node_id_map[node_num] == 0)
    {
        node_id_map[node_num] = ++elem_count;
    }

    return node_id_map[node_num];
}

void element_add(int node_from, int node_to, double value, char type)
{
    elems[elem_count].node_from = get_node_id(node_from);
    elems[elem_count].node_to = get_node_id(node_to);
    elems[elem_count].value = value;
    elems[elem_count].type = type;
}

void step_simulation(double step_size)
{
    // Perform an Euler-type approximation for numerical integration
    for (int i = 0; i < elem_count; i++)
    {
        int node_from = elems[i].node_from;
        int node_to = elems[i].node_to;
        double elem_voltage = nodes_voltage[node_from] - nodes_voltage[node_to];

        switch (elems[i].type)
        {
            case 'R':
            {
                elems_current[i] = elem_voltage / elems[i].value;
                break;
            }

            case 'C':
            {
                static double prev_elem_voltage[MAX_ELEMS] = {0};
                double d_elem_voltage = elem_voltage - prev_elem_voltage[i];
                prev_elem_voltage[i] = elem_voltage;
                elems_current[i] = d_elem_voltage / (step_size * elems[i].value);
                break;
            }

            case 'L':
            {
                static double prev_elem_current[MAX_ELEMS] = {0};
                double d_elem_current = elems_current[i] - prev_elem_current[i];
                prev_elem_current[i] = elems_current[i];
                elems_voltage[i] = d_elem_current * step_size * elems[i].value;
                break;
            }
        }

        nodes_current[node_from] += elems_current[i];
        nodes_current[node_to] -= elems_current[i];
    }

    for (int i = 1; i <= elem_count; i++)
    {
        nodes_voltage[i] += nodes_current[i] * step_size;
    }
}

int main()
{
    // Set initial node voltages
    nodes_voltage[get_node_id(1)] = 10;

    // Add circuit elements
    element_add(1, 2, 1000, 'R');
    element_add(2, 3, 0.00001, 'C');
    element_add(2, 4, 0.1, 'L');
    element_add(4, 3, 1000, 'R');

    // Simulate the circuit
    for (double t = 0; t < 1; t += 0.001)
    {
        step_simulation(0.001);
    }

    // Print voltages and currents
    for (int i = 1; i <= elem_count; i++)
    {
        printf("Node %d voltage: %f\n", i, nodes_voltage[i]);
        printf("Node %d current: %f\n", i, nodes_current[i]);
    }

    return 0;
}