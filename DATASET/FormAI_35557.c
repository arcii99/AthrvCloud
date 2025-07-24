//FormAI DATASET v1.0 Category: Image Classification system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 256
#define HIDDEN_LAYER_SIZE 64
#define OUTPUT_SIZE 10
#define LEARNING_RATE 0.1
#define TRAINING_SIZE 60000
#define TEST_SIZE 10000

// This function implements the sigmoid activation function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// This function returns a random number between -1 and 1
double rand_weight() {
    return ((double)rand() / RAND_MAX) * 2 - 1;
}

int main() {
    // Define the layers of the neural network
    double input[INPUT_SIZE];
    double hidden[HIDDEN_LAYER_SIZE];
    double output[OUTPUT_SIZE];

    // Initialize the weights between input and hidden layers
    double wih[INPUT_SIZE][HIDDEN_LAYER_SIZE];
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            wih[i][j] = rand_weight();
        }
    }

    // Initialize the weights between hidden and output layers
    double who[HIDDEN_LAYER_SIZE][OUTPUT_SIZE];
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            who[i][j] = rand_weight();
        }
    }

    // Load the MNIST data set
    FILE *fp = fopen("train-images.idx3-ubyte", "rb");
    if (fp == NULL) {
        printf("Error: could not open training data file.\n");
        return 1;
    }

    // Get past the header information in the data file
    fseek(fp, 16, SEEK_SET);

    // Train the neural network
    for (int i = 0; i < TRAINING_SIZE; i++) {
        // Load the input data
        unsigned char inputs[INPUT_SIZE];
        fread(inputs, sizeof(inputs[0]), INPUT_SIZE, fp);
        for (int j = 0; j < INPUT_SIZE; j++) {
            input[j] = (double)inputs[j] / 255.0;
        }

        // Load the expected output data
        unsigned char label;
        fread(&label, sizeof(label), 1, fp);
        double expected_output[OUTPUT_SIZE];
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            if (j == label) {
                expected_output[j] = 1.0;
            } else {
                expected_output[j] = 0.0;
            }
        }

        // Forward propagation
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            double sum = 0.0;
            for (int k = 0; k < INPUT_SIZE; k++) {
                sum += input[k] * wih[k][j];
            }
            hidden[j] = sigmoid(sum);
        }

        for (int j = 0; j < OUTPUT_SIZE; j++) {
            double sum = 0.0;
            for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                sum += hidden[k] * who[k][j];
            }
            output[j] = sigmoid(sum);
        }

        // Back propagation
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            double error = expected_output[j] - output[j];
            double derivative = output[j] * (1 - output[j]);
            for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                double delta = error * derivative * hidden[k];
                who[k][j] += LEARNING_RATE * delta;
            }
        }

        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            double error = 0.0;
            for (int k = 0; k < OUTPUT_SIZE; k++) {
                error += (expected_output[k] - output[k]) * output[k] * (1 - output[k]) * who[j][k];
            }
            double derivative = hidden[j] * (1 - hidden[j]);
            for (int k = 0; k < INPUT_SIZE; k++) {
                double delta = error * derivative * input[k];
                wih[k][j] += LEARNING_RATE * delta;
            }
        }
    }
    fclose(fp);

    // Test the neural network
    fp = fopen("t10k-images.idx3-ubyte", "rb");
    if (fp == NULL) {
        printf("Error: could not open test data file.\n");
        return 1;
    }

    // Get past the header information in the data file
    fseek(fp, 16, SEEK_SET);

    int correct = 0;
    for (int i = 0; i < TEST_SIZE; i++) {
        // Load the input data
        unsigned char inputs[INPUT_SIZE];
        fread(inputs, sizeof(inputs[0]), INPUT_SIZE, fp);
        for (int j = 0; j < INPUT_SIZE; j++) {
            input[j] = (double)inputs[j] / 255.0;
        }

        // Load the expected output data
        unsigned char label;
        fread(&label, sizeof(label), 1, fp);
        double expected_output[OUTPUT_SIZE];
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            if (j == label) {
                expected_output[j] = 1.0;
            } else {
                expected_output[j] = 0.0;
            }
        }

        // Forward propagation
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            double sum = 0.0;
            for (int k = 0; k < INPUT_SIZE; k++) {
                sum += input[k] * wih[k][j];
            }
            hidden[j] = sigmoid(sum);
        }

        for (int j = 0; j < OUTPUT_SIZE; j++) {
            double sum = 0.0;
            for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                sum += hidden[k] * who[k][j];
            }
            output[j] = sigmoid(sum);
        }

        // Check for correctness
        int max_index = 0;
        double max_output = 0.0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            if (output[j] > max_output) {
                max_index = j;
                max_output = output[j];
            }
        }
        if (max_index == label) {
            correct++;
        }
    }
    fclose(fp);

    printf("Accuracy: %f\n", (double)correct / TEST_SIZE);

    return 0;
}