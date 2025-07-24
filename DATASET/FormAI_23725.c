//FormAI DATASET v1.0 Category: Image Classification system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_LAYER_SIZE 256
#define OUTPUT_SIZE 10

// Definition of the neural network structure
typedef struct {
    float input_layer[INPUT_SIZE];
    float hidden_layer[HIDDEN_LAYER_SIZE];
    float output_layer[OUTPUT_SIZE];
    float input_to_hidden_weights[INPUT_SIZE][HIDDEN_LAYER_SIZE];
    float hidden_to_output_weights[HIDDEN_LAYER_SIZE][OUTPUT_SIZE];
} NeuralNetwork;

// Function to initialize the neural network
void initialize_network(NeuralNetwork *network) {
    // Setting the weights to random values between -0.5 and 0.5
    int i, j;

    for (i = 0; i < INPUT_SIZE; i++) {
        for (j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            network->input_to_hidden_weights[i][j] = ((float)rand()/(float)RAND_MAX) - 0.5;
        }
    }

    for (i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for (j = 0; j < OUTPUT_SIZE; j++) {
            network->hidden_to_output_weights[i][j] = ((float)rand()/(float)RAND_MAX) - 0.5;
        }
    }
}

// Sigmoid activation function
float sigmoid(float x) {
    return 1.0/(1.0 + exp(-x));
}

// Function to make a prediction on a given input
void predict(NeuralNetwork *network, float *input, float *output) {
    // Forward propagation through the network
    int i, j;

    for (i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        float hidden_value = 0.0;

        for (j = 0; j < INPUT_SIZE; j++) {
            hidden_value += input[j] * network->input_to_hidden_weights[j][i];
        }

        hidden_value = sigmoid(hidden_value);
        network->hidden_layer[i] = hidden_value;
    }

    for (i = 0; i < OUTPUT_SIZE; i++) {
        float output_value = 0.0;

        for (j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            output_value += network->hidden_layer[j] * network->hidden_to_output_weights[j][i];
        }

        output_value = sigmoid(output_value);
        output[i] = output_value;
    }
}

int main() {
    // Creating the neural network object and initializing it
    NeuralNetwork network;
    initialize_network(&network);

    // Reading in the image data from file and storing in the input array
    float input[INPUT_SIZE];

    FILE *input_file = fopen("input.txt", "r");
    int i;

    for (i = 0; i < INPUT_SIZE; i++) {
        fscanf(input_file, "%f", &input[i]);
    }

    fclose(input_file);

    // Making the prediction for the image using the neural network
    float output[OUTPUT_SIZE];
    predict(&network, input, output);

    // Printing out the prediction probabilities for each class
    printf("Prediction probabilities:\n");
    for (i = 0; i < OUTPUT_SIZE; i++) {
        printf("%d: %f\n", i, output[i]);
    }

    return 0;
}