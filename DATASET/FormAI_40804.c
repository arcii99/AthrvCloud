//FormAI DATASET v1.0 Category: Image Classification system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_SIZE 64
#define OUTPUT_SIZE 10

// Activation function.
double sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}

// Derivative of activation function.
double sigmoidDerivative(double x)
{
    return x * (1 - x);
}

int main()
{
    int i, j, k;

    // Initialize random weights.
    double weightsIH[INPUT_SIZE][HIDDEN_SIZE];
    double weightsHO[HIDDEN_SIZE][OUTPUT_SIZE];
    for (i = 0; i < INPUT_SIZE; i++) {
        for (j = 0; j < HIDDEN_SIZE; j++) {
            weightsIH[i][j] = (double) rand() / RAND_MAX;
        }
    }
    for (i = 0; i < HIDDEN_SIZE; i++) {
        for (j = 0; j < OUTPUT_SIZE; j++) {
            weightsHO[i][j] = (double) rand() / RAND_MAX;
        }
    }

    // Initialize input and output arrays.
    double input[INPUT_SIZE];
    double hidden[HIDDEN_SIZE];
    double output[OUTPUT_SIZE];

    // Load input data from file.
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    for (i = 0; i < INPUT_SIZE; i++) {
        fscanf(file, "%lf", &input[i]);
    }
    fclose(file);

    // Forward propagation.
    for (i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;
        for (j = 0; j < INPUT_SIZE; j++) {
            sum += input[j] * weightsIH[j][i];
        }
        hidden[i] = sigmoid(sum);
    }
    for (i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0;
        for (j = 0; j < HIDDEN_SIZE; j++) {
            sum += hidden[j] * weightsHO[j][i];
        }
        output[i] = sigmoid(sum);
    }

    // Print output.
    printf("Output:");
    for (i = 0; i < OUTPUT_SIZE; i++) {
        printf(" %lf", output[i]);
    }
    printf("\n");

    // Backward propagation.
    double target[OUTPUT_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    double error[OUTPUT_SIZE];
    for (i = 0; i < OUTPUT_SIZE; i++) {
        error[i] = target[i] - output[i];
    }
    double outputDerivatives[OUTPUT_SIZE];
    for (i = 0; i < OUTPUT_SIZE; i++) {
        outputDerivatives[i] = sigmoidDerivative(output[i]);
    }
    double deltasHO[HIDDEN_SIZE][OUTPUT_SIZE];
    for (i = 0; i < HIDDEN_SIZE; i++) {
        for (j = 0; j < OUTPUT_SIZE; j++) {
            deltasHO[i][j] = hidden[i] * error[j] * outputDerivatives[j];
        }
    }
    double hiddenDerivatives[HIDDEN_SIZE];
    for (i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;
        for (j = 0; j < OUTPUT_SIZE; j++) {
            sum += error[j] * outputDerivatives[j] * weightsHO[i][j];
        }
        hiddenDerivatives[i] = sigmoidDerivative(hidden[i]) * sum;
    }
    double deltasIH[INPUT_SIZE][HIDDEN_SIZE];
    for (i = 0; i < INPUT_SIZE; i++) {
        for (j = 0; j < HIDDEN_SIZE; j++) {
            deltasIH[i][j] = input[i] * hiddenDerivatives[j];
        }
    }

    // Update weights.
    double learningRate = 0.5;
    for (i = 0; i < INPUT_SIZE; i++) {
        for (j = 0; j < HIDDEN_SIZE; j++) {
            weightsIH[i][j] += learningRate * deltasIH[i][j];
        }
    }
    for (i = 0; i < HIDDEN_SIZE; i++) {
        for (j = 0; j < OUTPUT_SIZE; j++) {
            weightsHO[i][j] += learningRate * deltasHO[i][j];
        }
    }

    return 0;
}