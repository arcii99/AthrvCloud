//FormAI DATASET v1.0 Category: Image Classification system ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define Neural Network architecture
#define INPUT_NODES 784 // 28 x 28 pixel images
#define HIDDEN_NODES 64 // Arbitrary number of hidden nodes
#define OUTPUT_NODES 10 // 10 possible classifications (0 - 9)

// Define activation function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Define derivative of activation function (for backpropagation)
double sigmoidDerivative(double x) {
    return x * (1 - x);
}

int main() {

    // Initialize weights with random values
    double input_hidden_weights[INPUT_NODES][HIDDEN_NODES];
    double hidden_output_weights[HIDDEN_NODES][OUTPUT_NODES];
    double hidden_biases[HIDDEN_NODES];
    double output_biases[OUTPUT_NODES];
    for (int i = 0; i < INPUT_NODES; i++) {
        for (int j = 0; j < HIDDEN_NODES; j++) {
            input_hidden_weights[i][j] = (double) rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < HIDDEN_NODES; i++) {
        for (int j = 0; j < OUTPUT_NODES; j++) {
            hidden_output_weights[i][j] = (double) rand() / RAND_MAX;
        }
        hidden_biases[i] = (double) rand() / RAND_MAX;
    }
    for (int i = 0; i < OUTPUT_NODES; i++) {
        output_biases[i] = (double) rand() / RAND_MAX;
    }

    // Load test image
    int test_image[28][28];
    FILE *image_file = fopen("test_image.txt", "r");
    if (image_file == NULL) {
        printf("Error opening image file.");
        return 1;
    }
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            fscanf(image_file, "%1d", &test_image[i][j]);
        }
    }
    fclose(image_file);

    // Reshape test image as input vector
    double input_vector[INPUT_NODES];
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            input_vector[i * 28 + j] = test_image[i][j];
        }
    }

    // Forward pass
    double hidden_layer[HIDDEN_NODES];
    double output_layer[OUTPUT_NODES];
    for (int i = 0; i < HIDDEN_NODES; i++) {
        double sum = 0;
        for (int j = 0; j < INPUT_NODES; j++) {
            sum += input_vector[j] * input_hidden_weights[j][i];
        }
        hidden_layer[i] = sigmoid(sum + hidden_biases[i]);
    }
    for (int i = 0; i < OUTPUT_NODES; i++) {
        double sum = 0;
        for (int j = 0; j < HIDDEN_NODES; j++) {
            sum += hidden_layer[j] * hidden_output_weights[j][i];
        }
        output_layer[i] = sigmoid(sum + output_biases[i]);
    }

    // Print output (predicted classification)
    int max_index = 0;
    for (int i = 0; i < OUTPUT_NODES; i++) {
        if (output_layer[i] > output_layer[max_index]) {
            max_index = i;
        }
    }
    printf("Predicted classification: %d\n", max_index);

    return 0;
}