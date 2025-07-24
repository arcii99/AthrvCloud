//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CIRCUIT_ELEMENTS 100 // Maximum number of circuit elements
#define MAX_NAME_LENGTH 20 // Maximum length of a circuit element's name

// Struct for storing circuit element information
typedef struct {
    char name[MAX_NAME_LENGTH];
    float value;
} CircuitElement;

// Function for generating a random circuit element name
void generateName(char *name) {
    int i;
    for (i = 0; i < MAX_NAME_LENGTH - 1; i++) {
        name[i] = rand() % 26 + 'A';
    }
    name[MAX_NAME_LENGTH - 1] = '\0';
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Declare array of circuit elements
    CircuitElement circuit[MAX_CIRCUIT_ELEMENTS];

    // Generate random circuit element names and values
    int i;
    for (i = 0; i < MAX_CIRCUIT_ELEMENTS; i++) {
        generateName(circuit[i].name);
        circuit[i].value = (float) (rand() % 10000) / 100;
    }

    // Print out the circuit
    printf("Your circuit:\n");
    for (i = 0; i < MAX_CIRCUIT_ELEMENTS; i++) {
        printf("%s: %.2f\n", circuit[i].name, circuit[i].value);
    }

    // Simulate the circuit
    float output = 0;
    for (i = 0; i < MAX_CIRCUIT_ELEMENTS; i++) {
        if (circuit[i].value < 10) {
            output += 0.5;
        } else if (circuit[i].value >= 10 && circuit[i].value < 50) {
            output += 1;
        } else if (circuit[i].value >= 50 && circuit[i].value < 100) {
            output += 1.5;
        }
    }

    // Print out the simulation result
    printf("Your circuit's output: %.2f\n", output);

    return 0;
}