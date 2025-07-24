//FormAI DATASET v1.0 Category: Image Classification system ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INPUT_SIZE 784
#define HIDDEN_SIZE 256
#define OUTPUT_SIZE 10

#define TRAINING_SIZE 60000
#define TESTING_SIZE 10000

#define LEARNING_RATE 0.1

/* Define the neurons and biases */
double input[INPUT_SIZE];
double hidden[HIDDEN_SIZE];
double output[OUTPUT_SIZE];

double hidden_bias[HIDDEN_SIZE];
double output_bias[OUTPUT_SIZE];

/* Define the weights */
double input_hidden_weights[INPUT_SIZE][HIDDEN_SIZE];
double hidden_output_weights[HIDDEN_SIZE][OUTPUT_SIZE];

/* Function to initialize the weights and biases */
void initialize_weights_and_biases() {
    int i, j;

    /* Initialize the input to hidden weights */
    for (i = 0; i < INPUT_SIZE; i++) {
        for (j = 0; j < HIDDEN_SIZE; j++) {
            input_hidden_weights[i][j] = (double)rand() / (double)RAND_MAX - 0.5;
        }
    }

    /* Initialize the hidden to output weights */
    for (i = 0; i < HIDDEN_SIZE; i++) {
        for (j = 0; j < OUTPUT_SIZE; j++) {
            hidden_output_weights[i][j] = (double)rand() / (double)RAND_MAX - 0.5;
        }
    }

    /* Initialize the hidden bias */
    for (i = 0; i < HIDDEN_SIZE; i++) {
        hidden_bias[i] = (double)rand() / (double)RAND_MAX - 0.5;
    }

    /* Initialize the output bias */
    for (i = 0; i < OUTPUT_SIZE; i++) {
        output_bias[i] = (double)rand() / (double)RAND_MAX - 0.5;
    }
}

/* Function to propagate the inputs forward through the network */
void forward_propagation(double* input) {
    int i, j;

    /* Propagate inputs to hidden layer */
    for (i = 0; i < HIDDEN_SIZE; i++) {
        hidden[i] = 0;
        for (j = 0; j < INPUT_SIZE; j++) {
            hidden[i] += input[j] * input_hidden_weights[j][i];
        }
        hidden[i] += hidden_bias[i];
        hidden[i] = fmax(0, hidden[i]);
    }

    /* Propagate hidden layer to output layer */
    for (i = 0; i < OUTPUT_SIZE; i++) {
        output[i] = 0;
        for (j = 0; j < HIDDEN_SIZE; j++) {
            output[i] += hidden[j] * hidden_output_weights[j][i];
        }
        output[i] += output_bias[i];
    }
}

/* Function to train the network */
void train_network(double* input, double* target_output) {
    int i, j;

    /* Compute the output of the network */
    forward_propagation(input);

    /* Compute the error in the output layer */
    double output_error[OUTPUT_SIZE];
    for (i = 0; i < OUTPUT_SIZE; i++) {
        output_error[i] = target_output[i] - output[i];
    }

    /* Back-propagate the error */
    double hidden_error[HIDDEN_SIZE];
    double hidden_delta[HIDDEN_SIZE];
    double output_delta[OUTPUT_SIZE];

    for (i = 0; i < HIDDEN_SIZE; i++) {
        hidden_error[i] = 0;
        for (j = 0; j < OUTPUT_SIZE; j++) {
            hidden_error[i] += hidden_output_weights[i][j] * output_error[j];
        }
        hidden_delta[i] = hidden_error[i] * (hidden[i] > 0 ? 1 : 0);
    }

    /* Update the weights and biases */
    for (i = 0; i < HIDDEN_SIZE; i++) {
        for (j = 0; j < OUTPUT_SIZE; j++) {
            hidden_output_weights[i][j] += LEARNING_RATE * output_error[j] * hidden[i];
        }
    }
    for (i = 0; i < INPUT_SIZE; i++) {
        for (j = 0; j < HIDDEN_SIZE; j++) {
            input_hidden_weights[i][j] += LEARNING_RATE * hidden_delta[j] * input[i];
        }
    }
    for (i = 0; i < OUTPUT_SIZE; i++) {
        output_bias[i] += LEARNING_RATE * output_error[i];
    }
    for (i = 0; i < HIDDEN_SIZE; i++) {
        hidden_bias[i] += LEARNING_RATE * hidden_delta[i];
    }
}

/* Function to test the network */
void test_network() {
    int i, j, correct = 0;

    /* Load the test data */
    FILE* file = fopen("test_data.txt", "r");
    double testing_inputs[TESTING_SIZE][INPUT_SIZE];
    double testing_outputs[TESTING_SIZE][OUTPUT_SIZE];
    for (i = 0; i < TESTING_SIZE; i++) {
        for (j = 0; j < INPUT_SIZE; j++) {
            fscanf(file, "%lf", &testing_inputs[i][j]);
        }
        for (j = 0; j < OUTPUT_SIZE; j++) {
            fscanf(file, "%lf", &testing_outputs[i][j]);
        }
    }
    fclose(file);

    /* Test the network */
    for (i = 0; i < TESTING_SIZE; i++) {
        forward_propagation(testing_inputs[i]);

        double max_val = 0, max_idx = 0;
        for (j = 0; j < OUTPUT_SIZE; j++) {
            if (output[j] > max_val) {
                max_val = output[j];
                max_idx = j;
            }
        }

        double actual_output[OUTPUT_SIZE];
        memset(actual_output, 0, sizeof(actual_output));
        actual_output[(int)max_idx] = 1;

        if (memcmp(actual_output, testing_outputs[i], sizeof(actual_output)) == 0) {
            correct++;
        }
    }

    printf("Accuracy: %lf\n", (double)correct / TESTING_SIZE);
}

/* Main function */
int main() {
    int i, j;

    initialize_weights_and_biases();

    /* Load the training data */
    FILE* file = fopen("train_data.txt", "r");
    double training_inputs[TRAINING_SIZE][INPUT_SIZE];
    double training_outputs[TRAINING_SIZE][OUTPUT_SIZE];
    for (i = 0; i < TRAINING_SIZE; i++) {
        for (j = 0; j < INPUT_SIZE; j++) {
            fscanf(file, "%lf", &training_inputs[i][j]);
        }
        for (j = 0; j < OUTPUT_SIZE; j++) {
            fscanf(file, "%lf", &training_outputs[i][j]);
        }
    }
    fclose(file);

    /* Train the network */
    for (int epoch = 1; epoch <= 30; epoch++) {
        printf("Epoch %d\n", epoch);
        for (i = 0; i < TRAINING_SIZE; i++) {
            train_network(training_inputs[i], training_outputs[i]);
        }
        test_network();
        printf("\n");
    }

    return 0;
}