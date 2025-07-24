//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#define N 1000

typedef struct component {
    int comp_type;  // Type of the component (R,L,C)
    double value;   // Value of the component
    double curr[N]; // Array to store the current at each time step
    double volt[N]; // Array to store the voltage at each time step
}Component;

typedef struct node {
    int comp_count; // Number of components connected to this node
    Component *comp; // Array to store the components connected to this node
}Node;

void simulate(Node *node, int node_count, int time_steps, double time_interval) {
    // Code to simulate the circuit
    double time = 0.0;
    int i, j, k;
    for(i=0; i<time_steps; i++) {
        // Update the current and voltage values at each time step
        for(j=0; j<node_count; j++) {
            for(k=0; k<node[j].comp_count; k++) {
                Component c = node[j].comp[k];
                if(c.comp_type == 0) { // Resistor
                    if(j == 0) { // First node
                        c.curr[i] = (node[j+1].comp[k].volt[i] - node[j].comp[k].volt[i]) / c.value;
                    }
                    else if(j == node_count-1) { // Last node
                        c.curr[i] = (node[j-1].comp[k].volt[i] - node[j].comp[k].volt[i]) / c.value;
                    }
                    else { // Any intermediate node
                        c.curr[i] = (node[j-1].comp[k].volt[i] - node[j].comp[k].volt[i] + node[j+1].comp[k].volt[i] - node[j].comp[k].volt[i]) / (2*c.value);
                    }
                    c.volt[i] = node[j].comp[k].volt[i];
                }
                else if(c.comp_type == 1) { // Inductor
                    if(j == 0) { // First node
                        c.curr[i] = node[j].comp[k].curr[i-1] + (node[j+1].comp[k].volt[i] - node[j].comp[k].volt[i]) / (c.value*time_interval);
                    }
                    else if(j == node_count-1) { // Last node
                        c.curr[i] = node[j].comp[k].curr[i-1] + (node[j-1].comp[k].volt[i] - node[j].comp[k].volt[i]) / (c.value*time_interval);
                    }
                    else { // Any intermediate node
                        c.curr[i] = node[j].comp[k].curr[i-1] + (node[j-1].comp[k].volt[i] - node[j].comp[k].volt[i] + node[j+1].comp[k].volt[i] - node[j].comp[k].volt[i]) / (2*c.value*time_interval);
                    }
                    c.volt[i] = node[j].comp[k].volt[i];
                }
                else if(c.comp_type == 2) { // Capacitor
                    if(j == 0) { // First node
                        c.volt[i] = node[j].comp[k].volt[i-1] + c.curr[i-1]*time_interval/c.value;
                    }
                    else if(j == node_count-1) { // Last node
                        c.volt[i] = node[j].comp[k].volt[i-1] - c.curr[i-1]*time_interval/c.value;
                    }
                    else { // Any intermediate node
                        c.volt[i] = node[j].comp[k].volt[i-1] + (node[j-1].comp[k].volt[i-1] - node[j].comp[k].volt[i-1] + node[j+1].comp[k].volt[i-1] - node[j].comp[k].volt[i-1])/(2*c.value*time_interval*c.value);
                    }
                    c.curr[i] = node[j].comp[k].curr[i-1];
                }
                node[j].comp[k] = c;
            }
        }
        time += time_interval;
    }
}

int main() {
    // Code to create the circuit and pass it to the simulator
    int node_count = 4; // Number of nodes in the circuit
    int time_steps = 100; // Number of time steps
    double time_interval = 0.01; // Time interval between time steps
    
    // Initialize the circuit
    Node node[node_count];
    int comp_count[node_count]; // Array to store the number of components connected to each node
    int i, j;
    for(i=0; i<node_count; i++) {
        // Randomly assign number of components to each node
        comp_count[i] = rand()%3 + 1;
        node[i].comp = (Component*)malloc(comp_count[i]*sizeof(Component));
        node[i].comp_count = comp_count[i];
        for(j=0; j<comp_count[i]; j++) {
            // Randomly assign type and value to each component
            node[i].comp[j].comp_type = rand()%3;
            node[i].comp[j].value = (double)(rand()%10 + 1)*0.1;
            node[i].comp[j].curr[0] = 0.0;
            node[i].comp[j].volt[0] = 0.0;
        }
    }
    
    // Run the simulation
    simulate(node, node_count, time_steps, time_interval);
    
    // Print the results
    for(i=0; i<node_count; i++) {
        printf("Node %d: %d components\n", i+1, comp_count[i]);
        for(j=0; j<comp_count[i]; j++) {
            Component c = node[i].comp[j];
            printf("\tComponent %d: Type - %d, Value - %lf\n", j+1, c.comp_type, c.value);
            printf("\t\tCurrent: ");
            for(int k=0; k<time_steps; k++) {
                printf("%lf ", c.curr[k]);
            }
            printf("\n");
            printf("\t\tVoltage: ");
            for(int k=0; k<time_steps; k++) {
                printf("%lf ", c.volt[k]);
            }
            printf("\n");
        }
    }
    
    // Free memory
    for(i=0; i<node_count; i++) {
        free(node[i].comp);
    }
    
    return 0;
}