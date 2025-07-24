//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100 // Maximum nodes that can be handled by this program
#define MAX_VAL 1000000000 // Maximum value a node voltage or current can take
#define MIN_VAL -1000000000 // Minimum value a node voltage or current can take

int totalNodes = 0;
int groundedNode = -1;
double conductances[MAX_NODES][MAX_NODES];
double voltages[MAX_NODES];
double currents[MAX_NODES];

/* Add a new node to the circuit */
void addNode() {
    if(totalNodes >= MAX_NODES) {
        printf("Error! Maximum number of nodes exceeded.\n");
        return;
    }
    totalNodes++;
}

/* Add a resistor to the circuit */
void addResistor(int node1, int node2, double resistance) {
    if(node1 < 1 || node1 > totalNodes || node2 < 1 || node2 > totalNodes) {
        printf("Error! Invalid node number.\n");
        return;
    }
    if(node1 == groundedNode || node2 == groundedNode) {
        printf("Error! Cannot connect resistor to grounded node.\n");
        return;
    }
    conductances[node1][node2] += 1.0/resistance;
    conductances[node2][node1] += 1.0/resistance;
}

/* Add a voltage source to the circuit */
void addVoltageSource(int node1, int node2, double voltage) {
    if(node1 < 1 || node1 > totalNodes || node2 < 1 || node2 > totalNodes) {
        printf("Error! Invalid node number.\n");
        return;
    }
    if(node1 == groundedNode || node2 == groundedNode) {
        printf("Error! Cannot connect voltage source to grounded node.\n");
        return;
    }
    if(node1 == node2) {
        printf("Error! Cannot connect voltage source between same node.\n");
        return;
    }
    double conductance = 1.0/MAX_VAL; // avoid division by zero
    if(voltage > 0) {
        conductances[node1][node1] += conductance;
        conductances[node2][node2] += conductance;
        conductances[node1][node2] -= conductance;
        conductances[node2][node1] -= conductance;
        currents[node1] += MAX_VAL;
        currents[node2] -= MAX_VAL;
    }
    else {
        conductances[node1][node1] += conductance;
        conductances[node2][node2] += conductance;
        conductances[node1][node2] -= conductance;
        conductances[node2][node1] -= conductance;
        currents[node1] -= MAX_VAL;
        currents[node2] += MAX_VAL;
    }
}

/* Solve the circuit using gaussian elimination */
void solve() {
    for(int i=1; i<=totalNodes; i++) {
        for(int j=1; j<=totalNodes; j++) {
            if(i == j) continue;
            conductances[i][i] += conductances[i][j];
            currents[i] += currents[j]*conductances[i][j];
        }
    }
    for(int i=1; i<=totalNodes; i++) {
        if(i == groundedNode) continue;
        voltages[i] = currents[i]/conductances[i][i];
    }
}

int main() {
    addNode();
    addNode();
    addResistor(1, 2, 1000);
    addVoltageSource(1, 2, 5);
    groundedNode = 2; // node 2 is the ground node
    solve();
    printf("Circuit simulation results:\n");
    printf("Voltage at node 1 = %lf\n", voltages[1]);
    printf("Current through resistor = %lf\n", (voltages[1]-voltages[2])/1000);
    return 0;
}