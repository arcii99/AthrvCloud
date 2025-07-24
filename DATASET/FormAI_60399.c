//FormAI DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_SIZE 16
#define OUTPUT_SIZE 10
#define LEARNING_RATE 0.1

/**
 * A simple structure representing a neural network.
 * Consists of an input layer, a hidden layer, and an output layer.
 */
typedef struct {
    double input_layer[INPUT_SIZE];
    double hidden_layer[HIDDEN_SIZE];
    double output_layer[OUTPUT_SIZE];

    double input_hidden_weights[INPUT_SIZE][HIDDEN_SIZE];
    double hidden_output_weights[HIDDEN_SIZE][OUTPUT_SIZE];

    double hidden_layer_bias[HIDDEN_SIZE];
    double output_layer_bias[OUTPUT_SIZE];
} NeuralNetwork;

/**
 * A simple function to create and initialize a neural network.
 */
NeuralNetwork create_neural_network() {
    NeuralNetwork network;

    // Initialize weights and biases to random values
    for (int i = 0; i < INPUT_SIZE; i++)
        for (int j = 0; j < HIDDEN_SIZE; j++)
            network.input_hidden_weights[i][j] = ((double) rand() / (RAND_MAX)) - 0.5;

    for (int i = 0; i < HIDDEN_SIZE; i++)
        for (int j = 0; j < OUTPUT_SIZE; j++)
            network.hidden_output_weights[i][j] = ((double) rand() / (RAND_MAX)) - 0.5;

    for (int i = 0; i < HIDDEN_SIZE; i++)
        network.hidden_layer_bias[i] = ((double) rand() / (RAND_MAX)) - 0.5;

    for (int i = 0; i < OUTPUT_SIZE; i++)
        network.output_layer_bias[i] = ((double) rand() / (RAND_MAX)) - 0.5;

    return network;
}

/**
 * A simple function to compute the sigmoid function of an input.
 */
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

/**
 * A simple function to compute the derivative of the sigmoid function of an input.
 */
double sigmoid_prime(double x) {
    double sig = sigmoid(x);
    return sig * (1 - sig);
}

/**
 * A simple function to compute the feedforward output of a neural network.
 */
void feedforward(NeuralNetwork* network) {
    // Compute hidden layer output
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < INPUT_SIZE; j++)
            sum += network->input_layer[j] * network->input_hidden_weights[j][i];
        sum += network->hidden_layer_bias[i];
        network->hidden_layer[i] = sigmoid(sum);
    }

    // Compute output layer output
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < HIDDEN_SIZE; j++)
            sum += network->hidden_layer[j] * network->hidden_output_weights[j][i];
        sum += network->output_layer_bias[i];
        network->output_layer[i] = sigmoid(sum);
    }
}

/**
 * A simple function to compute the output error of a neural network.
 */
double output_error(NeuralNetwork* network, int expected_output) {
    double output = network->output_layer[expected_output];
    return sigmoid_prime(output) * (1 - output);
}

/**
 * A simple function to update the weights and biases of a neural network using backpropagation.
 */
void backpropagate(NeuralNetwork* network, int expected_output) {
    // Compute output error
    double error[OUTPUT_SIZE];
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        if (i == expected_output)
            error[i] = output_error(network, expected_output) * (1 - network->output_layer[i]);
        else
            error[i] = -network->output_layer[i] * network->output_layer[expected_output];
    }

    // Update output layer biases
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double delta = LEARNING_RATE * error[i];
        network->output_layer_bias[i] += delta;
    }

    // Update hidden output weights
    for (int i = 0; i < HIDDEN_SIZE; i++)
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            double delta = LEARNING_RATE * error[j] * network->hidden_layer[i];
            network->hidden_output_weights[i][j] += delta;
        }

    // Compute hidden layer error
    double hidden_error[HIDDEN_SIZE];
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < OUTPUT_SIZE; j++)
            sum += error[j] * network->hidden_output_weights[i][j];
        hidden_error[i] = sigmoid_prime(network->hidden_layer[i]) * sum;
    }

    // Update hidden layer biases
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double delta = LEARNING_RATE * hidden_error[i];
        network->hidden_layer_bias[i] += delta;
    }

    // Update input hidden weights
    for (int i = 0; i < INPUT_SIZE; i++)
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            double delta = LEARNING_RATE * hidden_error[j] * network->input_layer[i];
            network->input_hidden_weights[i][j] += delta;
        }
}

int main() {
    // Create neural network
    NeuralNetwork network = create_neural_network();

    // Train neural network on MNIST dataset
    // ... (omitted for brevity)

    // Use neural network to classify unseen image
    double unseen_image[INPUT_SIZE];
    // ... (omitted for brevity)

    for (int i = 0; i < INPUT_SIZE; i++)
        network.input_layer[i] = unseen_image[i];

    feedforward(&network);

    int predicted_class = -1;
    double max_output = -INFINITY;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        if (network.output_layer[i] > max_output) {
            max_output = network.output_layer[i];
            predicted_class = i;
        }
    }

    printf("Predicted class: %d\n", predicted_class);

    return 0;
}