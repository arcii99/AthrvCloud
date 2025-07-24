//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: synchronous
#include <stdio.h>

#define MAX_INPUTS 10
#define MAX_OUTPUTS 5

typedef struct {
    int in1;
    int in2;
    int out[MAX_OUTPUTS];
} Gate;

Gate gates[MAX_INPUTS];

int main() {
    int numInputs, numOutputs;

    printf("Enter the number of inputs (max %d): ", MAX_INPUTS);
    scanf("%d", &numInputs);

    printf("Enter the number of outputs (max %d): ", MAX_OUTPUTS);
    scanf("%d", &numOutputs);

    for(int i = 0; i < numInputs; i++) {
        printf("Enter inputs for gate %d (in1 in2): ", i+1);
        scanf("%d %d", &gates[i].in1, &gates[i].in2);

        for(int j = 0; j < numOutputs; j++) {
            printf("Enter output %d for gate %d: ", j+1, i+1);
            scanf("%d", &gates[i].out[j]);
        }
    }

    //Simulation
    printf("\n\nSimulation results:\n");

    for(int i = 0; i < numInputs; i++) {
        printf("=============================\n");
        printf("Gate %d:\n", i+1);
        printf("Inputs - in1: %d in2: %d\n", gates[i].in1, gates[i].in2);

        for(int j = 0; j < numOutputs; j++) {
            printf("Output %d: %d\n", j+1, gates[i].out[j]);
        }
    }

    return 0;
}