//FormAI DATASET v1.0 Category: Computer Biology ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sigmoid(double x) {
    // Sigmoid activation function
    return 1.0 / (1.0 + exp(-x));
}

int main() {
    // Generate random input
    double input[4] = {rand(), rand(), rand(), rand()};

    // Initialize weights randomly
    double weights[4] = {rand(), rand(), rand(), rand()};

    // Initialize bias randomly
    double bias = rand();

    // Compute weighted sum of input
    double weighted_sum = 0.0;
    for (int i = 0; i < 4; i++) {
        weighted_sum += input[i] * weights[i];
    }

    // Add bias to weighted sum
    weighted_sum += bias;

    // Apply activation function
    double output = sigmoid(weighted_sum);

    // Print the result
    printf("The output of the neural network is: %f\n", output);

    return 0;
}