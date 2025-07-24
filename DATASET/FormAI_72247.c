//FormAI DATASET v1.0 Category: Image Classification system ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define the number of input features
#define FEATURES 784
// define the number of classes
#define CLASSES 10

int main() {
    // define input and output arrays
    float input[FEATURES];
    float output[CLASSES];

    // initialize weights and biases
    float weights[FEATURES][CLASSES];
    float biases[CLASSES];
    for (int i = 0; i < FEATURES; i++) {
        for (int j = 0; j < CLASSES; j++) {
            // initialize each weight to a random value between -1 and 1
            weights[i][j] = ((float)rand()/(float)(RAND_MAX)) * 2 - 1;
        }
    }
    for (int i = 0; i < CLASSES; i++) {
        // initialize each bias to 0.1
        biases[i] = 0.1;
    }

    // read inputs and calculate outputs
    printf("Enter %d input values:\n", FEATURES);
    for (int i = 0; i < FEATURES; i++) {
        scanf("%f", &input[i]);
    }
    for (int i = 0; i < CLASSES; i++) {
        output[i] = biases[i];
        for (int j = 0; j < FEATURES; j++) {
            output[i] += weights[j][i] * input[j];
        }
        output[i] = 1 / (1 + exp(-output[i]));
    }

    // print outputs
    printf("Output values:\n");
    for (int i = 0; i < CLASSES; i++) {
        printf("%.3f ", output[i]);
    }

    return 0;
}