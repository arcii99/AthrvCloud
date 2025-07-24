//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
#define MAX_NODES 500    // maximum number of circuit nodes
#define MAX_ELEM 1000    // maximum number of circuit elements

// Circuit element types
#define RES 1
#define IND 2
#define CAP 3
#define VSRC 4
#define ISRC 5

// Circuit element structure
typedef struct circuit_element
{
    int type;
    double value;
    int node1;
    int node2;
} circuit_element;

// Circuit node structure
typedef struct circuit_node
{
    int node_num;
    int num_elem;
    circuit_element elem_list[MAX_ELEM];
    double voltage;
    double curr;
} circuit_node;

// Circuit simulation function
void simulate(circuit_node *node_list, int num_nodes, int num_elems, double dt, double tmax)
{
    double t = 0.0; // simulation time
    int i, j, k;

    // Array to store the node voltages for the previous time step
    double prev_voltages[MAX_NODES];

    // Initialize the voltages and currents for all nodes
    for (i = 0; i < num_nodes; i++)
    {
        node_list[i].voltage = 0.0;
        node_list[i].curr = 0.0;

        for (j = 0; j < node_list[i].num_elem; j++)
        {
            if (node_list[i].elem_list[j].type == VSRC)
            {
                node_list[i].voltage += node_list[i].elem_list[j].value;
            }
        }

        prev_voltages[i] = node_list[i].voltage;
    }

    // Simulation loop
    while (t < tmax)
    {
        // Update the voltages and currents for all nodes
        for (i = 0; i < num_nodes; i++)
        {
            node_list[i].voltage = 0.0;
            node_list[i].curr = 0.0;

            for (j = 0; j < node_list[i].num_elem; j++)
            {
                circuit_element elem = node_list[i].elem_list[j];

                switch (elem.type)
                {
                    case RES:
                        node_list[i].curr += (prev_voltages[elem.node1] - prev_voltages[elem.node2]) / elem.value;
                        break;

                    case IND:
                        node_list[i].curr += (prev_voltages[elem.node1] - prev_voltages[elem.node2]) * dt / elem.value;
                        node_list[i].voltage -= node_list[i].curr * dt;
                        break;

                    case CAP:
                        node_list[i].voltage += (prev_voltages[elem.node1] - prev_voltages[elem.node2]) / elem.value;
                        node_list[i].curr -= node_list[i].voltage * dt;
                        break;

                    case VSRC:
                        node_list[i].voltage += elem.value;
                        break;

                    case ISRC:
                        node_list[i].curr += elem.value;
                        break;
                }
            }

            // Update the voltage for this node
            node_list[i].voltage += node_list[i].curr * dt;
        }

        // Print the voltages for all nodes
        printf("%.5f", t);

        for (i = 0; i < num_nodes; i++)
        {
            printf("\t%.5f", node_list[i].voltage);
        }

        printf("\n");

        // Update the time and previous voltages array
        t += dt;

        for (i = 0; i < num_nodes; i++)
        {
            prev_voltages[i] = node_list[i].voltage;
        }
    }
}

// Main function
int main()
{
    // Circuit nodes and elements
    circuit_node node_list[MAX_NODES];
    circuit_element elem_list[MAX_ELEM];

    int num_nodes, num_elems;
    double dt, tmax;

    // Read the circuit description from file
    FILE *fp;
    fp = fopen("circuit.txt", "r");

    fscanf(fp, "%d\n", &num_nodes);

    for (int i = 0; i < num_nodes; i++)
    {
        node_list[i].node_num = i + 1;
        node_list[i].num_elem = 0;
    }

    fscanf(fp, "%d\n", &num_elems);

    for (int i = 0; i < num_elems; i++)
    {
        char type;
        double value;
        int node1, node2;

        fscanf(fp, "%c %lf %d %d\n", &type, &value, &node1, &node2);

        circuit_element elem;

        switch (type)
        {
            case 'R':
                elem.type = RES;
                break;

            case 'L':
                elem.type = IND;
                value *= 2 * PI;
                break;

            case 'C':
                elem.type = CAP;
                value = 1.0 / (2 * PI * value);
                break;

            case 'V':
                elem.type = VSRC;
                break;

            case 'I':
                elem.type = ISRC;
                break;
        }

        elem.value = value;
        elem.node1 = node1 - 1;
        elem.node2 = node2 - 1;

        elem_list[i] = elem;

        node_list[node1 - 1].elem_list[node_list[node1 - 1].num_elem++] = elem;
        node_list[node2 - 1].elem_list[node_list[node2 - 1].num_elem++] = elem;
    }

    // Simulation parameters
    printf("Enter the time step and simulation time: ");
    scanf("%lf %lf", &dt, &tmax);

    // Simulate the circuit and print the results
    simulate(node_list, num_nodes, num_elems, dt, tmax);

    return 0;
}