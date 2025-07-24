//FormAI DATASET v1.0 Category: Image Classification system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784       // MNIST image size 28x28 = 784
#define HIDDEN_SIZE 16       // Number of hidden units
#define OUTPUT_SIZE 10       // Number of output units

int main() {
    printf("Welcome to the cheerful Image Classification system example program!\n\n");

    // Input layer
    float input[INPUT_SIZE];

    // Hidden layer
    float hidden[HIDDEN_SIZE];
    float hidden_weights[INPUT_SIZE][HIDDEN_SIZE];   // Input to hidden weights
    float hidden_bias[HIDDEN_SIZE];                  // Hidden bias

    // Output layer
    float output[OUTPUT_SIZE];
    float output_weights[HIDDEN_SIZE][OUTPUT_SIZE];  // Hidden to output weights
    float output_bias[OUTPUT_SIZE];                  // Output bias

    // Initialize weights and biases to random values
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            hidden_weights[i][j] = (float)(rand()) / RAND_MAX - 0.5;   // Random weight between -0.5 and 0.5
        }
    }
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            output_weights[i][j] = (float)(rand()) / RAND_MAX - 0.5;   // Random weight between -0.5 and 0.5
        }
    }
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        hidden_bias[i] = (float)(rand()) / RAND_MAX - 0.5;   // Random bias between -0.5 and 0.5
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_bias[i] = (float)(rand()) / RAND_MAX - 0.5;   // Random bias between -0.5 and 0.5
    }

    // Forward pass through the network
    // Assume input[] and output[] have been initialized
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        hidden[i] = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden[i] += input[j] * hidden_weights[j][i];
        }
        hidden[i] = tanh(hidden[i] + hidden_bias[i]);   // Apply activation function
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output[i] = 0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            output[i] += hidden[j] * output_weights[j][i];
        }
        output[i] = exp(output[i] + output_bias[i]);    // Apply activation function
    }
    float sum = 0;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        sum += output[i];
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output[i] /= sum;   // Normalize outputs to sum to 1
    }

    // Print output probabilities
    printf("Class probabilities:\n");
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        printf("%d: %.3f%%\n", i, output[i] * 100);
    }

    printf("\nThank you for trying out my cheerful Image Classification system example program!\n");
    return 0;
}