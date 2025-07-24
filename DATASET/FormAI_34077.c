//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define NODE_COUNT 5
#define ELEMENT_COUNT 7

typedef struct {
    int from;
    int to;
    double value;
} element;

double nodes[NODE_COUNT];
element elements[ELEMENT_COUNT];

void simulate() {
    double delta_t = 0.0001;
    double max_time = 0.1;

    for (double t = 0.0; t < max_time; t += delta_t) {
        double currents[ELEMENT_COUNT] = {0};
        double conductances[ELEMENT_COUNT] = {0};

        // Calculate conductances
        for (int i = 0; i < ELEMENT_COUNT; i++) {
            element e = elements[i];
            int from = e.from;
            int to = e.to;

            if (from != -1 && to != -1) {
                double conductance = e.value > 0 ? 1.0 / e.value : 0;
                conductances[i] += conductance;
                currents[i] += conductance * (nodes[from] - nodes[to]);
            }
        }

        // Apply currents
        for (int i = 0; i < ELEMENT_COUNT; i++) {
            element e = elements[i];
            int from = e.from;
            int to = e.to;

            if (from != -1 && to != -1) {
                double current = currents[i];
                nodes[from] -= delta_t * current;
                nodes[to] += delta_t * current;
            }
        }
    }
}

int main() {
    // Initialize nodes
    for (int i = 0; i < NODE_COUNT; i++) {
        nodes[i] = 0;
    }

    // Initialize elements
    elements[0].from = 1;
    elements[0].to = 0;
    elements[0].value = 1000;

    elements[1].from = 1;
    elements[1].to = 2;
    elements[1].value = 0.000001;

    elements[2].from = 2;
    elements[2].to = 0;
    elements[2].value = 1000;

    elements[3].from = 3;
    elements[3].to = 0;
    elements[3].value = 500;

    elements[4].from = 3;
    elements[4].to = 4;
    elements[4].value = 1000;

    elements[5].from = 4;
    elements[5].to = 0;
    elements[5].value = 500;

    elements[6].from = -1;
    elements[6].to = -1;
    elements[6].value = 0;

    // Simulate circuit
    simulate();

    // Print results
    for (int i = 0; i < NODE_COUNT; i++) {
        printf("Node %d: %f\n", i, nodes[i]);
    }

    return 0;
}