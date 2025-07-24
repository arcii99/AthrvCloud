//FormAI DATASET v1.0 Category: Image Classification system ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_LAYER_SIZE 784
#define OUTPUT_LAYER_SIZE 10
#define HIDDEN_LAYER_SIZE 100

double sigmoid(double z) {
    return 1 / (1 + exp(-z));
}

int main() {
    double input[INPUT_LAYER_SIZE];
    double hidden[HIDDEN_LAYER_SIZE];
    double output[OUTPUT_LAYER_SIZE];
    double weights1[INPUT_LAYER_SIZE][HIDDEN_LAYER_SIZE];
    double weights2[HIDDEN_LAYER_SIZE][OUTPUT_LAYER_SIZE];

    // Initialize weights randomly
    for (int i = 0; i < INPUT_LAYER_SIZE; i++) {
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            weights1[i][j] = (double)rand() / RAND_MAX - 0.5;
        }
    }

    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for (int j = 0; j < OUTPUT_LAYER_SIZE; j++) {
            weights2[i][j] = (double)rand() / RAND_MAX - 0.5;
        }
    }

    // Read input data from file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < INPUT_LAYER_SIZE; i++) {
        fscanf(input_file, "%lf", &input[i]);
    }

    fclose(input_file);

    // Forward propagation
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        double z = 0;
        for (int j = 0; j < INPUT_LAYER_SIZE; j++) {
            z += input[j] * weights1[j][i];
        }
        hidden[i] = sigmoid(z);
    }

    for (int i = 0; i < OUTPUT_LAYER_SIZE; i++) {
        double z = 0;
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            z += hidden[j] * weights2[j][i];
        }
        output[i] = sigmoid(z);
    }

    // Print output
    for (int i = 0; i < OUTPUT_LAYER_SIZE; i++) {
        printf("%lf ", output[i]);
    }

    printf("\n");

    return 0;
}