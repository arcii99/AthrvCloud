//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: grateful
#include<stdio.h>
#include<math.h>

/* Grateful Simulator */

#define MAX_NODES 100
#define GMIN 1e-12

int num_nodes;
double capacitance[MAX_NODES][MAX_NODES];
double inductance[MAX_NODES];
double conductance[MAX_NODES][MAX_NODES];

void add_capacitor(int node1, int node2, double c) {
    capacitance[node1][node2] += c;
    capacitance[node2][node1] += c;
}

void add_inductor(int node1, int node2, double l) {
    inductance[node1] += l;
    inductance[node2] += l;
    conductance[node1][node2] -= 1/l;
    conductance[node2][node1] -= 1/l;
}

void add_resistor(int node1, int node2, double r) {
    conductance[node1][node2] += 1/r;
    conductance[node2][node1] += 1/r;
}

double voltage[MAX_NODES];
double current[MAX_NODES];
double dxdt[MAX_NODES];
double x[MAX_NODES];

void init() {
    for(int i=0;i<num_nodes;i++) {
        for(int j=0;j<num_nodes;j++) {
            capacitance[i][j] = 0;
            conductance[i][j] = 0;
        }
        inductance[i] = 0;
        voltage[i] = 0;
        current[i] = 0;
        dxdt[i] = 0;
        x[i] = 0;
    }
}

void simulate(double t, double dt) {
    int steps = ceil(t/dt);
    for(int i=0;i<steps;i++) {
        double time = dt*i;
        printf("Time: %lf\n", time);
        for(int j=0;j<num_nodes;j++) {
            double I = current[j];
            for(int k=0;k<num_nodes;k++) {
                if(j==k) continue;
                double V = voltage[j]-voltage[k];
                double G = conductance[j][k]+capacitance[j][k]/dt;
                double C = capacitance[j][k]/dt*x[j]+capacitance[k][j]/dt*x[k];
                dxdt[j] = (I+C)/capacitance[j][j];
                x[j] += dxdt[j]*dt;
                I += G*V;
            }
            current[j] = I;
            voltage[j] = x[j];
            printf("Node %d: Voltage: %lf Current: %lf\n",j+1,voltage[j],current[j]);
        }
        printf("\n");
    }
}

int main() {
    num_nodes = 3;
    init();
    add_resistor(0,1,100.0);
    add_resistor(1,2,50.0);
    add_capacitor(1,2,0.0001);
    add_inductor(0,2,0.00001);
    simulate(0.01,0.0001);
    return 0;
}