//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include <stdio.h>
#include <math.h>

typedef struct Components {
    float value;
    float current;
    float voltage;
    char type; // R for Resistor, C for Capacitor, L for Inductor
} Component;

float getVoltage(Component components[], int index, int time) {
    // Calculate voltage using Kirchoff's laws
    float voltage = 0;
    int i;
    for (i = 0; i <= index; i++) {
        float current = components[i].type == 'C' ? components[i].value / (1 / (2 * M_PI * 50 * components[i].value)) : components[i].current;
        voltage += current * components[i].value;
    }
    return voltage;
}

void simulateCircuit(Component components[], int count, int time) {
    int i;
    for (i = 0; i < count; i++) {
        // Set initial conditions
        if (components[i].type == 'C') {
            components[i].voltage = 0;
            components[i].current = components[i].value == 0 ? 0 : components[i].voltage / (1 / (2 * M_PI * 50 * components[i].value));
        } else if (components[i].type == 'L') {
            components[i].voltage = 0;
            components[i].current = 0;
        }
    }
    // Simulate the circuit
    float timeStep = 1.0 / 1000;
    for (float t = 0; t <= time; t += timeStep) {
        for (i = 0; i < count; i++) {
            if (components[i].type == 'C') {
                // Calculate current and voltage using capacitor formula
                components[i].current = (getVoltage(components, i - 1, time) - getVoltage(components, i, time)) / (timeStep * components[i].value);
                components[i].voltage += components[i].current * timeStep;
            } else if (components[i].type == 'L') {
                // Calculate current and voltage using inductor formula
                components[i].voltage = getVoltage(components, i, time);
                components[i].current += (getVoltage(components, i - 1, time) - getVoltage(components, i, time)) * timeStep / components[i].value;
            } else {
                // Calculate current and voltage using resistor formula
                components[i].current = (getVoltage(components, i - 1, time) - getVoltage(components, i, time)) / components[i].value;
                components[i].voltage = components[i].current * components[i].value;
            }
        }
        // Output voltage and current for each component
        for (i = 0; i < count; i++) {
            printf("%c%d:\t Voltage: %f V\t Current: %f A\n", components[i].type, i, components[i].voltage, components[i].current);
        }
        printf("\n");
    }
}

int main() {
    // Create components and set values
    Component components[3];
    components[0].type = 'R';
    components[0].value = 1000;
    components[1].type = 'L';
    components[1].value = 0.3;
    components[2].type = 'C';
    components[2].value = 1e-6;

    // Simulate the circuit over 10ms
    simulateCircuit(components, 3, 10);

    return 0;
}