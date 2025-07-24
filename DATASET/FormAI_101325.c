//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: future-proof
#include <stdio.h>
#include <math.h>

// Define constants
#define PI 3.14159
#define MAX_NODES 100

// Define struct for capacitors 
typedef struct capacitor
{
    double value;
    int node1;
    int node2;
} capacitor;

// Define struct for inductors
typedef struct inductor
{
    double value;
    int node1;
    int node2;
} inductor;

// Define struct for resistors
typedef struct resistor
{
    double value;
    int node1;
    int node2;
} resistor;

// Define struct for voltage sources
typedef struct voltage_source
{
    double amplitude;
    double frequency;
    double phase;
    int node1;
    int node2;
} voltage_source;

// Define struct for current sources
typedef struct current_source
{
    double amplitude;
    double frequency;
    double phase;
    int node1;
    int node2;
} current_source;

// Declare global variables
int num_nodes = 0;
capacitor caps[MAX_NODES];
inductor inds[MAX_NODES];
resistor resistors[MAX_NODES];
voltage_source voltages[MAX_NODES];
current_source currents[MAX_NODES];

// Function to add a new capacitor
void add_capacitor(double val, int n1, int n2)
{
    caps[num_nodes].value = val;
    caps[num_nodes].node1 = n1;
    caps[num_nodes].node2 = n2;
    num_nodes++;
}

// Function to add a new inductor
void add_inductor(double val, int n1, int n2)
{
    inds[num_nodes].value = val;
    inds[num_nodes].node1 = n1;
    inds[num_nodes].node2 = n2;
    num_nodes++;
}

// Function to add a new resistor
void add_resistor(double val, int n1, int n2)
{
    resistors[num_nodes].value = val;
    resistors[num_nodes].node1 = n1;
    resistors[num_nodes].node2 = n2;
    num_nodes++;
}

// Function to add a new voltage source
void add_voltage_source(double amp, double freq, double phase, int n1, int n2)
{
    voltages[num_nodes].amplitude = amp;
    voltages[num_nodes].frequency = freq;
    voltages[num_nodes].phase = phase;
    voltages[num_nodes].node1 = n1;
    voltages[num_nodes].node2 = n2;
    num_nodes++;
}

// Function to add a new current source
void add_current_source(double amp, double freq, double phase, int n1, int n2)
{
    currents[num_nodes].amplitude = amp;
    currents[num_nodes].frequency = freq;
    currents[num_nodes].phase = phase;
    currents[num_nodes].node1 = n1;
    currents[num_nodes].node2 = n2;
    num_nodes++;
}

// Function to simulate the circuit
void simulate(double time_step, double final_time)
{
    int i, j;
    double t = 0.0;
    double v[MAX_NODES] = {0.0};
    double i_c[MAX_NODES] = {0.0};
    double i_l[MAX_NODES] = {0.0};
    double node_v[MAX_NODES] = {0.0};
    double node_i[MAX_NODES] = {0.0};
    
    while (t <= final_time)
    {
        // Calculate capacitor currents
        for (i = 0; i < num_nodes; i++)
        {
            capacitor cap = caps[i];
            int n1 = cap.node1;
            int n2 = cap.node2;
            double v1 = node_v[n1];
            double v2 = node_v[n2];
            double i = (v2 - v1) * cap.value / time_step;
            i_c[n1] += i;
            i_c[n2] -= i;
        }
        
        // Calculate inductor voltages
        for (i = 0; i < num_nodes; i++)
        {
            inductor ind = inds[i];
            int n1 = ind.node1;
            int n2 = ind.node2;
            double i = node_i[n1] - node_i[n2];
            double v = i * ind.value * time_step;
            node_v[n1] += v;
            node_v[n2] -= v;
            i_l[n1] += i;
            i_l[n2] -= i;
        }
        
        // Calculate voltage sources
        for (i = 0; i < num_nodes; i++)
        {
            voltage_source vs = voltages[i];
            int n1 = vs.node1;
            int n2 = vs.node2;
            double v = vs.amplitude * sin(2*PI*vs.frequency*t + vs.phase);
            node_v[n1] += v;
            node_v[n2] -= v;
        }
        
        // Calculate current sources
        for (i = 0; i < num_nodes; i++)
        {
            current_source cs = currents[i];
            int n1 = cs.node1;
            int n2 = cs.node2;
            double i = cs.amplitude * sin(2*PI*cs.frequency*t + cs.phase);
            node_i[n1] += i;
            node_i[n2] -= i;
        }
        
        // Calculate resistors
        for (i = 0; i < num_nodes; i++)
        {
            resistor r = resistors[i];
            int n1 = r.node1;
            int n2 = r.node2;
            double v1 = node_v[n1];
            double v2 = node_v[n2];
            double i = (v2 - v1) / r.value;
            node_i[n1] += i;
            node_i[n2] -= i;
        }
        
        // Print node voltages
        printf("Time: %f\n", t);
        for (i = 0; i < num_nodes; i++)
        {
            printf("Node %d voltage: %f\n", i, node_v[i]);
        }
        printf("\n");
        
        t += time_step;
    }
}

int main()
{
    // Create a simple RC circuit with a 1uF capacitor and a 1k resistor
    add_resistor(1000.0, 0, 1);
    add_capacitor(1e-6, 1, 0);
    add_voltage_source(5.0, 1000.0, 0.0, 0, 1);
    
    // Simulate the circuit with a time step of 0.0001 seconds and a final time of 0.01 seconds
    simulate(0.0001, 0.01);
    
    return 0;
}