//FormAI DATASET v1.0 Category: Image Classification system ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_INPUTS 784   // 28x28 image
#define NUM_HIDDEN 100   // number of hidden neurons
#define NUM_OUTPUTS 3    // number of output classes
#define LEARNING_RATE 0.1

// Define the structure of the neural network
typedef struct {
    double inputs[NUM_INPUTS];
    double hidden[NUM_HIDDEN];
    double outputs[NUM_OUTPUTS];

    double weights_ih[NUM_INPUTS][NUM_HIDDEN];
    double weights_ho[NUM_HIDDEN][NUM_OUTPUTS];

    double bias_h[NUM_HIDDEN];
    double bias_o[NUM_OUTPUTS];
} neural_network;

// Initialize the neural network with random weights and biases
void init_neural_network(neural_network *nn) {
    int i, j;

    // Set random weights between input layer and hidden layer
    for (i = 0; i < NUM_INPUTS; i++) {
        for (j = 0; j < NUM_HIDDEN; j++) {
            nn->weights_ih[i][j] = ((double) rand() / (double) RAND_MAX) - 0.5;
        }
    }

    // Set random weights between hidden layer and output layer
    for (i = 0; i < NUM_HIDDEN; i++) {
        for (j = 0; j < NUM_OUTPUTS; j++) {
            nn->weights_ho[i][j] = ((double) rand() / (double) RAND_MAX) - 0.5;
        }
    }

    // Set random biases for hidden and output layers
    for (i = 0; i < NUM_HIDDEN; i++) {
        nn->bias_h[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
    }

    for (i = 0; i < NUM_OUTPUTS; i++) {
        nn->bias_o[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
    }
}

// Activation function (sigmoid)
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Feedforward function
void feedforward(neural_network *nn) {
    int i, j;

    // Calculate hidden layer values
    for (i = 0; i < NUM_HIDDEN; i++) {
        double sum = 0.0;

        for (j = 0; j < NUM_INPUTS; j++) {
            sum += nn->inputs[j] * nn->weights_ih[j][i];
        }

        nn->hidden[i] = sigmoid(sum + nn->bias_h[i]);
    }

    // Calculate output layer values
    for (i = 0; i < NUM_OUTPUTS; i++) {
        double sum = 0.0;

        for (j = 0; j < NUM_HIDDEN; j++) {
            sum += nn->hidden[j] * nn->weights_ho[j][i];
        }

        nn->outputs[i] = sigmoid(sum + nn->bias_o[i]);
    }
}

// Backpropagation function
void backpropagation(neural_network *nn, int target) {
    int i, j;

    // Calculate output layer errors
    double output_errors[NUM_OUTPUTS];
    for (i = 0; i < NUM_OUTPUTS; i++) {
        double error = (i == target ? 1.0 : 0.0) - nn->outputs[i];
        output_errors[i] = nn->outputs[i] * (1 - nn->outputs[i]) * error;
    }

    // Calculate hidden layer errors
    double hidden_errors[NUM_HIDDEN];
    for (i = 0; i < NUM_HIDDEN; i++) {
        double error = 0.0;

        for (j = 0; j < NUM_OUTPUTS; j++) {
            error += output_errors[j] * nn->weights_ho[i][j];
        }

        hidden_errors[i] = nn->hidden[i] * (1 - nn->hidden[i]) * error;
    }

    // Update weights and biases between hidden and output layers
    for (i = 0; i < NUM_HIDDEN; i++) {
        for (j = 0; j < NUM_OUTPUTS; j++) {
            nn->weights_ho[i][j] += LEARNING_RATE * nn->hidden[i] * output_errors[j];
        }
    }

    for (i = 0; i < NUM_OUTPUTS; i++) {
        nn->bias_o[i] += LEARNING_RATE * output_errors[i];
    }

    // Update weights and biases between input and hidden layers
    for (i = 0; i < NUM_INPUTS; i++) {
        for (j = 0; j < NUM_HIDDEN; j++) {
            nn->weights_ih[i][j] += LEARNING_RATE * nn->inputs[i] * hidden_errors[j];
        }
    }

    for (i = 0; i < NUM_HIDDEN; i++) {
        nn->bias_h[i] += LEARNING_RATE * hidden_errors[i];
    }
}

// Main function
int main() {
    neural_network nn;
    init_neural_network(&nn);

    printf("Training...\n\n");

    // Train the neural network on a dataset of fruit images
    FILE *fp = fopen("fruits.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file\n");
        return 1;
    }

    int i, j, target;
    double pixel_value;

    for (i = 0; i < 10000; i++) {
        // Read in input image
        for (j = 0; j < NUM_INPUTS; j++) {
            fscanf(fp, "%lf", &pixel_value);
            nn.inputs[j] = pixel_value / 255.0;   // scale pixel values between 0 and 1
        }

        // Read in target class
        fscanf(fp, "%d", &target);

        // Feedforward and backpropagate
        feedforward(&nn);
        backpropagation(&nn, target);

        // Print out progress every 1000 iterations
        if (i % 1000 == 0) {
            printf("Iteration %d: ", i);
            for (j = 0; j < NUM_OUTPUTS; j++) {
                printf("%.2f ", nn.outputs[j]);
            }
            printf("\n");
        }
    }

    fclose(fp);

    printf("\nTesting...\n\n");

    // Test the neural network on some new images
    fp = fopen("test_fruits.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file\n");
        return 1;
    }

    double accuracy = 0.0;
    int num_tests = 0;

    while (!feof(fp)) {
        int correct_class;
        double max_output = 0.0;

        // Read in input image
        for (i = 0; i < NUM_INPUTS; i++) {
            fscanf(fp, "%lf", &pixel_value);
            nn.inputs[i] = pixel_value / 255.0;   // scale pixel values between 0 and 1
        }

        // Read in correct class and feedforward
        fscanf(fp, "%d", &correct_class);
        feedforward(&nn);

        // Determine predicted class
        int predicted_class = -1;
        for (i = 0; i < NUM_OUTPUTS; i++) {
            if (nn.outputs[i] > max_output) {
                max_output = nn.outputs[i];
                predicted_class = i;
            }
        }

        // Print out results
        if (predicted_class == correct_class) {
            accuracy += 1.0;
            printf("Correctly classified as class %d!\n", predicted_class);
        } else {
            printf("Misclassified as class %d! (should be %d)\n", predicted_class, correct_class);
        }

        num_tests++;
    }

    fclose(fp);

    printf("\nAccuracy: %.2f%%\n", (accuracy / num_tests) * 100.0);

    return 0;
}