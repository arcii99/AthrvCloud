//FormAI DATASET v1.0 Category: Image Classification system ; Style: Cryptic
// b1N@Ry Cl@Ss1f1c@t10N Pr0gr@m
// L0@D1NG...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Set the number of binary digits for classification
#define DIGITS 5

// Define the input data structure
typedef struct {
    char* label;
    int binary[DIGITS];
} InputData;

// Define the neural network structure
typedef struct {
    float weights[DIGITS];
    float bias;
} NeuralNetwork;

// Initialize the neural network with random weights and bias
NeuralNetwork init_network() {
    NeuralNetwork network;
    for (int i = 0; i < DIGITS; i++) {
        network.weights[i] = (float)(rand() % 100) / 100.0f;
    }
    network.bias = (float)(rand() % 100) / 100.0f;
    return network;
}

// Calculate the dot product of the input and weights
float dot_product(InputData input, NeuralNetwork network) {
    float result = 0.0f;
    for (int i = 0; i < DIGITS; i++) {
        result += input.binary[i] * network.weights[i];
    }
    return result + network.bias;
}

// The sigmoid activation function
float sigmoid(float x) {
    return 1.0f / (1.0f + exp(-x));
}

// Classify the input data and return the predicted label
char* classify(InputData input, NeuralNetwork network) {
    float output = sigmoid(dot_product(input, network));
    if (output > 0.5f) {
        return "+";
    } else {
        return "-";
    }
}

// Train the neural network with a given set of input data and labels
NeuralNetwork train(InputData* inputs, char** labels, int num_inputs, float learning_rate, int num_epochs) {
    NeuralNetwork network = init_network();
    for (int epoch = 1; epoch <= num_epochs; epoch++) {
        float error = 0.0f;
        for (int i = 0; i < num_inputs; i++) {
            InputData input = inputs[i];
            char* label = labels[i];
            float output = sigmoid(dot_product(input, network));
            float target = strcmp(label, "+") == 0 ? 1.0f : 0.0f;
            float delta = (target - output) * output * (1.0f - output);
            for (int j = 0; j < DIGITS; j++) {
                network.weights[j] += learning_rate * delta * input.binary[j];
            }
            network.bias += learning_rate * delta;
            error += (target - output) * (target - output);
        }
        printf("Epoch %d: Error = %.4f\n", epoch, error);
    }
    return network;
}

// Run the program
int main() {
    srand(42);
    InputData inputs[] = {
        {"A", {1, 0, 1, 0, 1}},
        {"B", {1, 1, 0, 0, 1}},
        {"C", {0, 1, 1, 1, 0}},
        {"D", {0, 0, 0, 1, 0}},
        {"E", {1, 1, 1, 0, 1}}
    };
    char* labels[] = {"+", "+", "-", "-", "+"};
    int num_inputs = 5;
    float learning_rate = 0.1f;
    int num_epochs = 1000;
    NeuralNetwork network = train(inputs, labels, num_inputs, learning_rate, num_epochs);
    printf("Trained Weights:");
    for (int i = 0; i < DIGITS; i++) {
        printf(" %f", network.weights[i]);
    }
    printf("\nTrained Bias: %f\n", network.bias);
    printf("Testing...\n");
    for (int i = 0; i < num_inputs; i++) {
        InputData input = inputs[i];
        char* label = classify(input, network);
        printf("Input %s: Predicted %s, Actual %s\n", input.label, label, labels[i]);
    }
    return 0;
}