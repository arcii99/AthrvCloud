//FormAI DATASET v1.0 Category: Image Classification system ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 784 // Input image size (28x28 pixels)
#define HIDDEN_NEURONS 128 // Number of neurons in the hidden layer
#define OUTPUT_CLASSES 10 // Number of output classes

struct NeuralNetwork {
    double w1[INPUT_SIZE][HIDDEN_NEURONS]; // Weights for input -> hidden layer
    double w2[HIDDEN_NEURONS][OUTPUT_CLASSES]; // Weights for hidden -> output layer
    double b1[HIDDEN_NEURONS]; // Bias for hidden layer
    double b2[OUTPUT_CLASSES]; // Bias for output layer
};

// Random initialization of network weights and biases
void initialize_network(struct NeuralNetwork* nn) {
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_NEURONS; j++) {
            nn->w1[i][j] = (double)rand() / RAND_MAX - 0.5;
        }
    }

    for (int i = 0; i < HIDDEN_NEURONS; i++) {
        for (int j = 0; j < OUTPUT_CLASSES; j++) {
            nn->w2[i][j] = (double)rand() / RAND_MAX - 0.5;
        }
    }

    for (int i = 0; i < HIDDEN_NEURONS; i++) {
        nn->b1[i] = (double)rand() / RAND_MAX - 0.5;
    }

    for (int i = 0; i < OUTPUT_CLASSES; i++) {
        nn->b2[i] = (double)rand() / RAND_MAX - 0.5;
    }
}

// Sigmoid activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Forward propagation through the network
void forward_propagation(struct NeuralNetwork* nn, double input[INPUT_SIZE], double output[OUTPUT_CLASSES]) {
    double hidden_layer[HIDDEN_NEURONS];
    memset(hidden_layer, 0, sizeof(hidden_layer));

    // Calculate hidden layer activation
    for (int i = 0; i < HIDDEN_NEURONS; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden_layer[i] += nn->w1[j][i] * input[j];
        }
        hidden_layer[i] += nn->b1[i];
        hidden_layer[i] = sigmoid(hidden_layer[i]);
    }

    // Calculate output layer activation
    for (int i = 0; i < OUTPUT_CLASSES; i++) {
        for (int j = 0; j < HIDDEN_NEURONS; j++) {
            output[i] += nn->w2[j][i] * hidden_layer[j];
        }
        output[i] += nn->b2[i];
    }
}

int main() {
    // Load image data (for example purposes, we will generate random image data)
    double input[INPUT_SIZE];
    for (int i = 0; i < INPUT_SIZE; i++) {
        input[i] = (double)rand() / RAND_MAX;
    }

    // Initialize network weights and biases
    struct NeuralNetwork nn;
    initialize_network(&nn);

    // Forward propagation through network
    double output[OUTPUT_CLASSES];
    memset(output, 0, sizeof(output));
    forward_propagation(&nn, input, output);

    // Print output probabilities for each class
    for (int i = 0; i < OUTPUT_CLASSES; i++) {
        printf("Probability for class %d: %f\n", i, output[i]);
    }

    return 0;
}