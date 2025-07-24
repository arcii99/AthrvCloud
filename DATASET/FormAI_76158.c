//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* define constants */
#define RESISTOR 1
#define CAPACITOR 2
#define INDUCTOR 3

/* define structure for circuit components */
typedef struct circuitComponent {
    int type;
    double value;
    double impedance;
} CircuitComponent;

/* function to calculate impedance of a component */
void calculateImpedance(CircuitComponent *component) {
    double w = 2 * M_PI * 1000;  // frequency of 1000 Hz
    switch (component->type) {
        case RESISTOR:
            component->impedance = component->value;
            break;
        case CAPACITOR:
            component->impedance = 1 / (w * component->value);
            break;
        case INDUCTOR:
            component->impedance = w * component->value;
            break;
    }
}

/* function to calculate total impedance of a circuit */
double calculateTotalImpedance(CircuitComponent components[], int size) {
    double totalImpedance = 0;
    for (int i = 0; i < size; i++) {
        if (components[i].type != RESISTOR) {
            calculateImpedance(&components[i]);
        }
        totalImpedance += components[i].impedance;
    }
    return totalImpedance;
}

int main() {
    /* create circuit components */
    CircuitComponent resistor = {RESISTOR, 1000, 0};  // 1000 Ohm resistor
    CircuitComponent capacitor = {CAPACITOR, 10E-6, 0};  // 10 uF capacitor
    CircuitComponent inductor = {INDUCTOR, 1E-3, 0};  // 1 mH inductor

    /* calculate impedance */
    calculateImpedance(&capacitor);
    calculateImpedance(&inductor);

    /* create array of circuit components */
    CircuitComponent circuit[3] = {resistor, capacitor, inductor};

    /* calculate total impedance */
    double totalImpedance = calculateTotalImpedance(circuit, 3);

    /* print result */
    printf("The total impedance of the circuit is %.2f Ohms\n", totalImpedance);

    return 0;
}