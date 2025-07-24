//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 1000

struct element 
{
    char type; // 'R', 'C', or 'L'
    int from_node;
    int to_node;
    double value; // in ohms, farads or henries respectively
};

int num_nodes = 0;
int num_elements = 0;
double time_step = 0.1; // in seconds
double end_time = 100.0; // in seconds
double voltage[MAX_NODES][MAX_NODES];
double current[MAX_NODES][MAX_NODES];
double node_voltage[MAX_NODES];

struct element elements[MAX_NODES];

void add_element(char type, int from_node, int to_node, double value)
{
    elements[num_elements].type = type;
    elements[num_elements].from_node = from_node;
    elements[num_elements].to_node = to_node;
    elements[num_elements].value = value;

    num_elements++;
}

void create_circuit()
{
    // Build simple RC circuit
    add_element('R', 0, 1, 1000.0); // 1k ohm resistor
    add_element('C', 1, 2, 1e-6); // 1uF capacitor
    add_element('R', 2, 3, 500.0); // 500 ohm resistor
    add_element('C', 3, 0, 0.5e-6); // 0.5uF capacitor

    num_nodes = 4;
}

void initialize_matrices()
{
    int i, j;

    // Initialize matrices to zeros
    for (i = 0; i < MAX_NODES; i++) 
    {
        for (j = 0; j < MAX_NODES; j++) 
        {
            voltage[i][j] = 0.0;
            current[i][j] = 0.0;
        }
    }
}

void build_matrices(double t)
{
    int i, j, k;
    double conductance, impedance, omega, capacitance, inductance;

    // Fill in conductances
    for (i = 0; i < num_elements; i++) 
    {
        if (elements[i].type == 'R') 
        {
            conductance = 1.0 / elements[i].value;
            voltage[elements[i].from_node][elements[i].from_node] += conductance;
            voltage[elements[i].to_node][elements[i].to_node] += conductance;
            voltage[elements[i].from_node][elements[i].to_node] -= conductance;
            voltage[elements[i].to_node][elements[i].from_node] -= conductance;
        } 
        else if (elements[i].type == 'C') 
        {
            capacitance = elements[i].value;
            impedance = 1.0 / (2.0 * M_PI * capacitance * t);
            voltage[elements[i].from_node][elements[i].from_node] += impedance;
            voltage[elements[i].to_node][elements[i].to_node] += impedance;
            voltage[elements[i].from_node][elements[i].to_node] -= impedance;
            voltage[elements[i].to_node][elements[i].from_node] -= impedance;
        } 
        else if (elements[i].type == 'L') 
        {
            inductance = elements[i].value;
            impedance = 2.0 * M_PI * inductance * t;
            voltage[elements[i].from_node][elements[i].from_node] += impedance;
            voltage[elements[i].to_node][elements[i].to_node] += impedance;
            voltage[elements[i].from_node][elements[i].to_node] -= impedance;
            voltage[elements[i].to_node][elements[i].from_node] -= impedance;
        }
    }

    // Fill in current source equations
    for (i = 0; i < num_elements; i++) 
    {
        if (elements[i].type == 'I') 
        {
            current[elements[i].from_node][elements[i].to_node] += elements[i].value;
        }
    }

    // Initialize node voltages
    for (i = 0; i < num_nodes; i++) 
    {
        node_voltage[i] = 0.0;
    }

    // Solve the matrix equations
    for (i = 0; i < num_nodes; i++) 
    {
        for (j = 0; j < num_nodes; j++) 
        {
            if (voltage[i][j] != 0.0) 
            {
                node_voltage[i] += voltage[i][j] * node_voltage[j];
            }
        }
    }
}

void print_results(double t)
{
    printf("%lf, ", t);
    printf("%lf, %lf, %lf, %lf\n", node_voltage[0], node_voltage[1], node_voltage[2], node_voltage[3]);
}

int main()
{
    double t;

    create_circuit();
    initialize_matrices();

    for (t = 0.0; t < end_time; t += time_step) 
    {
        build_matrices(t);
        print_results(t);
    }

    return 0;
}