//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CIRCUITS 1000    // Maximum number of circuits that can be simulated

// Struct representing each circuit
typedef struct {
    int num_components;     // Number of components in the circuit
    int voltage;            // The voltage of the circuit
} Circuit;

// Struct representing each component
typedef struct {
    int resistance;         // The resistance of the component
    int current;            // The current passing through the component
} Component;

int main() {
    Circuit circuits[MAX_CIRCUITS];
    srand(time(NULL));
    int circuit_count = rand() % MAX_CIRCUITS + 1;

    for (int i = 0; i < circuit_count; i++) {
        circuits[i].num_components = rand() % 10 + 1;
        circuits[i].voltage = rand() % 100 + 1;
        Component components[circuits[i].num_components];
        for (int j = 0; j < circuits[i].num_components; j++) {
            components[j].resistance = rand() % 100 + 1;
            components[j].current = circuits[i].voltage / components[j].resistance;
        }
        circuits[i].num_components = rand() % 15 + circuits[i].num_components;
        printf("Circuit %d: %d components, %dv\n", i+1, circuits[i].num_components, circuits[i].voltage);
        printf("Component resistances and currents:");
        for (int j = 0; j < circuits[i].num_components; j++) {
            printf(" %dR, %dA;", components[j].resistance, components[j].current);
        }
        printf("\n\n");
    }
    return 0;
}