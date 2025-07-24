//FormAI DATASET v1.0 Category: Spam Detection System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SPAM_THRESHOLD 0.5

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

void train(double** inputs, double* outputs, int num_samples, int num_features, double* weights, int num_epochs, double learning_rate) {
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        double loss = 0;
        for (int i = 0; i < num_samples; i++) {
            // Forward propagation
            double z = 0;
            for (int j = 0; j < num_features; j++) {
                z += inputs[i][j] * weights[j];
            }
            double prediction = sigmoid(z);

            // Backward propagation
            double error = prediction - outputs[i];
            loss += pow(error, 2);

            for (int j = 0; j < num_features; j++) {
                weights[j] -= learning_rate * error * inputs[i][j];
            }
        }
        printf("Epoch %d loss: %f\n", epoch, loss);
    }
}

int main() {
    // The inputs will be the counts of certain words in the email
    double inputs[][3] = {
        {10, 3, 0},
        {0, 5, 3},
        {5, 2, 1},
        {1, 3, 1},
        {1, 0, 0},
        {0, 2, 1},
        {0, 0, 4},
        {0, 2, 3},
        {3, 0, 1},
        {0, 0, 1}
    };

    // The outputs will be 1 for spam and 0 for ham
    double outputs[] = {1, 1, 1, 0, 0, 0, 1, 1, 0, 0};

    int num_samples = sizeof(outputs) / sizeof(double);
    int num_features = sizeof(inputs[0]) / sizeof(double);

    double weights[num_features];
    for (int i = 0; i < num_features; i++) {
        weights[i] = 0;
    }

    // Train the model
    train(inputs, outputs, num_samples, num_features, weights, 1000, 0.1);

    // Test the model with some new input
    double new_input[] = {4, 1, 0};
    double z = 0;
    for (int i = 0; i < num_features; i++) {
        z += new_input[i] * weights[i];
    }
    double prediction = sigmoid(z);
    if (prediction >= SPAM_THRESHOLD) {
        printf("This email is classified as spam.\n");
    } else {
        printf("This email is classified as ham.\n");
    }

    return 0;
}