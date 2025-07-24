//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Linus Torvalds
/* Welcome to the Linus Torvalds-style Classical Circuit Simulator example program */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* Define constants and structs */
#define MAX_NODES 1000
#define MAX_RES 1000
#define MAX_CAP 1000
#define MAX_INDUCT 1000

typedef struct resistor {
    int node1;
    int node2;
    double resistance;
} resistor;

typedef struct capacitance {
    int node1;
    int node2;
    double capacitance;
    double voltage;
    double charge;
} capacitance;

typedef struct inductance {
    int node1;
    int node2;
    double inductance;
    double current;
} inductance;

/* Define global variables */
resistor Resistors[MAX_RES];
capacitance Capacitors[MAX_CAP];
inductance Inductors[MAX_INDUCT];
int ResCount = 0;
int CapCount = 0;
int IndCount = 0;
int NodeCount = -1;

double Nodes[MAX_NODES];

/* Function to simulate circuit for given time */
void simulate(double t) {
    double step = 0.001; /* define step size */
    bool done = false;

    while (!done) {
        /* Update resistors */
        for (int i = 0; i < ResCount; i++) {
            double resistance = Resistors[i].resistance;
            double v1 = Nodes[Resistors[i].node1];
            double v2 = Nodes[Resistors[i].node2];
            double current = (v1 - v2) / resistance;
            Nodes[Resistors[i].node1] += current;
            Nodes[Resistors[i].node2] -= current;
        }

        /* Update capacitors */
        for (int i = 0; i < CapCount; i++) {
            double capacitance = Capacitors[i].capacitance;
            double v1 = Nodes[Capacitors[i].node1];
            double v2 = Nodes[Capacitors[i].node2];
            double voltage = v1 - v2;
            Capacitors[i].charge += voltage * capacitance * step;
            Capacitors[i].voltage = Capacitors[i].charge / capacitance;
        }

        /* Update inductors */
        for (int i = 0; i < IndCount; i++) {
            double inductance = Inductors[i].inductance;
            double v1 = Nodes[Inductors[i].node1];
            double v2 = Nodes[Inductors[i].node2];
            double current = (v1 - v2) / inductance;
            Inductors[i].current += current * step;
            Nodes[Inductors[i].node1] -= Inductors[i].current;
            Nodes[Inductors[i].node2] += Inductors[i].current;
        }

        /* Check if simulation is complete */
        if (step >= t) {
            done = true;
            break;
        }

        step += 0.001; /* increment step size */
    }
}

/* Function to add resistor to circuit */
void add_resistor(int node1, int node2, double resistance) {
    Resistors[ResCount].node1 = node1;
    Resistors[ResCount].node2 = node2;
    Resistors[ResCount].resistance = resistance;
    ResCount++;
}

/* Function to add capacitor to circuit */
void add_capacitor(int node1, int node2, double capacitance) {
    Capacitors[CapCount].node1 = node1;
    Capacitors[CapCount].node2 = node2;
    Capacitors[CapCount].capacitance = capacitance;
    CapCount++;
}

/* Function to add inductor to circuit */
void add_inductor(int node1, int node2, double inductance) {
    Inductors[IndCount].node1 = node1;
    Inductors[IndCount].node2 = node2;
    Inductors[IndCount].inductance = inductance;
    IndCount++;
}

int main() {
    add_resistor(0, 1, 100); /* add a resistor between nodes 0 and 1 with resistance 100 ohms */
    add_resistor(1, 2, 200);
    add_resistor(0, 2, 300);
    add_capacitor(2, 3, 0.1); /* add a capacitor between nodes 2 and 3 with capacitance 0.1 farads */
    add_inductor(3, 4, 0.01); /* add an inductor between nodes 3 and 4 with inductance 0.01 henrys */

    simulate(1.0); /* simulate the circuit for 1 second */

    printf("Node voltages:\n");
    for (int i = 0; i <= NodeCount; i++) {
        printf("V%d = %.2f\n", i, Nodes[i]);
    }

    return 0;
}